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
  lbl_font.setPointSize(16);      //���������С  
  lbl->setFont(lbl_font);
  lbl->setText("Hello World.");
  lbl->setGeometry(QRect(20, 20, 150, 30)); //���ô�С��λ��  
  lbl->setFrameStyle(QFrame::Panel | QFrame::Sunken); //�������  

  QLineEdit* line = new QLineEdit(mainWindow);
  line->setText("12345");

  mainWindow->resize(200, 100);   //�����������С  
  mainWindow->setWindowTitle("Qt Test");  //�����������ǩ  
  mainWindow->show();
}