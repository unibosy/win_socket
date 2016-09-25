#include "../include/log.h"
#include "../include/lock.h"
#pragma comment(lib,"libglog.lib")

#include <string>
#include <memory>

Log* Log::m_instance = nullptr;


Log::Log()
{

}

Log::~Log()
{

}
Log* Log::instance()
{
  if (m_instance == nullptr)
  {
    std::unique_ptr<Lock> lock(new Lock);
    lock.get()->lock();
    if (m_instance == nullptr)
      m_instance = new Log;
    lock.get()->unLock();
  }
  return m_instance;
}

//like "level_logname.log"
void Log::initLog(const char* logname)
{
  google::InitGoogleLogging("COMMU");
  FLAGS_minloglevel = 0;
  FLAGS_logbufsecs = 0; // write all messages into one file
  std::string filename = logname;
  std::string client_filename = "./client_sdk.log";
  //std::string warning_filename = "./warning.log";
  google::SetLogDestination(0, client_filename.c_str());
  //google::SetLogDestination(1, warning_filename.c_str());

}