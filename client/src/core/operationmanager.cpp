#include "../include/operationmanager.h"

#include "../operation_login.h"

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
  std::auto_ptr<OperationManager> op_ptr;
  switch (type)
  {
  case LOGIN:
    op_ptr.reset(new Operation_Login);
    break;
  default:
    break;
  }
  try
  {
    op_ptr->invoke_para(resourceinfo,para);
  }
  catch (...)
  {
    std::cout << "invoke_para exception!" << std::endl;
  }
  return 0;
}
int OperationManager::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  return 0;
}