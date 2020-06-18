#ifndef VHOD_H
#define VHOD_H

#include <QWidget>
#include"enum.h"
#include<iostream>
#include"mainwindow.h"
#include"registration.h"
#include<QMessageBox>
using namespace std;
#pragma comment(lib,"wsock32.lib")//include functions
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include<winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
namespace Ui {
class Vhod;
}

class Vhod : public QWidget
{
    Q_OBJECT

public:
    explicit Vhod(QWidget *parent = nullptr);
    ~Vhod();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

public slots:
    void getSocket(SOCKET* socket);
signals:
    void giveSocketMain(SOCKET *socket, QString login);
    void giveSocketReg(SOCKET *socket);
private:
    Ui::Vhod *ui;
    SOCKET *Connection;
    MainWindow *main;
    Registration *reg;
};

#endif // VHOD_H
