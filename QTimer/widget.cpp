#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer(this);

    connect(timer,&QTimer::timeout,
            [=](){
        static int num=0;
       ui->lcdNumber->display(++num);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //定时器一到时间就会抛出信号timeout
    if(timer->isActive()==false){
        timer->start(100);
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(timer->isActive()==true){
         timer->stop();
    }

}
