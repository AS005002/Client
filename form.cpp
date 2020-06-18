#include "form.h"
#include "ui_form.h"
#include"mainwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    int a = 0;
    WSAData wsaData;
            WORD DLLVersion = MAKEWORD(2, 2);
            if (WSAStartup(DLLVersion, &wsaData) != 0) {//upload version library
                std::cout << "Error. Can't upload lib\n";
                exit(1);
            }

            SOCKADDR_IN addr;//struct save addr
            QString IP = ui->lineEdit->text();
            addr.sin_addr.s_addr = inet_addr(IP.toUtf8().data());//sin_addr save addr

            addr.sin_port = htons((ui->lineEdit_2->text()).toInt());//port
            addr.sin_family = AF_INET;//family protocols

            Connection = socket(AF_INET, SOCK_STREAM, NULL);
            if (::connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
                std::cout << "Error; failed connect to server.\n";
                QMessageBox::warning(this, "Внимание","Ошибка. Соеденение не установлено");
            }
            else
            {
                std::cout << "Client is connected" << std::endl;
                QMessageBox::information(this, "Информация","Подключение установлено");
                a=1;

            }
            this->close();// Закрываем окно
    emit mainWindow(a);
    emit copyWindow(ui->lineEdit->text(), ui->lineEdit_2->text(), &Connection);
    emit giveSocket(&Connection);
}
