#include "../include/utility.h"

#include <thread>
#include <mutex>
#include <iostream>

#include"Winsock2.h"  
#pragma comment(lib,"WS2_32.lib")  

std::mutex mtx;

Utility* Utility::m_instance = nullptr;

Utility::Utility()
{
  
}
Utility::~Utility()
{
  if (m_strlist.size() > 0)
  {
    m_strlist.clear();
  }
  if (m_instance)
  {
    delete m_instance;
    m_instance = nullptr;
  }
}
Utility* Utility::instance()
{
  if (m_instance == nullptr)
  {
    mtx.lock();
    if (m_instance == nullptr)
      m_instance = new Utility;
    mtx.unlock();
  }
  return m_instance;
}

//TODO:
//when logon server, read last used localip from data.xml, if no localip then set localip to logon.
StrList Utility::getLocalIP()
{
  WSADATA wsaData;
  if ( WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR )
  {
    std::cout << "ERROR:WSAStartup error!" << std::endl;
    return m_strlist;
  }

  char host[256] = { 0 };
  memset(host, 0, sizeof(host));
  //get local pc host name
  int status = gethostname(host, sizeof(host));
  if (status == SOCKET_ERROR)
  {
    std::cout << "ERROR:gethostname error!" << std::endl;
    return m_strlist;
  }
  //get local ip by host name
  hostent *pHost = gethostbyname(host);
  
  std::string str_ip = "";
  //print all these ips
  in_addr addr;
  for ( int i = 0; ; i++ )
  {
    char *p = pHost->h_addr_list[i];
    if (p == NULL)
      break;
    memcpy(&addr.S_un.S_addr, p, pHost->h_length);
    str_ip = ::inet_ntoa(addr);
    std::cout<<"local ip="<< str_ip << std::endl;
    m_strlist.push_back(str_ip);
  }
  ::WSACleanup();
  return m_strlist;
}
