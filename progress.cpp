#include "progress.h"
#include "ui_progress.h"
Progress::Progress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Progress)
{
    ui->setupUi(this);
}
Progress::~Progress()
{
    delete ui;
}

void Progress::FileName(QByteArray fileName, QString file, SOCKET* socket)
{
    Packet packettype=P_RecvServer;
    send(*socket, (char*)&packettype, sizeof(Packet), NULL);
    QFile fileIn1(file);
    QFileInfo fileInfo(file);
    int size_message = fileName.size();
    int column;
    send(*socket, (char*)&size_message, sizeof(int), NULL);
    send(*socket, fileName.data(), size_message, NULL);
    if(fileInfo.size()%1024==0) column=fileInfo.size()/1024;
    else column=fileInfo.size()/1024+1;
    send(*socket, (char*)&column, sizeof(int), NULL);
    if(fileIn1.open(QIODevice::ReadOnly))
    {
        ui->progressBar->setMaximum(fileIn1.size());
        ui->progressBar->setMinimum(0);
        ui->progressBar->setValue(0);
        while(column)
        {
            if(column!=1) size_message=1024;
            else size_message=fileInfo.size()%1024;
            send(*socket, (char*)&size_message, sizeof(int), NULL);
            send(*socket, fileIn1.read(size_message), size_message, NULL);
            ui->progressBar->setValue(ui->progressBar->value()+size_message);
            ui->progressBar->update();
            QApplication::processEvents();
            column--;
        }
        fileIn1.close(); // Закрываем filein.txt
        ui->progressBar->setValue(ui->progressBar->maximum());
        this->close();
    }
}




