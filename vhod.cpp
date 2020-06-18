#include "vhod.h"
#include "ui_vhod.h"

Vhod::Vhod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vhod)
{
    //set=new Settings();
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    main=new MainWindow();
    reg=new Registration();
    connect(this, &Vhod::giveSocketMain, main, &MainWindow::getSocket);
    connect(this, &Vhod::giveSocketReg, reg, &Registration::getSocket);
}

Vhod::~Vhod()
{
    delete ui;
}

void Vhod::on_pushButton_clicked()
{
    Packet packettype=P_Login;
    send(*Connection, (char*)&packettype, sizeof(Packet), NULL);
    int size_message=ui->lineEdit->text().length();
    send(*Connection, (char*)&size_message, sizeof(int), NULL);
    send(*Connection, ui->lineEdit->text().toUtf8(), size_message, NULL);
    size_message=ui->lineEdit_2->text().length();
    send(*Connection, (char*)&size_message, sizeof(int), NULL);
    send(*Connection, ui->lineEdit_2->text().toUtf8(), size_message, NULL);
    bool acsess;
    recv(*Connection, (char*)&acsess, sizeof(bool), NULL);
    if(acsess)
    {
        this->close();
        main->show();
        emit giveSocketMain(Connection, ui->lineEdit->text());
    }
    else
    {
        QMessageBox::warning(this, "Внимание","Ошибка. Логин или пароль неверный");
    }
}
void Vhod::getSocket(SOCKET* socket)
{
    Connection=socket;
}

void Vhod::on_pushButton_2_clicked()
{
    reg->show();
    this->close();
    emit giveSocketReg(Connection);
}
