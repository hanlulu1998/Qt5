#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //监听套接字
    tcpserver=nullptr;
    tcpsocket=nullptr;

    tcpserver=new QTcpServer(this);
    //绑定IP和端口
    tcpserver->listen(QHostAddress::Any,8888);
    //连接完成，取出连接好的套接字
    connect(tcpserver,&QTcpServer::newConnection,
            [=](){
        //连接好的套接字
        tcpsocket=tcpserver->nextPendingConnection();
        //获取对方的IP和端口
        QString ip=tcpsocket->peerAddress().toString();
        qint16 port=tcpsocket->peerPort();
        QString messg=QString("[%1:%2]:连接成功").arg(ip).arg(port);
        ui->Receivedtext->setText(messg);
        connect(tcpsocket,&QTcpSocket::readyRead,
                [=](){
            QByteArray array=tcpsocket->readAll();
            ui->Receivedtext->append(">"+array);
        });
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    //断开连接
    int ret=QMessageBox::question(this,"Disconnect",
                          "Note: \nThis will disconnect the connection.\nDo you want to continue?");
    if(ret==QMessageBox::Yes&&tcpsocket!=nullptr){
        tcpsocket->disconnectFromHost();
        tcpsocket->close();
        ui->Receivedtext->append("服务器已断开");
        tcpsocket=nullptr;
    }
    if(tcpsocket==nullptr){
        ui->Receivedtext->append("服务器未连接任何客户端");
    }
}
void Widget::on_pushButton_clicked()
{
    QString str=ui->SentEdit->toPlainText();
    if(tcpsocket!=nullptr){
        tcpsocket->write(str.toUtf8().data());
        ui->SentEdit->clear();
    }
    else {
        ui->Receivedtext->append("服务器未连接任何客户端");
    }
}
void Widget::closeEvent(QCloseEvent *event){
    int ret=QMessageBox::question(this,"Warning",
                          "Do you want to shut down the server?");
    if(ret==QMessageBox::Yes){
        close();
    }


}

void Widget::on_clearReceivedButton_clicked()
{
    ui->Receivedtext->clear();
}

void Widget::on_cleaSentButton_clicked()
{
    ui->SentEdit->clear();
}
