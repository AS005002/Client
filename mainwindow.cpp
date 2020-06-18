#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Connection=new SOCKET();
    ui->setupUi(this);
    cpyWindow = new Copy();
    prosmotr=new Prosmotr();
    connect(ui->label, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
    connect(cpyWindow, &Copy::mainWindow_cpy, this, &MainWindow::show);
    connect(this, &MainWindow::giveSocketCp, cpyWindow, &Copy::getSocket);
    connect(this, &MainWindow::giveSocketSh, prosmotr, &Prosmotr::getSocket);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cpyWindow->show();
    this->close();
    emit giveSocketCp(Connection);
}

void MainWindow::on_pushButton_2_clicked()
{
    prosmotr->show();
    this->close();
    emit giveSocketSh(Connection);
}


void MainWindow::Mouse_Pressed()
{
    ui->label_2->setText(ui->label_2->text()+" "+"All right");
}

void MainWindow::getSocket(SOCKET *socket, QString login)
{
    Connection=socket;
    ui->label_2->setText(ui->label_2->text()+" "+login);

}
