/*
Copyright (c) 2016 by unibosy@gmail.com
This file is part of the unibosy library. https://github.com/unibosy
This software is distributed under a license. The full license
agreement can be found in the file LICENSE in this distribution.
This software may not be copied, modified, sold or distributed
other than expressed in the named license agreement.
This software is distributed without any warranty.
*/
#pragma once

#include "include/operationmanager.h"
#include "operation_base.h"

//implement OperationManager

class OperationManager_Imp : public OperationBase
{
public:
  OperationManager_Imp();
  ~OperationManager_Imp();

  static OperationManager_Imp* instance();

  int invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para);
private:
  static OperationManager_Imp* m_instance;
};