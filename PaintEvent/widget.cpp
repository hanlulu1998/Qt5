#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPen>
#include<QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    x_foot=0;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event){
    //QPainter p(this);
    QPainter p;
    p.begin(this);
    //背景
//    p.drawPixmap(rect(),QPixmap("..\\img\\ahu.png"));
    //定义画笔
//    QPen pen;
//    pen.setWidth(5);
//    pen.setColor(QColor(14,9,234));//设置RGB
//    pen.setStyle(Qt::DashLine);
    //把笔给画家
//    p.setPen(pen);
    //定义笔刷
//    QBrush brush;
//    brush.setColor(Qt::red);
//    brush.setStyle(Qt::SolidPattern);
    //把画刷给画家
//    p.setBrush(brush);
    //直线
//    p.drawLine(50,50,150,50);
    //画矩形
//    p.drawRect(150,150,100,50);
    //画圆形
//    p.drawEllipse(QPoint(150,150),50,50);
    p.drawPixmap(x_foot,200,185,250,QPixmap("..\\img\\woman.jpg"));


    p.end();


}


void Widget::on_pushButton_clicked(){
    x_foot+=40;
    if(x_foot>width()){
    x_foot=0;
}
    //手动刷新
    update();

}
