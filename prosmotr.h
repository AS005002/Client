#ifndef PROSMOTR_H
#define PROSMOTR_H

#include<QStringListModel>
#include <QWidget>
#include"enum.h"
using namespace std;
#pragma comment(lib,"wsock32.lib")
#pragma warning(disable: 4996)
#include<winsock2.h>
namespace Ui {
class Prosmotr;
}

class Prosmotr : public QWidget
{
    Q_OBJECT

public:
    explicit Prosmotr(QWidget *parent = nullptr);
    ~Prosmotr();
public slots:
    void getSocket(SOCKET *socket);
private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Prosmotr *ui;
    SOCKET *Connection;
    QStringList list;
    QStringListModel stringListModel;
};

#endif // PROSMOTR_H
