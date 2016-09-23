#ifndef CLIENT_H
#define CLIENT_H

#include <QtWidgets/QMainWindow>
#include "ui_client.h"

#include <string>

class Client : public QMainWindow
{
  Q_OBJECT

public:
  Client(QWidget *parent = 0);
  ~Client();

  void setID(std::string& id);
  std::string getID();

private:
  Ui::ClientClass* ui;

  //add slots
public slots:
  void IDEditedFished(const QString&);
  void PassWordEditedFished(const QString&);
  void loginClicked();

};

#endif // CLIENT_H
