#pragma once


#include <string>

class ReadConfig
{
public:
  ReadConfig(std::string& filepath);
  ~ReadConfig();
public:
  void readText();
  void setServerIP(const std::string& sip) { m_sip = sip; }
  const std::string getServerIP() const { return m_sip; };

  void setClientIP(std::string& cip) { m_cip = cip; }
  const std::string getClientIP()const { return m_cip; };
private:
  std::string m_sip;
  std::string m_cip;
  std::string m_filepath;
};