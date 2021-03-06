#include "../include/operationmanager.h"
#include "../operation_login.h"
#include "../operation_logout.h"
#include "../operation_send_message.h"

#include "../operationmanager_imp.h"

#include <memory>
#include <string>
#include <iostream>

std::mutex instance_mtx;

OperationManager::OperationManager()
{
}

OperationManager::~OperationManager()
{
}


int OperationManager::invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para)
{
  auto result = -1;
  std::auto_ptr<OperationManager_Imp> op_ptr(new OperationManager_Imp);
  switch (type)
  {
  case LOGIN:
    op_ptr.reset(new Operation_Login);
    break;
  case LOGOUT:
    op_ptr.reset(new Operation_Logout);
    break;
  case SEND_MSG:
    op_ptr.reset(new Operation_Send_Message);
    break;
  default:
    LOG(WARNING)<<" unknown operation type!";
    break;
  }
  try
  {
    if(op_ptr.get())
      result = op_ptr.get()->invoke_para(resourceinfo,para);
  }
  catch (...)
  {
    std::cout << "invoke_para exception!" << std::endl;
    return result;
  }
  return result;
}
int OperationManager::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  return 0;
}