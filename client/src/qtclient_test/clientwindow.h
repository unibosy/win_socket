#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_client.h"

#include <string>

class ClientWindow : public QMainWindow
{
  Q_OBJECT

public:
  ClientWindow(QWidget *parent = 0);
  ~ClientWindow();

  void setID(std::string& id);
  std::string getID();

private:
  Ui::ClientClass* ui;

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
  void initData();

private:
  QString m_id;
  QString m_psw;
  QString m_localip;
  QString m_serverip;

  
};

#endif // CLIENTWINDOW_H
