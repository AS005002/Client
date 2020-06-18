#ifndef COPY_H
#define COPY_H

#include <QWidget>
#include<QFileSystemModel>
#include<QDir>
#include"progress.h"
namespace Ui {
class Copy;
}

class Copy : public QWidget
{
    Q_OBJECT
public:
    explicit Copy(QWidget *parent = nullptr);
    ~Copy();
signals:
    void ProgWindow(QByteArray fileName,QString file, SOCKET* socket);
    void mainWindow_cpy();
private slots:
    void on_pushButton_clicked();
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_pushButton_2_clicked();
public slots:
    void getSocket(SOCKET *socket);
private:
    Ui::Copy *ui;
    QFileSystemModel *model;
    Progress* prog;
    QByteArray fileName;
    SOCKET* Connection;
};

#endif // COPY_H
