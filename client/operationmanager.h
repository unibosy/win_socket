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

#include "core\operation_base.h"

#include <mutex>

class  OperationManager : public OperationBase
{
public:
  
  OperationManager();
  ~OperationManager();

  static OperationManager*instance();

  virtual int invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para);

  virtual int invoke_para(ResourceInfo* resourceinfo, void* para);
private:

  static OperationManager* m_instance;



};

