#include "mwidget.h"
#include "ui_mwidget.h"
#include <QDebug>
#include<QKeyEvent>
#include<QTimerEvent>
#include<QMouseEvent>
#include<QMessageBox>
#include<QEvent>
#include<QString>
MWidget::MWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MWidget)
{
    ui->setupUi(this);
    timeID1=this->startTimer(1000);
    timeID2=this->startTimer(1);
    connect(ui->pushButton,&MButton::pressed,
            [=](){
        qDebug()<<"按钮被按下";
    });
    ui->label_3->installEventFilter(this);
    qDebug()<<QString("0").size();

}

MWidget::~MWidget()
{
    delete ui;
}
void MWidget::keyPressEvent(QKeyEvent *ev){
    qDebug()<<(char)ev->key();
}
void MWidget::timerEvent(QTimerEvent *ev){

    if(ev->timerId()==timeID1){
    static int sec=0;
    ui->label->setText(QString("<center><h>Time Out: "
                               "%1 S</h></center>").arg(sec++));
    if(5==sec){
        this->killTimer(timeID1);
    }
    }
    else if(ev->timerId()==timeID2){
        static int msec=0;
        ui->label_2->setText(QString("<center><h>Time Out: "
                                   "%1 MS</h></center>").arg(msec++));
        if(5000==msec){
            this->killTimer(timeID2);
    }
    }
}
void MWidget::mousePressEvent(QMouseEvent *ev){
    qDebug()<<"传递给父组件";

}

void MWidget::closeEvent(QCloseEvent *event){
    int ret=QMessageBox::question(this,"Warning","是否要关闭？");
    if(ret==QMessageBox::Yes){
        event->accept();

    }
    else{
        event->ignore();
    }
}
bool MWidget::event(QEvent *event){
    if(event->type()==QEvent::Timer){
        QTimerEvent *e=static_cast<QTimerEvent *>(event);
        timerEvent(e);
        return true;
}
    else {
        return QWidget::event(event);
    }
}
bool MWidget::eventFilter(QObject *obj, QEvent *event){
    if(obj==ui->label_3){
        QMouseEvent *e=static_cast<QMouseEvent *>(event);
        if(event->type()==QEvent::MouseMove){
            ui->label_3->setText(QString("Mouse Move(%1,%2)")
                                 .arg(e->x()).
                                 arg(e->y()));
            return true;
        }
        else {
            return QWidget::eventFilter(obj,event);
        }
    }
    else {
        return QWidget::eventFilter(obj,event);
    }



}
