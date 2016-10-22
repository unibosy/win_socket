#pragma once

#include "macros.h"
#include "string"

/**
 * brief sdk will callback this to notify various messages to upper layer.
 */

class COMMU_API CBHandler
{
public:
  CBHandler() { ; }
  virtual ~CBHandler() { ; }
  //register handler to receive incoming chat messages
  virtual void handleChatMessage(int msgType, std::string classType) = 0;
};