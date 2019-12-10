#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(200,200);

    b2=new QPushButton(this);
    b2->setText("Hello World");
    connect(&b1,&QPushButton::pressed,this,&Widget::close);
    connect(b2,&QPushButton::released,this,&Widget::MySlot);
    connect(b2,&QPushButton::released,&b1,&Widget::hide);

    this->setWindowTitle("main");
    b3.setParent(this);
    b3.setText("switch to sub");
    b3.move(100,100);
//    w.show();
    connect(&b3,&QPushButton::released,this,&Widget::ChaSubWin);
    connect(&w,&SubWidegt::MySignal,this,&Widget::ChaMainWin);
    this->resize(400,300);
}
void Widget::MySlot(){

  b2->setText("I'm Robot");
}
void Widget::ChaSubWin(){
    w.show();
    this->hide();
}
void Widget::ChaMainWin(){
    this->show();
    w.hide();
}
Widget::~Widget()
{
    delete b2;
}

