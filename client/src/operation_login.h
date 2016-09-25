
#pragma once

#include "../operationmanager_imp.h"

class Operation_Login : public OperationManager_Imp
{
public:
  Operation_Login();
  ~Operation_Login();
  int invoke_para(ResourceInfo* resourceinfo, void* para);
};