#include "operationmanager.h"
#include "commondef.h"
#include "appcontext.h"
#include "macros.h"


#include "clientwindow.h"
#include <qdebug.h>

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  
  //int ret = AppContext::instance()->initApp();
  //qDebug() << "ret="<<ret;

  //OperationManager* op = new OperationManager;
  
  ClientWindow w;
  w.show();
  return a.exec();
}
