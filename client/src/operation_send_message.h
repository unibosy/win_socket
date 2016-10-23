#pragma once
#include "operation_base.h"
#include "../operationmanager_imp.h"


class Operation_Send_Message : public OperationManager_Imp
{
public:
  Operation_Send_Message();
  ~Operation_Send_Message();
  int invoke_para(ResourceInfo* resourceinfo, void* para);

private:

};

