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
#include "cbhandler.h"

/*
 *brief use client sdk:step 1: initApp, 2: login , 3: startRunning
 */

class COMMU_API AppContext
{
public:
  static AppContext& instance();
  int initApp();
  int startRunning();

  void setCBHandler(CBHandler*cbhander);
  CBHandler* getCBHandler();
private:
  AppContext();
  ~AppContext();

  CBHandler* m_cbhandler;
};