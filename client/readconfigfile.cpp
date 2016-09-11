#include "readconfigfile.h"

#include <iostream>
#include <fstream>

ReadConfig::ReadConfig()
{
}
ReadConfig::~ReadConfig()
{
}
std::string ReadConfig::getFileContent(const std::string& filepath)
{
  std::ifstream stream(filepath.c_str(), std::ios::in);
  std::istreambuf_iterator<char> beg(stream), end;
  std::string content(beg, end);
  std::cout << "file content=" << content << std::endl;
  stream.close();
  return content;
}
#define SEMICOLON ";"
#define DOUBLEQUOTES "\""


std::string ReadConfig::getServerIP(const std::string& filecontent)
{
  size_t first_index = filecontent.find_first_of(DOUBLEQUOTES);
  size_t last_index = filecontent.find_last_of(DOUBLEQUOTES);

  std::string serverip = filecontent.substr(first_index+1, last_index-first_index-1);
  std::cout << "serverip="<<serverip << std::endl;
  return serverip;
}