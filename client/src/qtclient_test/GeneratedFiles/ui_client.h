/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientClass
{
public:
    QWidget *centralWidget;
    QCheckBox *checkBox;
    QPushButton *login_btn;
    QPushButton *cancel_btn;
    QLabel *id_label;
    QLineEdit *id;
    QLabel *psw_label;
    QLineEdit *password;
    QLabel *lip_label;
    QLabel *sip_label;
    QLineEdit *localip;
    QLineEdit *serverip;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientClass)
    {
        if (ClientClass->objectName().isEmpty())
            ClientClass->setObjectName(QStringLiteral("ClientClass"));
        ClientClass->resize(600, 400);
        centralWidget = new QWidget(ClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(150, 220, 91, 16));
        login_btn = new QPushButton(centralWidget);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(150, 270, 75, 23));
        cancel_btn = new QPushButton(centralWidget);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        cancel_btn->setGeometry(QRect(370, 270, 75, 23));
        id_label = new QLabel(centralWidget);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(150, 60, 54, 16));
        id = new QLineEdit(centralWidget);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(220, 60, 113, 20));
        psw_label = new QLabel(centralWidget);
        psw_label->setObjectName(QStringLiteral("psw_label"));
        psw_label->setGeometry(QRect(150, 100, 54, 12));
        password = new QLineEdit(centralWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(220, 100, 113, 20));
        lip_label = new QLabel(centralWidget);
        lip_label->setObjectName(QStringLiteral("lip_label"));
        lip_label->setGeometry(QRect(150, 140, 61, 16));
        sip_label = new QLabel(centralWidget);
        sip_label->setObjectName(QStringLiteral("sip_label"));
        sip_label->setGeometry(QRect(150, 180, 61, 16));
        localip = new QLineEdit(centralWidget);
        localip->setObjectName(QStringLiteral("localip"));
        localip->setGeometry(QRect(220, 140, 113, 20));
        serverip = new QLineEdit(centralWidget);
        serverip->setObjectName(QStringLiteral("serverip"));
        serverip->setGeometry(QRect(220, 180, 113, 20));
        ClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        ClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ClientClass->setStatusBar(statusBar);

        retranslateUi(ClientClass);

        QMetaObject::connectSlotsByName(ClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientClass)
    {
        ClientClass->setWindowTitle(QApplication::translate("ClientClass", "Client", 0));
        checkBox->setText(QApplication::translate("ClientClass", "Remember Me", 0));
        login_btn->setText(QApplication::translate("ClientClass", "Login", 0));
        cancel_btn->setText(QApplication::translate("ClientClass", "Cancel", 0));
        id_label->setText(QApplication::translate("ClientClass", "ID:", 0));
        psw_label->setText(QApplication::translate("ClientClass", "Password:", 0));
        lip_label->setText(QApplication::translate("ClientClass", "Local IP:", 0));
        sip_label->setText(QApplication::translate("ClientClass", "Server IP:", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientClass: public Ui_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
