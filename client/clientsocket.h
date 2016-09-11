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


#include "winsock2.h"

#include <string>

class ClientSocket
{
public:
  ClientSocket();
  ~ClientSocket();

  //init the socket and start threads to send/receive messages.
  void init(const std::string& serverip);

protected:
  bool createSocket(const std::string& serverip);

  void runRecvThread();

  void runSendThread();

  void recvMessage();

  void sendMessage();

private:

  SOCKET m_socket;
};