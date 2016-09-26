#include "../clientsocket.h"
#include "../include/commondef.h"
#include "../include/lock.h"
//#include "../include/log.h"


//NOT: compile error about ERROR redefined if include log.h
//nedd add GLOG_NO_ABBREVIATED_SEVERITIES in Preprocessor
#include "../include/log.h"

#include <string>
#include <thread>
#include <mutex>
#include <iostream>

//create threads
std::thread recvthread;
std::thread sendthread;


std::unique_ptr<Lock> lockInstance(new Lock);
std::unique_ptr<Lock> lockCreateSock(new Lock);

ClientSocket::ClientSocket() : m_socket(0)
{
  m_buf = new char[MESSAGEBUF];
  memset(m_buf, 0, strlen(m_buf));
}
ClientSocket::~ClientSocket()
{}

ClientSocket* ClientSocket::m_instance = nullptr;

//2016/09/26 TOFIX: get lcokInstance always is nullptr.
ClientSocket* ClientSocket::instance()
{
  if (m_instance == nullptr)
  {
    LOG(INFO)<<"get client socket instance";
    if (lockInstance.get())
    {
      LOG(WARNING) << "lock instance is null!!";
      return nullptr;
    }
    lockInstance.get()->lock();
    if (m_instance == nullptr)
      m_instance = new ClientSocket;
    LOG(INFO) << "unlock lock!";
    lockInstance.get()->unLock();
  }
  LOG(INFO) << "return client socket instance";
  return m_instance;
}
void ClientSocket::init(const char* serverip)
{
  bool result =createSocket(serverip);
  if(result)
  {
    runRecvThread();
    runSendThread();
    recvthread.detach();
    sendthread.detach();
  }
  else
  {
    std::cout << "init failed!" << std::endl;
  }
  
}


bool ClientSocket::createSocket(const char* serverip)
{
  LOG(INFO)<<"enter create socket";
  lockCreateSock.get()->lockGuard();
  WORD sockVersion = MAKEWORD(2, 2);
  WSADATA data;
  if (WSAStartup(sockVersion, &data) != 0)
  {
    LOG(WARNING) << "WSAStartup error!";
    return false;
  }

  m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (m_socket == INVALID_SOCKET)
  {
    std::cout << "invalid socket !" << std::endl;
    int err = GetLastError();
    LOG(WARNING) << "call socket return error! err="<<err;
    return false;
  }

  sockaddr_in serAddr;
  serAddr.sin_family = AF_INET;
  serAddr.sin_port = htons(SERVERPORT);
  serAddr.sin_addr.S_un.S_addr = inet_addr(serverip);
  if (connect(m_socket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
  {
    std::cout<<"connect error !"<<std::endl;
    LOG(WARNING) << "call connect return error!";
    closesocket(m_socket);
    return false;
  }
  LOG(INFO) << "leave create socket";
  return true;
}

void ClientSocket::sendMessage()
{
  //int length = strlen(send_message);
  std::cout << "sendMessage thread id=" << std::this_thread::get_id() << std::endl;
    //<<",message="<< send_message << ",length="<< length <<std::endl;

  int iResult = -1;
  while (true)
  {
    //no client, cannot send message
    if (m_socket)
    {
      const char* send_message = getMessage();
      if (strlen(send_message) > 0)
      {

        iResult = ::send(m_socket, send_message, strlen(send_message), 0);

        std::cout << "send_message="<< send_message << std::endl;
        memset(m_buf, 0, MESSAGEBUF);
        //delete send_message;
        //send_message = nullptr;
        memset(m_buf, 0, MESSAGEBUF);
        if (iResult > 0)
        {
          std::cout << "send_message is=" << send_message << std::endl;
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

void ClientSocket::setMessage(const char* message)
{
  strncpy(m_buf, message, strlen(message));
}
const char* ClientSocket::getMessage() const
{
  return m_buf;
}