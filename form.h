#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QFileSystemModel>
#include<QDir>
#include<iostream>
#include<QMessageBox>
#pragma comment(lib,"wsock32.lib")//include functions
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include<winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS


using namespace std;

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    SOCKET Connection;
signals:
    void mainWindow(int num);  // Сигнал для первого окна на открытие
    void copyWindow(QString IP, QString sock, SOCKET* socket);
    void giveSocket(SOCKET* socket);
private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();
private:
    Ui::Form* ui;

};

#endif // FORM_H
