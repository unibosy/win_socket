#include "dispatchtask.h"

#include "log.h"

DispatchTask* DispatchTask::m_dt = nullptr;

DispatchTask::DispatchTask()
{
  //connect(this,SIGNAL(notiryChatMsg(int)),this, SLOT(setValue(int)));
  connect(this, SIGNAL(notifyChatMsg(const char*)),this,SLOT(setValue(const char*)));
}
DispatchTask::~DispatchTask()
{

}

//thread-safe in C++11
/*DispatchTask& DispatchTask::getInstance()
{
  static DispatchTask singleInstance;
  return singleInstance;
}*/

void DispatchTask::dispatchChatTask(const int& type, const std::string& message)
{
  LOG(INFO)<<"dispatch Chat Task,and message="<<message;
  emit notifyChatMsg(message.c_str());
}

void DispatchTask::setValue(const char* message)
{
  LOG(INFO) << "setvalue="<< message;
}
