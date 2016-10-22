#include "../include/appcontext.h"
#include "../include/log.h"
#include "commondef.h"

#include <string>
#include <thread>

AppContext& AppContext::instance()
{
  static AppContext appcontext;
  return appcontext;
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

//const after a function declaration means the function is not allowed to changed any class members
//except ones marked mutable
void AppContext::setCBHandler(CBHandler* cbhandler)
{
  m_cbhandler = cbhandler;
}
CBHandler* AppContext::getCBHandler()
{
  return m_cbhandler;
}
