#include "../operation_send_message.h"
#include "../clientsocket.h"

Operation_Send_Message::Operation_Send_Message()
{
}

Operation_Send_Message::~Operation_Send_Message()
{
}

int Operation_Send_Message::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  std::unique_ptr<SMessage> smsg((SMessage*)(para));
  ClientSocket::instance().setMessage(smsg.get()->message);
  return 1;
}