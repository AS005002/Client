#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>
#include<QFileSystemModel>
#include<QFile>
#include"enum.h"
#include<iostream>
#include<QMessageBox>
using namespace std;
#pragma comment(lib,"wsock32.lib")//include functions
#pragma warning(disable: 4996)
#include<winsock2.h>

namespace Ui {
class Progress;
}

class Progress : public QWidget
{
    Q_OBJECT

public:
    explicit Progress(QWidget *parent = nullptr);
    ~Progress();

private:
    Ui::Progress *ui;
    SOCKET* Connection;
    QByteArray Data;
public:
    void FileName(QByteArray fileName, QString file, SOCKET* socket);
};

#endif // PROGRESS_H
