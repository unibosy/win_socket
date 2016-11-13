#pragma once

#include "string"

#include "json\json.h"

/*namespace Json {
  class Value;
}*/

class JsonConvert
{
public:
  //thread safety after cpp11
  /*JsonConvert& instance() {
    static JsonConvert instance;
    return instance;
  }*/
  JsonConvert() { ; }
  ~JsonConvert() { ; }
  Json::Value StrToJson(const std::string& str);
  std::string JsonToStr(const Json::Value& jsonvalue);
private:
  

};