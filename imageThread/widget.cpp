#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pthread=new painterThread;
    thread=new QThread(this);
    pthread->moveToThread(thread);
    thread->start();
    connect(ui->pushButton,&QPushButton::pressed,pthread,&painterThread::drawImge);
    connect(pthread,&painterThread::updateImge,this,&Widget::getImge);
}

Widget::~Widget()
{
    delete ui;
    thread->quit();
    thread->wait();
    delete pthread;
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawImage(0,0,imge);

}
void Widget::getImge(QImage imge){
    this->imge=imge;
    update();
}
