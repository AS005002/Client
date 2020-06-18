#include "copy.h"
#include "ui_copy.h"

Copy::Copy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Copy)
{
    ui->setupUi(this);
    prog=new Progress();
    model=new QFileSystemModel(this);
    model->setFilter(QDir::QDir::AllEntries);
    model->setRootPath("");
    ui->listView->setModel(model);
    Connection=new SOCKET();
    connect(this, &Copy::ProgWindow, prog, &Progress::FileName);
}
void Copy::on_listView_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileInfo=model->fileInfo(index);
    if(fileInfo.fileName()=="..")
    {
        QDir dir=fileInfo.dir();
        dir.cdUp();
        ui->listView->setRootIndex(model->index(dir.absolutePath()));
        ui->lineEdit->setText(fileInfo.absolutePath());
        ui->pushButton->setEnabled(0);
    }
    else if(fileInfo.fileName()==".")
    {
        QDir dir=fileInfo.dir();
        dir.cdUp();
        ui->listView->setRootIndex(model->index(""));
        ui->lineEdit->setText("");
        ui->pushButton->setEnabled(0);
    }
    else if (fileInfo.isDir()) {
        ui->listView->setRootIndex(index);
        if (fileInfo.absolutePath()[fileInfo.absolutePath().length()-1]!="/")
        {
            ui->lineEdit->setText(fileInfo.absolutePath()+"/"+fileInfo.fileName());
        }
        ui->lineEdit->setText(fileInfo.absolutePath()+fileInfo.fileName());
        ui->pushButton->setEnabled(0);
    }
    else if (fileInfo.isFile()) {
        ui->lineEdit->setText(fileInfo.absolutePath()+"/"+fileInfo.fileName());
        ui->pushButton->setEnabled(1);
        fileName=fileInfo.fileName().toUtf8();

    }
}

void Copy::on_pushButton_clicked()
{
    prog->show();
    emit ProgWindow(fileName, ui->lineEdit->text(), Connection);
}
Copy::~Copy()
{
    delete ui;
}

void Copy::on_pushButton_2_clicked()
{
    this->close();
    ui->pushButton->setEnabled(0);
    ui->lineEdit->setText("");
    ui->listView->setRootIndex(model->index(""));
    emit mainWindow_cpy();
}

void Copy::getSocket(SOCKET *socket)
{
    Connection=socket;
}
