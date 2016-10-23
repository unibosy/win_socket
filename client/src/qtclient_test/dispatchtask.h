#pragma once

//real workers who work detail tasks

#include "qobject.h"


#include "string"

class DispatchTask : public QObject
{
  Q_OBJECT
public:
  ~DispatchTask();
  //static DispatchTask& getInstance();
  static DispatchTask* getInstance()
  {
    if (m_dt == nullptr)
    {
      m_dt = new DispatchTask;
    }
    return m_dt;
  }
  void dispatchChatTask(int type,std::string& message);


private:
  DispatchTask();
  static DispatchTask* m_dt;
public slots:
  void setValue(const char* value);
signals:
  void notifyChatMsg(const char*);
};