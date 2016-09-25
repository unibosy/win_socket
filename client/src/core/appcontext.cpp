#include "../include/appcontext.h"
#include "../include/log.h"
#include "commondef.h"

#include <string>
#include <thread>


AppContext* AppContext::m_appcontext = nullptr;

AppContext* AppContext::instance()
{
  return nullptr;
}

AppContext::AppContext()
{
}

AppContext::~AppContext()
{
}

int AppContext::initApp()
{
  Log::instance()->initLog(LOGNAME);
  return 0;
}

int AppContext::startRunning()
{
  return 0;
}