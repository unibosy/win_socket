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

//set the login user infomessage, like ip, userid, password...

class COMMU_API ResourceInfo
{
public:
  ResourceInfo();
  ~ResourceInfo();

  void setResourceID(const char* rid);
  const char* getResouceID() const;

  void setPassword(const char* psw);
  const char* getPassword() const;

  void setLocalIP(const char* localip);
  const char* getLocalIP() const;

  void setServerIP(const char* serverip);
  const char* getServerIP() const;

private:
  const char* m_rid;
  const char* m_password;
  const char* m_localip;
  const char* m_serverip;
};

