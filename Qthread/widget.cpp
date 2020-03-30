#include "widget.h"
#include "ui_widget.h"

#include<QThread>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,
            [=](){
        //timer->stop();
        static int i=0;

        ui->lcdNumber->display(++i);
    });
    td=new MyThread(this);
    connect(td,&MyThread::isDone,this,&Widget::DealThread);
    connect(this,&Widget::destroy,this,&Widget::stopThread);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(timer->isActive()==false){
        timer->start(100);
    }
    td->start();


}
void Widget::DealThread(){
    timer->stop();
}
void Widget::stopThread(){
    td->quit();
    td->wait();

}
