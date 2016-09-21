#pragma once

#include "include/resourceinfo.h"
#include "include/operationmanager.h"

class OperationBase
{
public:
  OperationBase();
  virtual ~OperationBase();

  virtual int invoke(ResourceInfo* resourceinfo,OPERATIONTYPE type, void* para);
private:

};
