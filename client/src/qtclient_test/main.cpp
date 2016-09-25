


#include "clientwindow.h"
#include <qdebug.h>

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  
  
  ClientWindow w;
  w.show();
  return a.exec();
}
