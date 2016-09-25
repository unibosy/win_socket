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

/**
 * @brief Simple implementation of std::mutex as a wrapper.
 * If locked a mutex, unlock is MUST within the same thread.
 * The same thread can get the mutex again.
 */
//TODO add LockGuard class to implement lock guard function
class COMMU_API Lock
{
public:
  Lock();
  ~Lock();

  /**
  * if out of function's range, mutex will be released automatically.
  */
  void lockGuard();

  /**
  * Locks the mutex.
  */
  void lock();
  /**
  * try to lock the mutex
  */
  bool tryLock();
  /**
  * Releases the mutex.
  */
  void unLock();

private:
  //define a nested structure which is the true implemention.
  class LockImp;
  Lock& operator = (const Lock&);
  LockImp* m_lock;
};