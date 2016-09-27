#pragma once
#include "../operationmanager_imp.h"

class Operation_Logout : public OperationManager_Imp
{
public:
  Operation_Logout();
  ~Operation_Logout();

  int invoke_para(ResourceInfo* resourceinfo, void* para);
};
