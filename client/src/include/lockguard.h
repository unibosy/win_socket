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

#include "lock.h"

//Implementation of a lock guard.

class COMMU_API LockGuard
{
public:

  //Contructs a new simple lock guard and locks the supplied Lock.
  LockGuard(Lock* lock);

  LockGuard(Lock& lock);


  //Destructor. Releases the guarded Mutex.
  ~LockGuard();

private:
  LockGuard& operator=(const LockGuard&);
  Lock& m_lock;
};