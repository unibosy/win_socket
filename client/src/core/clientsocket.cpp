#include "../clientsocket.h"
#include "../include/commondef.h"

//NOTE: compile error about ERROR redefined if include log.h
//nedd add GLOG_NO_ABBREVIATED_SEVERITIES in Preprocessor
#include "../include/log.h"
#include "../include/appcontext.h"

#include <string>
#include <thread>
#include <mutex>
#include <iostream>

//create threads
std::thread recvthread;
std::thread sendthread;

//thread-safe after c++11
ClientSocket& ClientSocket::instance()
{
  static ClientSocket cs;
  return cs;
}

ClientSocket::ClientSocket() : m_socket(0)
{
  m_buf = new char[MESSAGEBUF];
  //strlen string length, not include '\0', sizeof array memory size
  memset(m_buf, 0, MESSAGEBUF*sizeof(char));
}
ClientSocket::~ClientSocket()
{
  if (m_buf)
  {
    delete m_buf;
  }
}

bool ClientSocket::init(const char* serverip)
{
  bool result = createSocket(serverip);
  //Here there are some bugs, which cause some crash.
  if(result)
  {
    runRecvThread();
    runSendThread();
    recvthread.detach();
    sendthread.detach();
  }
  else
  {
    LOG(WARNING) << "init error!";
  }
  return result;
  
}

bool ClientSocket::fini()
{
  LOG(INFO)<<"enter fini";
  bool bStopSock = stopSocket();
  LOG(INFO)<<"stop socket ret="<< bStopSock;

  bool bStopThreads = stopAllThreads();

  LOG(INFO) << "leave fini";

  return true;

}

bool ClientSocket::stopAllThreads()
{
  return true;
}

//simplely return true
bool ClientSocket::stopSocket()
{
  if(m_socket)
    closesocket(m_socket);
  return true;
}

bool ClientSocket::createSocket(const char* serverip)
{
  LOG(INFO)<<"enter create socket";
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
  LOG(INFO) << "enter sendMessage";
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

        LOG(INFO)<<"::send message, message="<< send_message;
        //delete send_message;
        //send_message = nullptr;
        memset(m_buf, 0, MESSAGEBUF);
        const char* sendStr = getMessage();
        LOG(INFO) << "::send message, message 1=" << sendStr;

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
  //std::cout << "recvMessage thread id=" << std::this_thread::get_id() << std::endl;
  LOG(INFO) << "client receive message!";
  //std::unique_ptr<CBHandler> cbh(AppContext::instance().getCBHandler());
  CBHandler* cbh(AppContext::instance().getCBHandler());
  int iResult = -1;
  do
  {
    char* recvData = new char[MAXLEN];
    memset(recvData, 0, MAXLEN);
    //std::cout << "what???" << std::endl;
    iResult =  ::recv(m_socket, recvData, MAXLEN, 0);
    if (iResult > 0)
    {
      LOG(INFO) << "::recv result bigger than zero,message="<<recvData;
      cbh->handleChatMessage(1, recvData);

      //recvData = nullptr;
      delete[]recvData;
      recvData = nullptr;
    }
    else if (iResult == 0)
    {
      LOG(INFO)<<"recvMessage connection closed!";
      delete[]recvData;
      recvData = nullptr;
    }
    else
    {
      LOG(INFO) << "recv failed!";
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
  memset(m_buf,0, MESSAGEBUF);
  strncpy(m_buf, message, strlen(message));
}
const char* ClientSocket::getMessage() const
{
  return m_buf;
}