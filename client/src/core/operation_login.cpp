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
  std::cout << "OPeration_Login::invoke" << std::endl;
  std::string info = "";
  std::string ip = resourceinfo->getResourceIP();
  std::string resid = resourceinfo->getResouceID();
  std::string psd = resourceinfo->getPassword();
  ClientSocket::instance()->setMessage("Hello World!");
  return 0;
}