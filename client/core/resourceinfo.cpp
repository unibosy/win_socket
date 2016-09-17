#include "../include/resourceinfo.h"

ResourceInfo::ResourceInfo()
{
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

void ResourceInfo::setResourceIP(const char* ip)
{
  m_ip = ip;
}
const char* ResourceInfo::getResourceIP() const
{
  return m_ip;
}