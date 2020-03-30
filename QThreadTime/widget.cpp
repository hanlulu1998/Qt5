#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mt=new myThread;//不可以指定父对象,手动回收
    //创建子线程
    thread=new QThread(this);
    //加入子线程
    mt->moveToThread(thread);
    connect(mt,&myThread::mySingal,this,&Widget::dealSingal);
    qDebug()<<"主线程号"<<QThread::currentThread();

    connect(this,&Widget::startThread,mt,&myThread::myTimeout);

}

Widget::~Widget()
{
    delete ui;
    delete mt;
}


void Widget::on_pushButton_clicked()
{
    thread->start();//启动线程没有调用函数，直接调用又会在一个线程
    //只能通过信号和槽
    mt->setStop(false);
    emit startThread();


}
void Widget::dealSingal(){
    static int i=0;
    ui->lcdNumber->display(++i);
}

void Widget::on_pushButton_2_clicked()
{
    mt->setStop(true);
    thread->quit();
    thread->wait();
}
