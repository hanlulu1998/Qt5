#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMessageBox>
#include<QCloseEvent>
#include<QTime>
#include<QtGlobal>
# include<QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    time=1;
    timeID=0;
    OverTime=0;
    caitime=0;
    ui->setupUi(this);
    setWindowIcon(QIcon("../img/sample.ico"));
    ui->timeBar->setFormat("%vS");
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->addItem("20");
    ui->comboBox->addItem("40");
    ui->comboBox->addItem("60");
    ui->comboBox->addItem("80");
    ui->comboBox->addItem("100");
    ui->comboBox->addItem("200");
    ui->result->clear();
    ui->historylabel->clear();
    ui->suglabel->setText("Please enter 4 digits");

    connect(ui->pushButton0,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton1,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton2,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton3,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton4,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton5,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton6,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton7,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton8,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton9,&QPushButton::clicked,this,&Widget::DealNum);
    connect(ui->pushButton_ok,&QPushButton::clicked,this,&Widget::DealNum);

    ui->label_con->setText("<a href=\"mailto:hanlulu1998@outlook.com?Subject=Hello!%20Write%20what%20you%20want%20to%20say!\" "
                           "target=\"_top\">联系作者</a>");
    ui->label_con->setOpenExternalLinks(true);




}

Widget::~Widget()
{
    delete ui;

}

void Widget::on_ExitButton_clicked()
{
    close();
}
void Widget::closeEvent(QCloseEvent *event){
    int ret=QMessageBox::question(this,"警告","是否要退出？");
    if(ret==QMessageBox::Yes){
        event->accept();
    }
    else {
        event->ignore();
    }
}

void Widget::on_StartButton_clicked()
{
    timeID=this->startTimer(1000);

    ui->stackedWidget->setCurrentIndex(1);

    totaltime=ui->comboBox->currentText().toInt();

    ui->timeBar->setMaximum(totaltime);

    ui->timeBar->setValue(0);

    randstr=GenRand();


}
void Widget::timerEvent(QTimerEvent *ev){
    if(ev->timerId()==timeID&&timeID!=0){
        ui->timeBar->setValue(time);

        if(totaltime==time){
            killTimer(timeID);
            timeID=0;
            time=1;
            ui->overlabel->setText("败");
            ui->stackedWidget->setCurrentIndex(2);
            resulthistory.clear();
            resultStr.clear();
            ui->result->clear();
            ui->historylabel->clear();
            ui->suglabel->setText("Please enter 4 digits");

        }
        time++;
    }


    if(ev->timerId()==OverTime&&OverTime!=0){
        killTimer(OverTime);
        OverTime=0;
        resulthistory.clear();
        resultStr.clear();
        ui->result->clear();
        ui->historylabel->clear();
        ui->suglabel->setText("Please enter 4 digits");
        ui->overlabel->setText("胜");
        ui->stackedWidget->setCurrentIndex(2);

    }


    if(ev->timerId()==caitime&&caitime!=0){
        killTimer(caitime);
        caitime=0;
        ui->overlabel->setText("菜");
        ui->stackedWidget->setCurrentIndex(2);
        resulthistory.clear();
        resultStr.clear();
        ui->result->clear();
        ui->historylabel->clear();
        ui->suglabel->setText("Please enter 4 digits");

    }

}
void  Widget::DealNum(){
    QObject *msend=sender();
    QPushButton *p=static_cast<QPushButton *>(msend);
    if(nullptr!=p&&p!=ui->pushButton_ok){
        QString numstr=p->text();
        if(resultStr.size()<4){
             resultStr+=numstr;
            if(resultStr.size()==1&&numstr=="0"){
                resultStr.clear();
            }
            ui->result->setText(resultStr);
        }
         else {
              ui->suglabel->setText("Only guess four digits");
         }
    }
    if(nullptr!=p&&p==ui->pushButton_ok){

        if(resultStr.size()==4){
            QString temp;
            temp=resultStr+"\n";
            resulthistory+=temp;
            ui->historylabel->setText(resulthistory);

            if(resultStr>randstr){
                ui->suglabel->setText("It's a little big");
                resultStr.clear();
            }
            else if(resultStr<randstr){
                ui->suglabel->setText("It's a little bit small");
                resultStr.clear();
            }
            else{
                killTimer(timeID);
                timeID=0;
                time=1;
                ui->suglabel->setText("Congratulations!");

                OverTime=this->startTimer(1500);
            }
            ui->result->clear();
        }
    }
}
QString Widget::GenRand(){
    int num;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    while((num=qrand()%10000)<999);
   // qDebug()<<QString::number(num);
    return QString::number(num);
}

void Widget::on_pushButton_sug_clicked()
{
    killTimer(timeID);
    timeID=0;
    time=1;

    ui->suglabel->setText(QString("The random number is "+randstr));


    caitime=this->startTimer(2500);
}
void Widget::on_pushButton_del_clicked()
{
     if(resultStr.size()==1){
         resultStr.clear();
         ui->result->clear();
     }
     else{
         resultStr.chop(1);
         ui->result->setText(resultStr);
     }


}

void Widget::on_pushButton_ag_clicked()

{
    timeID=this->startTimer(1000);

    time=1;

    ui->timeBar->setValue(0);

    ui->stackedWidget->setCurrentIndex(1);

    randstr=GenRand();


}

void Widget::on_pushButton_menu_clicked()

{
    ui->stackedWidget->setCurrentIndex(0);
    ui->timeBar->setValue(0);
}

void Widget::on_pushButton_back_clicked()
{
    killTimer(timeID);
    timeID=0;
    time=1;
    ui->timeBar->setValue(0);

    ui->stackedWidget->setCurrentIndex(0);

}

void Widget::on_pushButton_rest_clicked()
{
    killTimer(timeID);
    timeID=0;
    time=1;
    ui->timeBar->setValue(0);

    timeID=this->startTimer(1000);


    ui->stackedWidget->setCurrentIndex(1);
    resulthistory.clear();
    resultStr.clear();
    ui->result->clear();
    ui->historylabel->clear();
    ui->suglabel->setText("Please enter 4 digits");

    randstr=GenRand();




}
