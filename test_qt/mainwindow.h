#ifndef TEST_H
#define TEST_H

#include <QtWidgets/QMainWindow>


class Test : public QMainWindow
{
    Q_OBJECT

public:
    Test(QWidget *parent = 0);
    ~Test();

    void showWidget();
    
private:
};

#endif // TEST_H
