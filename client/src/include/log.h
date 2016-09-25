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

#include "macros.h"

#include "../include/glog/logging.h"

/**
 *brief Simplely use GLOG to log messages.
 *
 */
class COMMU_API Log
{
public:
  static Log* instance();

  //init app log
  virtual void initLog(const char* logname);

protected:
 

private:
  Log();
  ~Log();

  static Log* m_instance;

};