#include "client.h"

#include <qstring.h>
#include <qdebug.h>
Client::Client(QWidget *parent)
  : QMainWindow(parent),
  ui(new Ui::ClientClass)
{
  ui->setupUi(this);
  //connect the signals with slots
  connect(ui->id, SIGNAL(textEdited(const QString&)), this, SLOT(IDEditedFished(const QString&)));
  connect(ui->password, SIGNAL(textEdited(const QString&)), this, SLOT(IDEditedFished(const QString&)));
  connect(ui->login_btn, SIGNAL(clicked()), this, SLOT(loginClicked()));
}

Client::~Client()
{
  if (ui)
  {
    delete ui;
    ui = nullptr;
  }
}

void Client::IDEditedFished(const QString& id)
{
  qDebug() << "IDEditedFished ="<< id;
}
void Client::PassWordEditedFished(const QString& psw)
{
  
}
void Client::loginClicked()
{
  qDebug() << "loginClicked =";
}