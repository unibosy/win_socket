#include "readfile.h"
#include "log.h"

#include <iostream>
#include <fstream>

ReadConfig::ReadConfig(std::string& filepath) :m_sip(""), m_cip(""), m_filepath("")
{
  m_filepath = filepath;
}
ReadConfig::~ReadConfig()
{

}

#define CLIENTIP "clientip="
#define SERVERIP "serverip="

void ReadConfig::readText()
{
  std::string line = "";

  std::ifstream file;
  file.open(m_filepath);
  if (file.is_open())
  {
    while (getline(file, line))
    {
      if(!strncmp(line.c_str(), CLIENTIP,strlen(CLIENTIP)))
      {
        LOG(INFO) << "client ip="<<line;
        std::string localip = "";
        size_t localip_pos = line.find("=");
        localip = line.substr(localip_pos + 1,strlen(line.c_str())- localip_pos + 1);
        setClientIP(localip);
      }
      else if (!strncmp(line.c_str(), SERVERIP,strlen(SERVERIP)))
      {
        LOG(INFO) << "server ip=" << line;
        std::string serverip = "";
        size_t serverip_pos = line.find("=");
        serverip = line.substr(serverip_pos + 1, strlen(line.c_str()) - serverip_pos + 1);
        setServerIP(serverip);
      }

    }
  }

}


