#include "dispatchtask.h"

#include "log.h"

DispatchTask::DispatchTask()
{
  connect(this,SIGNAL(notiryChatMsg(int)),this, SLOT(setValue(int)));
}
DispatchTask::~DispatchTask()
{

}

//thread-safe in C++11 
DispatchTask& DispatchTask::getInstance()
{
  static DispatchTask singleInstance;
  return singleInstance;
}

void DispatchTask::dispatchChatTask(int type, std::string& message)
{
  LOG(INFO)<<"dispatch Chat Task";
  emit notiryChatMsg(message);
}

void DispatchTask::setValue(int value)
{
  LOG(INFO) << "setvalue="<<value;
}