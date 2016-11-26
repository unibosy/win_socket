#include "../operation_send_message.h"
#include "../clientsocket.h"

Operation_Send_Message::Operation_Send_Message()
{
}

Operation_Send_Message::~Operation_Send_Message()
{
}

//DO NOT USE smart pointer to point ui parameter!
int Operation_Send_Message::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  //donot use unique_ptr
  //std::unique_ptr<SMessage> sp_smsg((SMessage*)(para));
  //std::shared_ptr<SMessage> sp_smsg((SMessage*)(para));

  std::string str = ((SMessage*)(para))->message;;

  ClientSocket::instance().setMessage(str.c_str());
  return 1;
}