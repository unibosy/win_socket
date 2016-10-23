#pragma once
#include <qdialog.h>
#include <qwidget.h>
#include "qlabel.h"
#include "qlineedit.h"


#include "qt_cbhandler.h"


class Widget : public QWidget/*, public QObject*/
{
  Q_OBJECT

  friend class QTCBHandler;
public:
  public slots :
    void recvChatMessage(const char*);
    void dispalyMessage(const char*);
signals:
  void toShowWhatRecv(const char*);
public:
  //Widget(QWidget* parent = 0);
  Widget();
  ~Widget();

  void prepareConnects();
  void prepareDatas();
  void prepareUI();

public:
  QLabel* m_qlabel;
  QLineEdit* m_qledit;

//protected:

private:
  std::string m_recvdata;
 

};