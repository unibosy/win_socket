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

#include "resourceinfo.h"
#include "macros.h"
#include <mutex>

//operation type
enum OPERATIONTYPE
{
  LOGIN,
  LOGOUT,
  UNKNOWN_TYPE
};

/**
 * @brief all operations entrance
 *
 */

class COMMU_API  OperationManager
{
public:
  
  OperationManager();
  ~OperationManager();

  virtual int invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para);

  virtual int invoke_para(ResourceInfo* resourceinfo, void* para);
private:

};

