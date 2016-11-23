#pragma once


struct SMessage {
  SMessage() :message(nullptr) { ; }
  char* message;
  char* type; //0:normal message, 1: with file message,MMS
};
