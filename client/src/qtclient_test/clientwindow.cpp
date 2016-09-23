#include "clientwindow.h"

#include <qstring.h>
#include <qdebug.h>
ClientWindow::ClientWindow(QWidget *parent)
  : QMainWindow(parent),
  ui(new Ui::ClientClass)
{

  initData();
  ui->setupUi(this);
  //connect the signals with slots
  connect(ui->id, SIGNAL(textEdited(const QString&)), this, SLOT(setID(const QString&)));
  connect(ui->password, SIGNAL(textEdited(const QString&)), this, SLOT(setPassword(const QString&)));
  connect(ui->localip, SIGNAL(textEdited(const QString&)), this, SLOT(setLocalIP(const QString&)));
  connect(ui->serverip, SIGNAL(textEdited(const QString&)), this, SLOT(setServerIP(const QString&)));
  
  connect(ui->login_btn, SIGNAL(clicked()), this, SLOT(loginClicked()));
  connect(ui->cancel_btn, SIGNAL(clicked()), this, SLOT(cancelClicked()));
}

ClientWindow::~ClientWindow()
{
  if (ui)
  {
    delete ui;
    ui = nullptr;
  }
}

void ClientWindow::initData()
{
  m_id = "";
  m_psw = "";
  m_localip = "";
  m_serverip = "";
}
void ClientWindow::setID(const QString& id)
{
  qDebug() << "IDEditedFished ="<< id;
  m_id = id;
}
void ClientWindow::setPassword(const QString& psw)
{
  m_psw = psw;
}
void ClientWindow::setLocalIP(const QString& localip)
{
  m_localip = localip;
}
void ClientWindow::setServerIP(const QString& serverip)
{
  m_serverip = serverip;
}
void ClientWindow::loginClicked()
{
  qDebug() << "loginClicked =";
}
void ClientWindow::cancelClicked()
{

}
