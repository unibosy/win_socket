#include "macros.h"
#include "readconfigfile.h"
#include "clientsocket.h"
#include "utility.h"


#include "iostream"
#pragma  comment(lib,"ws2_32.lib")


int main(int argc, char* argv[])
{
  ReadConfig* readfile = new ReadConfig;
  std::string content = readfile->getFileContent(configure_path);
  std::string serverip = readfile->getServerIP(content);
  std::cout << "content="<< serverip << std::endl;

  ClientSocket* cs = new ClientSocket;
  cs->init(serverip);
  std::cout << "end init" << std::endl;

  delete cs;
  cs = nullptr;
  delete readfile;
  readfile = nullptr;

  getchar();
  return 0;
}