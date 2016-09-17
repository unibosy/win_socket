#pragma once

#include "../include/resourceinfo.h"

enum OPERATIONTYPE
{
  LOGIN,
  LOGOUT,
  UNKNOWN_TYPE
};

class OperationBase
{
public:
  OperationBase();
  virtual ~OperationBase();

  virtual int invoke(ResourceInfo* resourceinfo,OPERATIONTYPE type, void* para);
private:

};
