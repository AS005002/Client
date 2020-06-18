#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    ui->lineEdit_6->setEchoMode(QLineEdit::Password);
    main=new MainWindow();
    Connection= new SOCKET();
    connect(this,&Registration::giveSocket,main,&MainWindow::getSocket);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    if (ui->lineEdit_5->text()!=ui->lineEdit_6->text()) QMessageBox::warning(this, "Внимание","Пароли не совпадают");
    else if (ui->lineEdit_5->text().length()<8) QMessageBox::warning(this, "Внимание","длина пароля должна быть не менее 8 символов");
    else
    {
        Packet packettype=P_Register;
        send(*Connection, (char*)&packettype, sizeof(Packet), NULL);
        int size_message=ui->lineEdit->text().length();
        send(*Connection, (char*)&size_message, sizeof(int), NULL);
        send(*Connection, ui->lineEdit->text().toUtf8(), size_message, NULL);
        size_message=ui->lineEdit_5->text().length();
        send(*Connection, (char*)&size_message, sizeof(int), NULL);
        send(*Connection, ui->lineEdit_5->text().toUtf8(), size_message, NULL);
        bool acsess;
        recv(*Connection, (char*)&acsess, sizeof(bool), NULL);
        if(acsess)
        {
            this->close();
            main->show();
            emit giveSocket(Connection, ui->lineEdit->text());
        }
        else
        {
            QMessageBox::warning(this, "Внимание","Ошибка. Логин уже существует");
        }
    }
}

void Registration::getSocket(SOCKET *socket)
{
    Connection=socket;
}

void Registration::on_pushButton_2_clicked()
{

}
