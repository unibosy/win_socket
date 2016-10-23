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
  ClientSocket::instance().setMessage("from client message!");
  return 1;
}