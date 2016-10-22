#pragma once

//real workers who work detail tasks

#include "qobject.h"


#include "string"

class DispatchTask : public QObject
{
public:
  ~DispatchTask();
  static DispatchTask& getInstance();
  void dispatchChatTask(int type,std::string& message);


private:
  DispatchTask();

public slots:
  void setValue(int value);
signals:
  void notiryChatMsg(std::string& message);
};