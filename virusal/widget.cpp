#include "widget.h"
#include "ui_widget.h"
#include<QSqlError>
#include<QSqlQuery>
#include <QSqlDatabase>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QSqlRecord>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("hll523811");
    db.setDatabaseName("db");
    if(db.open()==false){
        QMessageBox::warning(this,"错误",db.lastError().text());
    }
    //设置模型
    mod=new QSqlTableModel(this);
    mod->setTable("qt");
    ui->tableView->setModel(mod);
    //显示模型数据
    mod->select();
    //改表头
    mod->setHeaderData(0,Qt::Horizontal,"名字");
    mod->setHeaderData(1,Qt::Horizontal,"年龄");
    //设置手动编辑模式
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //设置不给修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_AddpushButton_clicked()
{
    //添加空记录
    QSqlRecord record=mod->record();//获取空记录
    //获取行号
    int row=mod->rowCount();
    mod->insertRecord(row,record);

}

void Widget::on_OKpushButton_clicked()
{
    mod->submitAll();//提交
}

void Widget::on_CancelpushButton_clicked()
{
    mod->revertAll();// 取消操作
    mod->submitAll();//提交取消
    //恢复原来视图
    mod->setTable("qt");
    mod->select();
}

void Widget::on_DeletepushButton_clicked()
{
    //获取选择的模型
    QItemSelectionModel *sm=ui->tableView->selectionModel();
    //取出模型的索引
    QModelIndexList list=sm->selectedRows();
    //删除所选行
    for (int i=0;i<list.size();i++) {
       mod->removeRow(list.at(i).row());//取出索引包含的行号
    }
}

void Widget::on_FindpushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString str=QString("name='%1'").arg(name);//注意后面的''
    mod->setFilter(str);
    //刷新显示
    mod->select();
}
