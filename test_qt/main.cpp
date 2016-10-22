#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test w;
    w.showWidget();
    //w.show();
    return a.exec();
}
