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
  const std::string psw = resourceinfo->getPassword();
  const std::string serverip = resourceinfo->getServerIP();

  //step 1: create a socket with the server
  bool ret = ClientSocket::instance().init(serverip.c_str());
  LOG(INFO) << "init ret="<<ret;

  //step 2: use the userid/password to login the server
  /*
  {
    "userid":"1001",
    "password":"1001",
    "ip":"192.168.41.102"
  }
  "{\"age\":\"26\",\"name\":\"brant\"}";
  */
  std::string login_message = "\"userid\"" + semicolon;
  login_message += (left_dqm + resid + right_dqm + comma);
  login_message += "\"password\"" + semicolon;
  login_message += (left_dqm + psw + right_dqm + comma);
  login_message += "\"ip\"" + semicolon;
  login_message += (left_dqm + localip + right_dqm);

  std::string total_message = (left_brace + login_message + right_brace);
  LOG(INFO)<<"login message="<<total_message;

  ClientSocket::instance().setMessage(total_message.c_str());

  return 0;
}


