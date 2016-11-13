#include "clientwindow.h"
#include "readfile.h"

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
  label = new QLabel(this);
  
  ui->setupUi(this);

  initData();
  initStye(ui);

  //connect the signals with slots
  connect(ui->id, SIGNAL(textEdited(const QString&)), this, SLOT(setID(const QString&)));
  
  connect(ui->password, SIGNAL(textEdited(const QString&)), this, SLOT(setPassword(const QString&)));

  if ("" != m_localip)
  {
    ui->localip->setText(m_localip);
  }
  else
    connect(ui->localip, SIGNAL(textEdited(const QString&)), this, SLOT(setLocalIP(const QString&)));
  if ("" != m_serverip)
  {
    ui->serverip->setText(m_serverip);
  }
  else
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
  if (m_widget)
  {
    delete m_widget;
  }
}

void ClientWindow::initStye(Ui::ClientClass* ui)
{
  ui->id->setPlaceholderText("User ID");
  ui->id->setEchoMode(QLineEdit::Normal);
  ui->password->setPlaceholderText("Password");
  ui->password->setEchoMode(QLineEdit::Normal);
  ui->localip->setPlaceholderText("Local IP");
  ui->localip->setEchoMode(QLineEdit::Normal);
  ui->serverip->setPlaceholderText("Server IP");
  ui->serverip->setEchoMode(QLineEdit::Normal);
}

void ClientWindow::initData()
{
  //std::auto_ptr<ReadFile> rf(new ReadFile(""));
  //ReadFile* rf = new ReadFile("");
  std::string configname = "config.ini";
  std::unique_ptr<ReadConfig> rc(new ReadConfig(configname));
  rc.get()->readText();
  m_localip = QString::fromStdString( rc.get()->getServerIP() );
  m_serverip = QString::fromStdString(rc.get()->getClientIP());

  LOG(INFO) << "m_localip=" << m_localip.toStdString() << ",m_serverip=" << m_serverip.toStdString();


  m_id = "";
  m_psw = "";
  //m_localip = "";
  //m_serverip = "";
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
  ui->login_btn->setDisabled(true);
  LOG(INFO)<<"login end!!";
  
}
void ClientWindow::cancelClicked()
{
  qDebug() << "cancelClicked";
  this->close();
}

//Open new dialog from mainwindow

int ClientWindow::login()
{
  label->setObjectName(QStringLiteral("qwe"));
  label->setText("aaaaaaaaaaaaaaaa");
  label->setText(QApplication::translate("ClientClass", "Local IP:", 0));
  label->show();

  int ret = AppContext::instance().initApp();

  LOG(INFO)<<"initApp result="<<m_serverip.toStdString();
  CBHandler* detailCBHandler = new QTCBHandler;
  AppContext::instance().setCBHandler(detailCBHandler);
  //save dialog data, in case dialog disapear and data deleted.
  std::string userid = m_id.toStdString();
  std::string psw = m_psw.toStdString();
  std::string localip = m_localip.toStdString();
  std::string serverip = m_serverip.toStdString();
  
  std::unique_ptr<ResourceInfo> rinfo(new ResourceInfo);
  rinfo.get()->setResourceID(userid.c_str());
  rinfo.get()->setPassword(psw.c_str());
  rinfo.get()->setLocalIP(localip.c_str());
  rinfo.get()->setServerIP(serverip.c_str());

  std::auto_ptr<OperationManager> opm(new OperationManager);

  int result = opm.get()->invoke(rinfo.get(), LOGIN, nullptr);

  LOG(INFO)<<"login result="<<result;
  if (result == 0)
  {
    this->hide();
    m_widget = new Widget(this);
    m_widget->show();
    m_widget->resize(600,600);
  }
  return 0;
}

void ClientWindow::closeEvent(QCloseEvent* bar)
{
  std::string userid = m_id.toStdString();
  std::auto_ptr<OperationManager> opm(new OperationManager);
  ResourceInfo* rinfo = new ResourceInfo(userid.c_str());
  opm.get()->invoke(rinfo,LOGOUT, nullptr);
  QWidget::closeEvent(bar);
}



