#include "../include/resourceinfo.h"

ResourceInfo::ResourceInfo()
{
  m_rid = "";
  m_localip = "";
  m_password = "";
  m_serverip = "";
}

ResourceInfo::~ResourceInfo()
{
}

void ResourceInfo::setResourceID(const char* rid)
{
  m_rid = rid;
}
const char* ResourceInfo::getResouceID() const
{
  return m_rid;
}

void ResourceInfo::setPassword(const char* psw)
{
  m_password = psw;
}
const char* ResourceInfo::getPassword() const
{
  return m_password;
}

void ResourceInfo::setLocalIP(const char* localip)
{
  m_localip = localip;
}
const char* ResourceInfo::getLocalIP() const
{
  return m_localip;
}

void ResourceInfo::setServerIP(const char* serverip)
{
  m_serverip = serverip;
}

const char* ResourceInfo::getServerIP() const
{
  return m_serverip;
}