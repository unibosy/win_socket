#pragma once
#include <qdialog.h>
#include <qwidget.h>
#include "qt_cbhandler.h"


class Widget : public QWidget
{
  Q_OBJECT

  friend class QTCBHandler;
public:
  Widget() { ; }
  ~Widget() { ; }

  void test() { ; }


 
public slots:
  
signals:
  void recvChatMessage(int classType);
};