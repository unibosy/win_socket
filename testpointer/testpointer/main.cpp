#include <string>
#include <iostream>

class Test
{
public:
  Test();
  ~Test();
  void set(const char* src);
  const char* get() const;
private:
  char* m_buf;
};

Test::Test()
{
  m_buf = new char[255];
  memset(m_buf, 0, 255);
}
Test::~Test()
{
  
}
void Test::set(const char* src)
{
  strncpy(m_buf, src, strlen(src));
}
const char* Test::get() const
{
  return m_buf;
}


int main()
{
  Test* test = new Test;
  test->set("hello");
  const char* msg = test->get();
  printf("msg=%s", msg);
  delete msg;
  msg = nullptr;
  getchar();
  return 0;
}