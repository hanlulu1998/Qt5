#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QMessageBox>
#include<QHostAddress>
#include<QDebug>
clientWidget::clientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWidget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    tcpsocket=new QTcpSocket(this);
    begin=true;
    ReceiveSize=0;
    connect(tcpsocket,&QTcpSocket::readyRead,
            [=](){

        QByteArray buff=tcpsocket->readAll();
//        qDebug()<<buff;
        if(true==begin){
           begin=false;

           fileName=QString(buff).section("##",0,0);
//           qDebug()<<fileName;
           fileSize=QString(buff).section("##",1,1).toInt();
//            qDebug()<<fileSize;
           ReceiveSize=0;

           ui->progressBar->setMaximum(fileSize/1024);
           ui->progressBar->setMinimum(0);
           ui->progressBar->setValue(0);


           file.setFileName(fileName);

           bool flag=file.open(QIODevice::WriteOnly);

           if(false==flag){
               throw "打开失败";
             }
        }
        else {
            qint64 len=file.write(buff);
             qDebug()<<len;
            ReceiveSize+=len;
//            qDebug()<<ReceiveSize;
            ui->progressBar->setValue(ReceiveSize/1024);

            if(ReceiveSize==fileSize)
            {
                tcpsocket->write("File done");

                file.close();
                QMessageBox::information(this,"Complete","File reception completed");
                tcpsocket->disconnectFromHost();
                tcpsocket->close();
            }
        }
    });
}

clientWidget::~clientWidget()
{
    delete ui;
}

void clientWidget::on_ConnectpushButton_clicked()
{
    QString ip=ui->IPlineEdit->text();
    quint16 port=ui->portlineEdit->text().toInt();
    tcpsocket->connectToHost(QHostAddress(ip),port);
}
