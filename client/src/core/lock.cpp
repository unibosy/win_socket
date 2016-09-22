#include "../include/lock.h"

#include <string>
#include <mutex>


class Lock::LockImp
{
public:
  LockImp();
  ~LockImp();
  void lockGuard();

  void lock();
  bool tryLock();
  void unLock();
private:
  //copy constructor
  LockImp(const LockImp&);
  LockImp& operator = (const LockImp&);

  std::mutex m_mutex;

};
Lock::LockImp::LockImp()
{

}
Lock::LockImp::~LockImp()
{
}

void Lock::LockImp::lockGuard()
{
  std::lock_guard<std::mutex> lock(m_mutex);
}

void Lock::LockImp::lock()
{
  m_mutex.lock();
}

bool Lock::LockImp::tryLock()
{
  return m_mutex.try_lock();
}

void Lock::LockImp::unLock()
{
  m_mutex.unlock();
}

Lock::Lock() : m_lock( new LockImp )
{
}

Lock::~Lock()
{
  delete m_lock;
}

void Lock::lockGuard()
{
  m_lock->lockGuard();
}

void Lock::lock()
{
  m_lock->lock();
}
bool Lock::tryLock()
{
  return m_lock->tryLock();
}

void Lock::unLock()
{
  m_lock->unLock();
}