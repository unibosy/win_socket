#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_client.h"
#include <string>

#include "widget.h"

class ClientWindow : public QMainWindow
{
  Q_OBJECT

public:
  ClientWindow(QWidget *parent = 0);
  ~ClientWindow();

  QString getID() { return m_id; }
  QString getPassword() { return m_psw; }
  QString getLocalIP() { return m_localip; }
  QString getServerIP() { return m_serverip; }

  QLabel* label;

private:
  Ui::ClientClass* ui;
  Widget* m_widget;

  //add slots
public slots:
  //user id
  void setID(const QString&);
  //user password
  void setPassword(const QString&);
  //local ip
  void setLocalIP(const QString&);
  //server ip
  void setServerIP(const QString&);
  //click login
  void loginClicked();
  //click cancel
  void cancelClicked();

protected:
  
  void initStye(Ui::ClientClass* ui);
  void initData(Ui::ClientClass* ui);
  void prepareConnect(Ui::ClientClass* ui);
  int login();


private:
  QString m_id;
  QString m_psw;
  QString m_localip;
  QString m_serverip;

  void closeEvent(QCloseEvent* bar);
};

#endif // CLIENTWINDOW_H
