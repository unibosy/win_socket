#include "mainwindow.h"

#include "qlabel.h"
#include "qlineedit.h"

Test::Test(QWidget *parent)
    : QMainWindow(parent)
{
}

Test::~Test()
{

}

void Test::showWidget()
{
  QMainWindow *mainWindow = new QMainWindow;

  QLabel *lbl = new QLabel(mainWindow);
  QFont lbl_font;
  lbl_font.setPointSize(16);      //设置字体大小  
  lbl->setFont(lbl_font);
  lbl->setText("Hello World.");
  lbl->setGeometry(QRect(20, 20, 150, 30)); //设置大小和位置  
  lbl->setFrameStyle(QFrame::Panel | QFrame::Sunken); //设置外观  

  QLineEdit* line = new QLineEdit(mainWindow);
  line->setText("12345");

  mainWindow->resize(200, 100);   //设置主窗体大小  
  mainWindow->setWindowTitle("Qt Test");  //设置主窗体标签  
  mainWindow->show();
}