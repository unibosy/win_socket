#include "serversocket.h"

#include <string>
#include <iostream>
using namespace std;

// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")


int main(int argc, char* argv[])
{
  ServerSocket* socket_server = new ServerSocket;

  int result = socket_server->init();
  if (result != 0)
  {
    std::cout << "init error" << std::endl;
    delete socket_server;
    socket_server = nullptr;
    return -1;
  }
  int run_result = socket_server->startRunning();

  getchar();
  return 0;
}