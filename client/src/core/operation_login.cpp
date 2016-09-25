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
  const std::string resid = resourceinfo->getResouceID();
  const std::string psd = resourceinfo->getPassword();
  const std::string serverip = resourceinfo->getServerIP();

  LOG(INFO) << "do init ";
  ClientSocket::instance()->init(serverip.c_str());

  LOG(INFO) << "send login message";
  ClientSocket::instance()->setMessage("Hello World!");
  return 0;
}