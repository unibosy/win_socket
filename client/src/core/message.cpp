#include "../include/reportmessage/message.h"

Message::Message() : m_userid(nullptr), m_username(nullptr), m_message_type(-1)
{

}

Message::~Message()
{
  //should avoid memory leak
}

void Message::setUserID(const char* userid)
{
  m_userid = userid;
}