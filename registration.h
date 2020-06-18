#ifndef REGISTRATION_H
#define REGISTRATION_H

#include"enum.h"
#include <QWidget>
#include<QMessageBox>
#include"mainwindow.h"
#pragma comment(lib,"wsock32.lib")//include functions
#pragma warning(disable: 4996)
#include<winsock2.h>
namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
signals:
    void giveSocket(SOCKET *socket, QString login);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

public slots:
    void getSocket(SOCKET* socket);
private:
    Ui::Registration *ui;
    SOCKET* Connection;
    MainWindow *main;
};

#endif // REGISTRATION_H
