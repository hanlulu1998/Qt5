#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去边框
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    //设置透明
    setAttribute(Qt::WA_TranslucentBackground);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,QPixmap("..\\img\\woman2.png"));

}
void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        move(event->globalPos()-pin);
    }


}
void Widget::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){
        close();
    }
    else if(event->button()==Qt::LeftButton){
        //求差值
        pin=event->globalPos()-this->frameGeometry().topLeft();


    }


}
