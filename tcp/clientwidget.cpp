#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QHostAddress>
#include<QMessageBox>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpsocket=nullptr;

    ui->lineIP->setText("192.168.0.106");
    ui->linePORT->setText("8888");

    tcpsocket=new QTcpSocket(this);

    connect(tcpsocket,&QTcpSocket::connected,
            [=](){
        ui->ReadEdit->setText("已连接服务器");
    });
    connect(tcpsocket,&QTcpSocket::readyRead,
            [=](){
        QByteArray array=tcpsocket->readAll();
        ui->ReadEdit->append(">"+array);
    });

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_connectButton_clicked()
{
    QString ip=ui->lineIP->text();
    qint16 port=ui->linePORT->text().toInt();

    tcpsocket->connectToHost(QHostAddress(ip),port);

}

void ClientWidget::on_sentButton_clicked()
{
    QString str=ui->WriteEdit->toPlainText();
    if(tcpsocket!=nullptr){
        tcpsocket->write(str.toUtf8().data());
        ui->WriteEdit->clear();
    }
    else {
        ui->ReadEdit->append("服务器未连接");
    }
}

void ClientWidget::on_disconnectButton_clicked()
{
    //断开连接
    int ret=QMessageBox::question(this,"Disconnect",
                          "Note: \nThis will disconnect the connection.\nDo you want to continue?");
    if(ret==QMessageBox::Yes&&tcpsocket!=nullptr){
        tcpsocket->disconnectFromHost();
        tcpsocket->close();
        ui->ReadEdit->append("已断开连接");
        tcpsocket=nullptr;
    }
    if(tcpsocket==nullptr){
        ui->ReadEdit->append("服务器未连接");
    }
}

void ClientWidget::on_sentButton_2_clicked()
{
    ui->WriteEdit->clear();
}

void ClientWidget::on_sentButton_3_clicked()
{
    ui->ReadEdit->clear();
}
