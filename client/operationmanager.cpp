#include "operationmanager.h"

#include "core\operation_login.h"

#include <memory>
#include <string>
#include <iostream>


std::mutex instance_mtx;

OperationManager* OperationManager::m_instance = nullptr;


OperationManager::OperationManager()
{
}

OperationManager::~OperationManager()
{
}

OperationManager* OperationManager::instance()
{
  if (m_instance == nullptr)
  {
    std::lock_guard<std::mutex> lock(instance_mtx);
    if (m_instance == nullptr)
      m_instance = new OperationManager;
  }
  return m_instance;
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