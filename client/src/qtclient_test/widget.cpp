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
  m_qlabel = new QLabel(this);
  m_qledit = new QLineEdit(this);
}
void Widget::prepareConnects()
{
  LOG(INFO) << "prepareConnects";
  connect(DispatchTask::getInstance(), SIGNAL(notifyChatMsg(const char*)),
    this, SLOT(recvChatMessage(const char*)));

  connect(this, SIGNAL(toShowWhatRecv(const char*)), this, SLOT(displayMessage(const char*)));
}


void Widget::prepareUI()
{
  m_qlabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);//set appearance
  m_qlabel->setObjectName("QLabel");
  m_qlabel->setText("received message:");
  m_qlabel->setAlignment(Qt::AlignBottom | Qt::AlignRight); // set alignment
  m_qlabel->setGeometry(QRect(20, 20, 110, 30)); //set size and position
  m_qlabel->show();

  m_qledit->setGeometry(QRect(150,20,400,30));

}
void Widget::recvChatMessage(const char* message)
{
  LOG(INFO) << "this widget receive a new message="<< message;
  dispalyMessage(message);
  emit toShowWhatRecv(message);
}


void Widget::dispalyMessage(const char* message)
{
  LOG(INFO) << "this widget receive a new message11111=" << message;
  this->m_qledit->setText(message);

}

void Widget::sendMessage()
{
  std::unique_ptr<OperationManager> om(new OperationManager);
  std::unique_ptr<ResourceInfo> resinfo(new ResourceInfo());

  om.get()->invoke(resinfo.get(), SEND_MSG, nullptr);
}






