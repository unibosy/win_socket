#include "../operation_base.h"



OperationBase::OperationBase()
{
}

OperationBase::~OperationBase()
{
}

int OperationBase::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  return 0;
}

int OperationBase::invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para)
{
  //implement in derived class
  return 0;
}