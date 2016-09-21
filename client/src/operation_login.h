
#pragma once

#include "../include/operationmanager.h"

class Operation_Login : public OperationManager
{
public:
  Operation_Login();
  ~Operation_Login();
  int invoke_para(ResourceInfo* resourceinfo, void* para);
};