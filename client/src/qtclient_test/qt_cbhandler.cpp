#include "qt_cbhandler.h"
#include "log.h"
#include "widget.h"
#include "dispatchtask.h"

void QTCBHandler::handleChatMessage(int msgType, std::string classType)
{
  LOG(INFO)<<"enter handleChatMessage";
  Widget* widget = new Widget;

  //DispatchTask::getInstance().dispatchChatTask(msgType,classType);

  //emit recvChatMessage(classType);
  LOG(INFO) << "leave handleChatMessage";
}