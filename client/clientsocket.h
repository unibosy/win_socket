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
#include "macros.h"

#include "winsock2.h"

#include <string>

class ClientSocket
{
public:

  static ClientSocket* instance();
  //init the socket and start threads to send/receive messages.
  void init(const char* serverip);

  void setMessage(const char* message);
  const char* getMessage() const;
protected:
  bool createSocket(const char* serverip);

  void runRecvThread();

  void runSendThread();

  void recvMessage();

  void sendMessage();


private:

  ClientSocket();
  ~ClientSocket();

  static ClientSocket* m_instance;

  SOCKET m_socket;

  char* m_buf;
};