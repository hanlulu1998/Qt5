#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>
#include<QVariantList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<QSqlDatabase::drivers();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("hll523811");
    db.setDatabaseName("db");

    if(db.open()==false)
    {
        qDebug()<<"打开失败"<<db.lastError().text();
    }
    QSqlQuery Qu;
   // Qu.exec("create table qt(name varchar(20),age int);");

//    //win风格，占位符号？
//    Qu.prepare("insert into qt(name,age) values(?,?)");
//    QVariantList nameList;
//    nameList<<"xiaoming"<<"xiaohong";
//    QVariantList ageList;
//    ageList<<20<<21;
//    //顺序不可变
//    Qu.addBindValue(nameList);
//    Qu.addBindValue(ageList);
//    Qu.execBatch();

    //oracle风格
    Qu.prepare("insert into qt(name,age) values(:name,:age)");
    QVariantList nameList1;
    nameList1<<"xiao"<<"hong";
    QVariantList ageList2;
    ageList2<<20<<21;
    Qu.bindValue(":name",nameList1);
    Qu.bindValue(":age",ageList2);
    Qu.execBatch();




}

Widget::~Widget()
{
    delete ui;
}

