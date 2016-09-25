#include "../operation_login.h"
#include "../clientsocket.h"

#include <string>
#include <iostream>

Operation_Login::Operation_Login()
{
}
Operation_Login::~Operation_Login()
{
}

int Operation_Login::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  //login the server
  LOG(INFO) << "Operation_Login invoke";
  const std::string info = "";
  const std::string localip = resourceinfo->getLocalIP();
  LOG(INFO) << "Operation_Login invoke -1";
  const std::string resid = resourceinfo->getResouceID();
  const std::string psd = resourceinfo->getPassword();
  const std::string serverip = resourceinfo->getServerIP();

  LOG(INFO) << "Operation_Login invoke -1";
  ClientSocket::instance()->init(serverip.c_str());

  LOG(INFO) << "Operation_Login invoke -2";
  ClientSocket::instance()->setMessage("Hello World!");
  LOG(INFO) << "Operation_Login invoke -3";
  
  return 0;
}