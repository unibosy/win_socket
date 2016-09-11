#include "serversocket.h"

#include <string>
#include <iostream>
using namespace std;

// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")


int main(int argc, char* argv[])
{
  ServerSocket* socket_server = new ServerSocket;

  socket_server->init();

  getchar();
  return 0;
}