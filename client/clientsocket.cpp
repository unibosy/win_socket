#include "clientsocket.h"
#include "macros.h"

#include <string>
#include <thread>
#include <mutex>
#include <iostream>

//create threads
std::thread recvthread;
std::thread sendthread;

std::mutex mtx1;


ClientSocket::ClientSocket() : m_socket(0)
{}
ClientSocket::~ClientSocket()
{}

void ClientSocket::init(const std::string& serverip)
{
  bool result =createSocket(serverip);
  if(result)
  {
    runRecvThread();
    runSendThread();
    recvthread.join();
    sendthread.join();
  }
  else
  {
    std::cout << "init failed!" << std::endl;
  }
  
}


bool ClientSocket::createSocket(const std::string& serverip)
{
  std::lock_guard<std::mutex> lock(mtx1);

  WORD sockVersion = MAKEWORD(2, 2);
  WSADATA data;
  if (WSAStartup(sockVersion, &data) != 0)
  {
    return false;
  }

  m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (m_socket == INVALID_SOCKET)
  {
    std::cout << "invalid socket !" << std::endl;
    return false;
  }

  sockaddr_in serAddr;
  serAddr.sin_family = AF_INET;
  serAddr.sin_port = htons(SERVERPORT);
  serAddr.sin_addr.S_un.S_addr = inet_addr(serverip.c_str());
  if (connect(m_socket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
  {
    std::cout<<"connect error !"<<std::endl;
    closesocket(m_socket);
    return false;
  }
  return true;
}

void ClientSocket::sendMessage()
{
  std::cout << "sendMessage thread id=" << std::this_thread::get_id() << std::endl;
  std::string send_message = "";
  int iResult = -1;
  while (true)
  {
    //no client, cannot send message
    if (m_socket)
    {
      getline(std::cin, send_message);
      if (send_message.length() <= 0)
      {
        std::cout << "Please input some words to send!" << std::endl;
        continue;
      }
      iResult = ::send(m_socket, send_message.c_str(), send_message.length(), 0);
      if (iResult > 0)
      {
        std::cout << "send_message is=" << send_message.c_str() << std::endl;
      }
      else if (iResult == 0)
      {
        continue;
      }
      else
      {
        std::cout << "send failed!" << std::endl;
        break;
      }
    }
    //sleep 10ms
    Sleep(10);

  }
}

void ClientSocket::recvMessage()
{
  std::cout << "recvMessage thread id=" << std::this_thread::get_id() << std::endl;
  int iResult = -1;
  do
  {
    char* recvData = new char[MAXLEN];
    memset(recvData, 0, MAXLEN);
    //std::cout << "what???" << std::endl;
    iResult =  ::recv(m_socket, recvData, MAXLEN, 0);
    if (iResult > 0)
    {
      std::cout << "receive message=" << recvData << std::endl;
      //recvData = nullptr;
      delete[]recvData;
      recvData = nullptr;
    }
    else if (iResult == 0)
    {
      std::cout << "recvMessage connection closed!" << std::endl;
      delete[]recvData;
      recvData = nullptr;
    }
    else
    {
      std::cout << "recv failed!" << std::endl;
      delete[]recvData;
      recvData = nullptr;
    }
    //sleep 10ms
    Sleep(10);
  } while (iResult > 0);
}

void ClientSocket::runRecvThread()
{
  recvthread = std::thread(&ClientSocket::recvMessage, this);
}
void ClientSocket::runSendThread()
{
  sendthread = std::thread(&ClientSocket::sendMessage, this);
}