#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QPixmap
    QPixmap pix(400,300);
    QPainter p(&pix);
    //填充背景
    pix.fill(Qt::white);
    p.drawPixmap(0,0,185,250,QPixmap("../img/woman.jpg"));
    //保存图片
    pix.save("../pix.jpg");





}

Widget::~Widget()
{
    delete ui;
}

