#include "qt_cbhandler.h"
#include "log.h"
#include "widget.h"
#include "dispatchtask.h"

QTCBHandler::QTCBHandler()
{
}
QTCBHandler::~QTCBHandler()
{

}

void QTCBHandler::handleChatMessage(int msgType, std::string message)
{
  LOG(INFO)<<"enter handleChatMessage,message="<< message;

  DispatchTask::getInstance()->dispatchChatTask(msgType,message);

  LOG(INFO) << "leave handleChatMessage";
}