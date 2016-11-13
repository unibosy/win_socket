#pragma once

#include "../macros.h"

//Base message, defines the commonality of these reported messages

class COMMU_API Message
{
public:
  Message();
  ~Message();

  void setUserID(const char* userid);
  char* getUserID() const;

  void setUserName(const char* username);
  char* getUserName() const;

  //just defin type as int temporarily
  void setMessageType(const int type);
  int getMessageType() const;
private:
  const char* m_userid;
  const char* m_username;

  const int m_message_type;
};