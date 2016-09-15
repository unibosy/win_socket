/*
Copyright (c) 2016 by unibosy@gmail.com
This file is part of the unibosy library. https://github.com/unibosy
This software is distributed under a license. The full license
agreement can be found in the file LICENSE in this distribution.
This software may not be copied, modified, sold or distributed
other than expressed in the named license agreement.
This software is distributed without any warranty.
*/

#pragma once

#include <winsock2.h>
#include <string>

class ServerSocket
{
public:
  ServerSocket();
  ~ServerSocket();
  //init the socket and start threads to send/receive messages.
  int init();
  int startRunning();
  
protected:
  void recvClientConnect();

  int createSocket();

  void runRecvThread();

  void runSendThread(/*void* p*/);
  
  void recvMessage(SOCKET client_sock);

  void sendMessage(SOCKET sock);

  void waitAcceptClient();
private:
  
  SOCKET m_server_socket;
  SOCKET m_client_socket;
};