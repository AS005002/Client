#include "prosmotr.h"
#include "ui_prosmotr.h"
#include<QMessageBox>
#include<iostream>
using namespace std;
Prosmotr::Prosmotr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Prosmotr)
{
    ui->setupUi(this);
    ui->listView->setModel(&stringListModel);
    Connection=new SOCKET();
}

Prosmotr::~Prosmotr()
{
    delete ui;
}

void Prosmotr::getSocket(SOCKET *socket)
{
    Connection=socket;
    Packet packettype=P_Show;
    int msg_size=1;
    string str ="";
    int str_size = str.size();
    send(*Connection, (char*)&packettype, sizeof(Packet), NULL);
    send(*Connection, (char*)&str_size, sizeof(int),NULL);
    send(*Connection, str.c_str(), str_size,NULL);
    int kolvo_str;
    recv(*Connection, (char*)&kolvo_str, sizeof(int),NULL);
    for(int i=0;i<kolvo_str;i++)
    {
        recv(*Connection, (char*)&msg_size, sizeof(int),NULL);
        char* msg=new char[msg_size+1];
        msg[msg_size]=0;
        recv(*Connection, msg, msg_size,NULL);
        if(msg[0]!='.') list<<msg;
    }
    stringListModel.setStringList(list);
}

void Prosmotr::on_listView_doubleClicked(const QModelIndex &index)
{
    Packet packettype=P_Show;
    send(*Connection, (char*)&packettype, sizeof(Packet), NULL);
    QString str=index.data(Qt::DisplayRole).toString();
    if(str[0]!='.') ui->lineEdit->setText(ui->lineEdit->text()+'\\'+str);
    else if(str[0]=='.' && str[1]=='.')
    {
        //ui->lineEdit->setText("");
        for(int i=ui->lineEdit->text().length(); i>0;i--)
        {
            if(ui->lineEdit->text()[i]=='\\') break;
            else ui->lineEdit->setText(ui->lineEdit->text()+ui->lineEdit->text()[i]);
        }

    }
    int msg_size1=ui->lineEdit->text().length();
    send(*Connection,(char*)&msg_size1,sizeof(int),NULL);
    send(*Connection,ui->lineEdit->text().toUtf8(),msg_size1,NULL);
    int kolvo_str;
    recv(*Connection, (char*)&kolvo_str, sizeof(int),NULL);
    list.clear();
    for(int i=0;i<kolvo_str;i++)
    {
        recv(*Connection, (char*)&msg_size1, sizeof(int),NULL);
        char* msg=new char[msg_size1+1];
        msg[msg_size1]=0;
        recv(*Connection, msg, msg_size1,NULL);
    }
    stringListModel.setStringList(list);
}

void Prosmotr::on_listView_clicked(const QModelIndex &index)
{

}
