#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QStringList>
#include"domxml.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //开始就调用第一个页面
    on_actionCar_triggered();
    //连接数据库
    connectDB();

    initialDB();

    DomXML::createXML("..//demo.xml");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//车辆管理
void MainWindow::on_actionCar_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->Car);
    ui->label->setText("车辆管理");
}
//销售主页
void MainWindow::on_actionCalc_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->Calc);
     ui->label->setText("销售统计");
}
void MainWindow::connectDB(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("hll523811");
    db.setDatabaseName("car");
    if(db.open()==false){
       QMessageBox::warning(this,"错误",db.lastError().text());
    }

}
void MainWindow::initialDB(){
    QSqlQueryModel *queryMod=new QSqlQueryModel(this);
    queryMod->setQuery("select name from factory");
    ui->factorycomboBox->setModel(queryMod);

    ui->lastlabel->setText("0");
    ui->totallineEdit->setEnabled(false);
}
//下拉框槽函数
void MainWindow::on_factorycomboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="请选择厂家"){
        ui->brandcomboBox->clear();
        ui->pricelineEdit->clear();
        ui->lastlabel->clear();
        ui->numspinBox->setValue(0);
        ui->totallineEdit->clear();
        ui->numspinBox->setEnabled(false);
        ui->OKpushButton->setEnabled(false);
    }
    else {
        ui->brandcomboBox->clear();
        QSqlQuery query;
        QString sql=QString("select name from brand "
                            "where factory = '%1'").arg(arg1);
        query.exec(sql);
        while(query.next()){
            QString name=query.value(0).toString();
            ui->brandcomboBox->addItem(name);
        }
        ui->numspinBox->setEnabled(true);
    }
}

void MainWindow::on_brandcomboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    QString sql=QString("select price,last from brand "
                        "where factory = '%1' and name = '%2'").arg(ui->factorycomboBox->currentText()).arg(arg1);
    query.exec(sql);
    while(query.next()){
        int price=query.value("price").toInt();
        int last=query.value("last").toInt();

        ui->pricelineEdit->setText(QString::number(price));
        ui->lastlabel->setText(QString::number(last));

    }
}


void MainWindow::on_numspinBox_valueChanged(int arg1)
{
    QSqlQuery query;
    int last;
    QString sql=QString("select sum,last from brand "
                        "where factory = '%1' and name = '%2'")
            .arg(ui->factorycomboBox->currentText())
            .arg(ui->brandcomboBox->currentText());
    query.exec(sql);
    while(query.next()){
        last=query.value("last").toInt();
    }
    if(arg1==0){
        ui->numspinBox->setValue(0);

        return;

    }
    else{
         ui->OKpushButton->setEnabled(true);
    }
    ui->numspinBox->setMinimum(0);
    ui->numspinBox->setMaximum(last);
    int tempNum=last-arg1;
    ui->lastlabel->setText(QString::number(tempNum));

    //金额
    int totalprice=ui->pricelineEdit->text().toInt()*arg1;
    ui->totallineEdit->setText(QString::number(totalprice));
}

void MainWindow::on_cancelpushButton_clicked()
{
    on_factorycomboBox_currentIndexChanged("请选择厂家");
    ui->factorycomboBox->setCurrentIndex(0);
    ui->lastlabel->setText("0");
}

void MainWindow::on_OKpushButton_clicked()
{
    //获取信息
    int num=ui->numspinBox->value();
    int last=ui->lastlabel->text().toInt();

    //获取数据库数据
    QSqlQuery query;
    QString sql=QString("select sell from brand "
                        "where factory = '%1' and name = '%2'")
            .arg(ui->factorycomboBox->currentText())
            .arg(ui->brandcomboBox->currentText());
    query.exec(sql);
    int sell;

    while(query.next()){
        sell=query.value("sell").toInt();
    }
    sell+=num;

    sql=QString("update brand set sell = %1, last = %2 where factory = '%3' and name = '%4'")
            .arg(sell)
            .arg(last)
            .arg(ui->factorycomboBox->currentText())
            .arg(ui->brandcomboBox->currentText());

    query.exec(sql);

    //确定消息后，添加XML
    QStringList list;
    list<<ui->factorycomboBox->currentText()
       <<ui->brandcomboBox->currentText()
       <<ui->pricelineEdit->text()
      <<QString::number(num)
     <<ui->totallineEdit->text();
    DomXML::appendXML("../demo.xml",list);

    QStringList fList;
        QStringList bList;
        QStringList pList;
        QStringList nList;
        QStringList tList;
        QString totalstr;
        DomXML::readXML("../demo.xml", fList, bList, pList, nList, tList);
        totalstr.clear();
        for(int i = 0; i < fList.size(); i++)
        {
            QString str = QString("%1:%2:卖出了%3,单价：%4, 总价: %5")
                    .arg(fList.at(i))
                    .arg(bList.at(i))
                    .arg(nList.at(i))
                    .arg(pList.at(i))
                    .arg(tList.at(i));

                    totalstr.append(str+'\n');
        }
        ui->textEdit->setText(totalstr);

        ui->OKpushButton->setEnabled(false);

        on_cancelpushButton_clicked();


}
