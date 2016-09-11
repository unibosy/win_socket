#include "serversocket.h"
#include "macros.h"
#include "helper.h"

#include <string>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

//create threads
std::thread recvthread;
std::thread sendthread;

ServerSocket::ServerSocket() : m_server_socket(0), m_client_socket(0)
{
}
ServerSocket::~ServerSocket()
{
  if (m_server_socket)
  {
    closesocket(m_server_socket);
    m_server_socket = 0;
  }
  if (m_client_socket)
  {
    closesocket(m_client_socket);
    m_client_socket = 0;
  }
  WSACleanup();
}
void ServerSocket::createSocket()
{
  std::lock_guard<std::mutex> lock(mtx);
  if (m_server_socket)
  {
    std::cout << "Already exist server socket!" << std::endl;
    return;
  }
  //initialize
  WORD socketVersion = MAKEWORD(2, 2);
  WSADATA wsaData;
  if (WSAStartup(socketVersion, &wsaData) != 0)
  {
    return;
  }
  //create socket
  m_server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (m_server_socket == INVALID_SOCKET)
  {
    std::cout << "create socket error !" << std::endl;
    closesocket(m_server_socket);
    WSACleanup();
    return;
  }

  sockaddr_in sin;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(SERVERPORT);
  sin.sin_addr.S_un.S_addr = INADDR_ANY;
  
  //bind
  if (bind(m_server_socket, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
  {
    closesocket(m_server_socket);
    WSACleanup();
    std::cout << "bind error !" << std::endl;
  }

  //listen
  if (listen(m_server_socket, 5) == SOCKET_ERROR)
  {
    std::cout << "listen error!" << std::endl;
    closesocket(m_server_socket);
    WSACleanup();
    return;
  }
}

void ServerSocket::init()
{
  createSocket();
  runRecvThread();
  runSendThread();
  recvthread.join();
  sendthread.join();
  std::cout << "init end" << std::endl;
}
void ServerSocket::runRecvThread()
{
  recvthread = std::thread(&ServerSocket::recvMessage, this);
  //recvthread.join();//wait this thread finished
}
void ServerSocket::runSendThread()
{
  sendthread = std::thread(&ServerSocket::sendMessage, this);
  //sendthread.join();//wait this thread finished
}
SOCKET ServerSocket::waitAcceptClient()
{
  SOCKET client_socket;
  sockaddr_in remoteAddr;
  int nAddrlen = sizeof(remoteAddr);
  std::cout << "waiting for client!" << std::endl;
  client_socket = ::accept(m_server_socket, (SOCKADDR *)&remoteAddr, &nAddrlen);
  if (client_socket == INVALID_SOCKET)
  {
    std::cout << "accept error!" << std::endl;
  }
  std::cout << "new client ip=" << inet_ntoa(remoteAddr.sin_addr) << std::endl;
  return client_socket;
}

//receive message
void ServerSocket::recvMessage()
{
  //TODO: How will do if there are multiple clients wait to connect ?
  std::cout << "recvMessage thread id="<<std::this_thread::get_id() << std::endl;
  //SOCKET client_socket = 0;
  int iResult = -1;
  do
  {
    //wait client to actively connect this server
    if(!m_client_socket)
      m_client_socket = waitAcceptClient();
    char* recvData = new char[MAXLEN];
    memset(recvData, 0, MAXLEN);
    //std::cout << "what???" << std::endl;
    iResult = ::recv(m_client_socket, recvData, MAXLEN, 0);
    if ( iResult > 0 )
    {
      std::cout << "receive message="<<recvData << std::endl;
      //recvData = nullptr;
      delete []recvData;
      recvData = nullptr;
    }
    else if( iResult == 0 )
    {
      std::cout << "recvMessage connection closed!" << std::endl;
      delete []recvData;
      recvData = nullptr;
      Helper::getInstance()->showLastErrMessage();
    }
    else
    {
      std::cout << "recv failed!" << std::endl;
      delete []recvData;
      recvData = nullptr;
      Helper::getInstance()->showLastErrMessage();
    }
    //sleep 10ms
    Sleep(10);
  } while (iResult > 0);
}

void ServerSocket::sendMessage()
{
  //system("cmd.exe /c dir c:\\");
  std::cout << "sendMessage thread id=" << std::this_thread::get_id() << std::endl;
  std::string send_message = "";
  int iResult = -1;
  while(true)
  {
    //no client, cannot send message
    if (m_client_socket)
    {
      getline(std::cin, send_message);
      if (send_message.length() <= 0)
      {
        std::cout << "Please input some words to send!" << std::endl;
          continue;
      }
      iResult = ::send(m_client_socket, send_message.c_str(), send_message.length(), 0);
      if (iResult > 0)
      {
        std::cout << "send_message is=" << send_message.c_str() << std::endl;
      }
      else if (iResult == 0)
      {
        Helper::getInstance()->showLastErrMessage();
        continue; //if send quickly, the socket maybe closed, so set continue!
      }
      else
      {
        std::cout << "send failed!" << std::endl;
        Helper::getInstance()->showLastErrMessage();
        break;
      }
    }
    //sleep 10ms
    Sleep(10);

  }
}