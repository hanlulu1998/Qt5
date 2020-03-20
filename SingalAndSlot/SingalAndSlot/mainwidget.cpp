#include "mainwidget.h"
# include<QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(QString("主窗口"));
    b1.setParent(this);
    b1.setText(QString("关闭"));
    b2=new QPushButton(this);
    b2->setText(QString("未点击"));
    b2->move(200,200);
    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    connect(b2,&QPushButton::released,this,&MainWidget::MySlot);
    b3.setParent(this);
    b3.setText(QString("切换"));
    b3.move(100,100);
    connect(&b3,&QPushButton::pressed,this,&MainWidget::Change);
    // Qt5接受重载方式
    // void (SubWidget::*SingalFun1)()=&SubWidget::MySingal;
    //void (SubWidget::*SingalFun2)(int,QString)=&SubWidget::MySingal;
    //connect(&w,SingalFun2,this,&MainWidget::DealSingal);
    //Qt4接受重载方式
    //首先满足所有的槽函数是public slots：定义
    //connect(&w,SINGAL(MySingal(int,QSTring)),this,SOLT(DealSingal));

    //Lambda表达式
    //首先满足CONFIG += c++11
    b4=new QPushButton(this);
    b4->setText(QString("Lambda表达式"));
    b4->move(300,300);
    int a=1;
    connect(b4,&QPushButton::pressed,this,
            [=]() mutable {
        b4->setText(QString("Lambda输出"));
        qDebug()<<"Lambde:"<<a;
        a++;
    });



    this->resize(500,400);
}
void MainWidget::MySlot(){
    b2->setText(QString("已点击"));
}
void MainWidget::Change(){
    w.show();
    this->hide();


}
void MainWidget::DealSolt(){
    this->show();
    w.hide();

}
void  MainWidget::DealSingal(int a,QString str){
    qDebug()<<a<<str;


}
MainWidget::~MainWidget()
{
    delete b2;
}

