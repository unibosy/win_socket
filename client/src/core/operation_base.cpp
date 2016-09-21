#include "../operation_base.h"



OperationBase::OperationBase()
{
}

OperationBase::~OperationBase()
{
}


int OperationBase::invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para)
{
  //implement in derived class
  return 0;
}