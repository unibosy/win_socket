#pragma once


#include "cbhandler.h"

//reimplement CBHandler to receive messages.

class QTCBHandler : public CBHandler
{
public:
  QTCBHandler() { ; }
  ~QTCBHandler() { ; }
  //receive various messages by msgtype and classtype
  void handleChatMessage(int msgType, std::string classType);


};
