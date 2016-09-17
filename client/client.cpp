#include "macros.h"
#include "readconfigfile.h"
#include "clientsocket.h"
#include "utility.h"
#include "core\operation_login.h"
#include "include\resourceinfo.h"
#include "operationmanager.h"


#include "iostream"
#pragma  comment(lib,"ws2_32.lib")


int main(int argc, char* argv[])
{
  ReadConfig* readfile = new ReadConfig;
  std::string content = readfile->getFileContent(configure_path);
  std::string serverip = readfile->getServerIP(content);
  std::cout << "content="<< serverip << std::endl;
  //init
  ClientSocket::instance()->init(serverip.c_str());
  std::cout << "end init" << std::endl;

  //login
  StrList strlist = Utility::instance()->getLocalIP();
  std::string ip = "";
  for (StrList::iterator itr = strlist.begin(); itr != strlist.end(); ++itr)
  {
    ip = *itr;
    std::cout << "ip="<<ip << std::endl;
  }
  ResourceInfo* resinfo = new ResourceInfo;
  resinfo->setResourceID("1000");
  resinfo->setPassword("abcdf");
  resinfo->setResourceIP(ip.c_str());
  OperationManager* op = new Operation_Login;
  op->invoke(resinfo, LOGIN, nullptr);

  std::cout << "................." << std::endl;

  delete readfile;
  readfile = nullptr;

  getchar();
  return 0;
}