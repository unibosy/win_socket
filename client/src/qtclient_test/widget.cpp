#include "widget.h"
#include "dispatchtask.h"
#include "../include/operationmanager.h"

#include "log.h"

Widget::Widget()
{
  prepareDatas();
  prepareConnects();
  prepareUI();
}

Widget::~Widget()
{

}

void Widget::prepareDatas()
{
  m_recvQlabel = new QLabel(this);
  m_recvQledit = new QLineEdit(this);
  
  m_sendQlabel = new QLabel(this);
  m_sendQledit = new QLineEdit(this);
}
void Widget::prepareConnects()
{
  LOG(INFO) << "prepareConnects";
  connect(DispatchTask::getInstance(), SIGNAL(notifyChatMsg(const char*)),
    this, SLOT(recvChatMessage(const char*)));
  //connect signal slot params :const char*
  //connect(this, SIGNAL(toShowWhatRecv(const char*)), this, SLOT(displayMessage(const char*)));
  
  connect(m_recvQledit, SIGNAL(toShowWhatRecv(const char*)), this, SLOT(setText(const char*)));

  //send connect and slot
  //connect(m_sendQledit, SIGNAL(textFinished(const char*)), this, SLOT(sendMessage(const char*)));

  connect(m_sendQledit, SIGNAL(textEdited(const QString&)), this, SLOT(sendMessage(const QString&)));
}


void Widget::prepareUI()
{
  m_recvQlabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);//set appearance
  m_recvQlabel->setObjectName("QLabel");
  m_recvQlabel->setText("Received Message:");
  m_recvQlabel->setAlignment(Qt::AlignBottom | Qt::AlignRight); // set alignment
  m_recvQlabel->setGeometry(QRect(20, 20, 110, 30)); //set size and position
  m_recvQlabel->show();

  m_recvQledit->setGeometry(QRect(150,20,400,30));

  //send layout
  m_sendQlabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);//set appearance
  m_sendQlabel->setObjectName("QLabel");
  m_sendQlabel->setText("Send Message:");
  m_sendQlabel->setAlignment(Qt::AlignBottom | Qt::AlignRight); // set alignment
  m_sendQlabel->setGeometry(QRect(20,60,110,30));
  m_sendQlabel->show();

  m_sendQledit->setGeometry(QRect(150, 60, 400, 30));
  m_sendQledit->setPlaceholderText("SendMessage");
  m_sendQledit->setEchoMode(QLineEdit::Normal);
  m_sendQledit->editingFinished();

}
void Widget::recvChatMessage(const char* message)
{
  LOG(INFO) << "this widget receive a new message="<< message;
  dispalyMessage(message);
  //why here connet and slot does not work???
  //emit toShowWhatRecv(message);
}


void Widget::dispalyMessage(const char* message)
{
  LOG(INFO) << "this widget receive a new message11111=" << message;
  this->m_recvQledit->setText(message);

}

void Widget::sendMessage(QString& qstr)
{
  LOG(INFO)<< "send message"<<qstr.toStdString();
  std::unique_ptr<OperationManager> om(new OperationManager);
  std::unique_ptr<ResourceInfo> resinfo(new ResourceInfo());

  om.get()->invoke(resinfo.get(), SEND_MSG, nullptr);
}






