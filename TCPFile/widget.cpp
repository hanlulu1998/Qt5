#include "widget.h"
#include "ui_widget.h"
#include<QHostAddress>
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>
#include<QTimer>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->SendpushButton->setEnabled(false);
    ui->ChoosepushButton->setEnabled(false);
    SendSize=0;
    tcpserver=new QTcpServer(this);

    tcpserver->listen(QHostAddress::Any,8888);
    connect(tcpserver,&QTcpServer::newConnection,
            [=](){
        tcpsocket=tcpserver->nextPendingConnection();
        QString ip =tcpsocket->peerAddress().toString();
        quint16 port=tcpsocket->peerPort();

        QString messg=QString("[%1:%2]:连接成功").arg(ip).arg(port);
        ui->textdisplay->setText(messg);
        ui->ChoosepushButton->setEnabled(true);

        connect(tcpsocket,&QTcpSocket::readyRead,
                [=](){
            QByteArray array=tcpsocket->readAll();
            if(QString(array)=="File done"){
                ui->textdisplay->append("文件接收完成");
                tcpsocket->disconnectFromHost();
                tcpsocket->close();
            }
        });


        });

    connect(&timer,&QTimer::timeout,
            [=](){
        timer.stop();
        SendData();
        });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ChoosepushButton_clicked()
{
   QString path=QFileDialog::getOpenFileName(this,"Open","../");

   if(path.isEmpty()==false){
       file.setFileName(path);

       fileName=QFileInfo(file).fileName();

       fileSize=QFileInfo(file).size();

       bool flag=file.open(QIODevice::ReadOnly);

       if(true==flag){
           ui->textdisplay->append(path);
           ui->textdisplay->append(QString("file:%1 size:%2").arg(fileName).arg(fileSize));
           ui->SendpushButton->setEnabled(true);

       }
       else{
           ui->textdisplay->append("文件打开错误");
       }

   }
   else{
       ui->textdisplay->append("文件路径错误");
   }
}

void Widget::on_SendpushButton_clicked()
{
    QString head=QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len=tcpsocket->write(head.toUtf8().data());
    if(len>0){
         timer.start(20);
    }
    else{
        file.close();
        ui->ChoosepushButton->setEnabled(true);
        ui->SendpushButton->setEnabled(false);

    }
}
void  Widget::SendData(){
    qint64 len=0;
    char buff[4*1024]={0};
    do{

        len=0;
        len=file.read(buff,sizeof(buff));
        tcpsocket->write(buff,len);
        SendSize+=len;

    }while(len>0);
    if(SendSize==fileSize){
        ui->textdisplay->append("文件发送完毕");
        file.close();
    }

}
