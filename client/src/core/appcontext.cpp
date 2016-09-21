#include "../include/appcontext.h"
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
  return 0;
}

int AppContext::startRunning()
{
  return 0;
}