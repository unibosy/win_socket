#include "../jsonconvert.h"



//#pragma comment(lib,"src\\lib\\json\\json.lib")



std::string JsonConvert::JsonToStr(const Json::Value& jsonvalue)
{
  std::string str = "";
  std::string name = "";
  std::string age = "";
  if (jsonvalue.isMember("name"))
  {
    name = jsonvalue["name"].asString();
  }
  if (jsonvalue.isMember("age"))
  {
    age = jsonvalue["age"].asString();
  }
  
  str.append(name).append(":").append(age);
  
  return str;
}

Json::Value JsonConvert::StrToJson(const std::string& str)
{
  Json::Reader reader;
  Json::Value value;
  
  if (!reader.parse(str, value))
  {
    
    return value;
  }
  
  return value;
}