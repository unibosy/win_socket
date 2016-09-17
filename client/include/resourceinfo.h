#pragma once


//set the login user infomessage, like ip, userid, password...

class ResourceInfo
{
public:
  ResourceInfo();
  ~ResourceInfo();

  void setResourceID(const char* rid);
  const char* getResouceID() const;

  void setPassword(const char* psw);
  const char* getPassword() const;

  void setResourceIP(const char* ip);
  const char* getResourceIP() const;

private:
  const char* m_rid;
  const char* m_password;
  const char* m_ip;
};

