#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <form.h>
#include"copy.h"
#include"my_label.h"
#include"prosmotr.h"
#include<QMessageBox>
#pragma comment(lib,"wsock32.lib")//include functions
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include<winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setLabel(const QString&x);
    ~MainWindow();
    QString dir_path="";

private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void Mouse_Pressed();
public slots:
    void getSocket(SOCKET *socket, QString login);
signals:
    void giveSocketCp(SOCKET *socket);
    void giveSocketSh(SOCKET *socket);
private:
    Ui::MainWindow *ui;
    Copy *cpyWindow;
    SOCKET *Connection;
    Prosmotr *prosmotr;
};

#endif // MAINWINDOW_H
