#pragma once

#include "include/resourceinfo.h"
#include "include/operationmanager.h"
#include "uiparameter.h"

class OperationBase
{
public:
  OperationBase();
  virtual ~OperationBase();

  virtual int invoke_para(ResourceInfo* resourceinfo, void* para);
  virtual int invoke(ResourceInfo* resourceinfo,OPERATIONTYPE type, void* para);
private:

};
