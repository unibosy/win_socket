#include "helper.h"


#include <string>
#include <mutex>
#include <iostream>

#include <windows.h>

std::mutex helper_mtx;

Helper* Helper::m_instance = nullptr;

Helper* Helper::getInstance()
{
  helper_mtx.lock();
  if (!m_instance)
  {
    m_instance = new Helper;
  }
  helper_mtx.unlock();
  return m_instance;
}

void Helper::showLastErrMessage()
{
  int errorno = GetLastError();
  std::cout << "errorno=" << errorno << std::endl;
}