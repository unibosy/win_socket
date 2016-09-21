#include "serversocket.h"
#include "commondef.h"
#include "helper.h"

#include <string>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

//create threads
std::thread recvthread;
std::thread sendthread;

//create thread pool for client connect
std::thread thread_pool[CLIENTNUMBER];

static int client_number = 0;

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
int ServerSocket::createSocket()
{
  std::lock_guard<std::mutex> lock(mtx);
  if (m_server_socket)
  {
    std::cout << "Already exist server socket!" << std::endl;
    return -1;
  }
  //initialize
  WORD socketVersion = MAKEWORD(2, 2);
  WSADATA wsaData;
  if (WSAStartup(socketVersion, &wsaData) != 0)
  {
    return -1;
  }
  //create socket
  m_server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (m_server_socket == INVALID_SOCKET)
  {
    std::cout << "create socket error !" << std::endl;
    closesocket(m_server_socket);
    WSACleanup();
    return -1;
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
    return -1;
  }
  return 0;
}

int ServerSocket::init()
{
  return createSocket();
}
int ServerSocket::startRunning()
{
  //receive client connect, and will start threads to receive connected client messages
  //std::thread recv_client_thread = std::thread(&ServerSocket::recvClientConnect, this);
  //recv_client_thread.join();

  recvClientConnect();

  std::cout << "init end" << std::endl;
  return 0;
}

void ServerSocket::recvClientConnect()
{
  //create a thread to wait client connect, and start a thread for receiving message from client, and also start
  //a thread for sending message to a connected client.
  //std::thread wait_thread = std::thread(&ServerSocket::waitAcceptClient, this);
  //wait_thread.join();

  waitAcceptClient();

}

void ServerSocket::runRecvThread()
{
  //recvthread = std::thread(&ServerSocket::recvMessage, this);
  //recvthread.join();//wait this thread finished
}
void ServerSocket::runSendThread(/*void* p*/)
{
  SOCKET client_sock;
  sendthread = std::thread(&ServerSocket::sendMessage, this, m_client_socket/*, (SOCKET *)p*/);
  sendthread.join();//wait this thread finished
}
void ServerSocket::waitAcceptClient()
{
  while (client_number < CLIENTNUMBER)
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
    client_number++;

    m_client_socket = client_socket;
    std::string test = "test";
    thread_pool[client_number] = std::thread(&ServerSocket::recvMessage, this, client_socket);

    std::thread send_thread = std::thread(&ServerSocket::sendMessage, this, client_socket);
    
    thread_pool[client_number].detach();

    send_thread.detach();

    Sleep(10);
  }
  return;
}

//receive message
void ServerSocket::recvMessage(SOCKET client_sock)
{
  //TODO: How will do if there are multiple clients wait to connect ?
  std::cout << "recvMessage thread id="<<std::this_thread::get_id() << std::endl;
  //SOCKET client_socket = 0;

  int iResult = -1;
  do
  {
    char* recvData = new char[MAXLEN];
    memset(recvData, 0, MAXLEN);
    iResult = ::recv(client_sock, recvData, MAXLEN, 0);
    if ( iResult > 0 )
    {
      std::cout << "receive message="<<recvData << std::endl;
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
  } while (iResult > 0 && client_sock);
}

void ServerSocket::sendMessage(SOCKET sock)
{
  //system("cmd.exe /c dir c:\\");
  std::cout << "sendMessage thread id=" << std::this_thread::get_id() << std::endl;
  std::string send_message = "";
  int iResult = -1;
  while(true)
  {
    //no client, cannot send message
    if (sock)
    {
      getline(std::cin, send_message);
      if (send_message.length() <= 0)
      {
        std::cout << "Please input some words to send!" << std::endl;
        continue;
      }
      iResult = ::send(sock, send_message.c_str(), send_message.length(), 0);
      
      if (iResult > 0)
      {
        std::cout << "thread id=" << std::this_thread::get_id() << ",send message=" << send_message << std::endl;
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