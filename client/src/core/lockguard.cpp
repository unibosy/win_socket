#include "../include/lockguard.h"


LockGuard::LockGuard( Lock* lock ) : m_lock(*lock)
{
  if (lock) 
    m_lock.lock();
}
LockGuard::LockGuard(Lock& lock) : m_lock(lock)
{
  m_lock.lock();
}
LockGuard::~LockGuard()
{
  m_lock.unLock();
}

