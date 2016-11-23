#pragma once
#include <qdialog.h>
#include <qwidget.h>
#include "qlabel.h"
#include "qlineedit.h"

#include "qt_cbhandler.h"
#include "ui_client.h"

class Widget : public QWidget/*, public QObject*/
{
  Q_OBJECT

  friend class QTCBHandler;
public:
public slots :
  void recvChatMessage(const char*);
  //void showWhatRecv(const char*);
  void dispalyMessage(const char*);

  //send message
  void sendMessage();
signals:
  void emitShowWhatRecv(const char*);
  //QLineEdit::returnPressed(QString&);
public:
  //Widget(QWidget* parent = 0);
  Widget(QWidget* parent = 0);
  ~Widget();

  void prepareConnects();
  void prepareDatas();
  void prepareUI();

public:
  QLabel* m_recvQlabel;
  QLineEdit* m_recvQledit;

  //send
  QLabel* m_sendQlabel;
  QLineEdit* m_sendQledit;

//protected:

private:
  std::string m_recvdata;
 

};