#include "clientwindow.h"


#include "operationmanager.h"
#include "commondef.h"
#include "appcontext.h"
#include "macros.h"
#include "log.h"


#include <qstring.h>
#include <qdebug.h>
#include <iostream>
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
  qDebug() << "loginClicked";
  login();
  
}
void ClientWindow::cancelClicked()
{
  qDebug() << "cancelClicked";
  this->close();
}

int ClientWindow::login()
{
  int ret = AppContext::instance()->initApp();

  LOG(INFO)<<"initApp result="<<m_serverip.toStdString();

  //save dialog data, in case dialog disapear and data deleted.
  std::string userid = m_id.toStdString();
  std::string psw = m_psw.toStdString();
  std::string localip = m_localip.toStdString();
  std::string serverip = m_serverip.toStdString();
  
  ResourceInfo* rinfo = new ResourceInfo;
  rinfo->setResourceID(userid.c_str());
  rinfo->setPassword(psw.c_str());
  rinfo->setLocalIP(localip.c_str());
  //rinfo->setServerIP(m_serverip.toStdString().c_str());
  rinfo->setServerIP(serverip.c_str());


  std::auto_ptr<OperationManager> opm(new OperationManager);

  int result = opm.get()->invoke(rinfo, LOGIN, nullptr);

  delete rinfo;
  rinfo = nullptr;

  return 0;
}