#include "../../../include/commondef.h"
#include "../../../include/macros.h"
#include "../../../include/operationmanager.h"
#include "../../../include/resourceinfo.h"

#include "readconfigfile.h"

#include "memory"


#include "iostream"
#pragma  comment(lib,"ws2_32.lib")


int main(int argc, char* argv[])
{
  //read file for getting server ip
  std::unique_ptr<ReadConfig> readfile(new ReadConfig);
  std::string content = readfile.get()->getFileContent(configure_path);
  std::string serverip = readfile.get()->getServerIP(content);
  std::cout << "content=" << serverip << std::endl;

  //step 1: init
  ClientSocket::instance()->init(serverip.c_str());
  std::cout << "end init" << std::endl;

  //get localip
  StrList strlist = Utility::instance()->getLocalIP();
  std::string ip = "";
  for (StrList::iterator itr = strlist.begin(); itr != strlist.end(); ++itr)
  {
    ip = *itr;
    std::cout << "ip=" << ip << std::endl;
  }
  //step 2: login
  ResourceInfo* resinfo = new ResourceInfo;
  resinfo->setResourceID("1000");
  resinfo->setPassword("abcdf");
  resinfo->setResourceIP(ip.c_str());
  OperationManager* op = new Operation_Login;
  int ret = op->invoke(resinfo, LOGIN, nullptr);

  //do things
  std::unique_ptr<DoOperation> doop(new DoOperation);


  getchar();
  return 0;
}

