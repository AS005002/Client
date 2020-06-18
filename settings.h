#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include<QFileSystemModel>
#include<QDir>
#include<iostream>
#include<QMessageBox>
#include"vhod.h"
#pragma comment(lib,"wsock32.lib")//include functions
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include<winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    SOCKET Connection;
signals:
    void giveSocket(SOCKET* socket);
private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();

private:
    Ui::Settings *ui;
    Vhod *vhod;
};

#endif // SETTINGS_H
