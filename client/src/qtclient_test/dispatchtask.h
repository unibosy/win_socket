#pragma once

//real workers who work detail tasks

#include "qobject.h"

class DispatchTask : public QObject
{
public:
  ~DispatchTask();
  static DispatchTask& getInstance();
  void dispatchChatTask(int,int);


private:
  DispatchTask();

public slots:
  void setValue(int value);
signals:
  void notiryChatMsg(int classType) { ; }
};