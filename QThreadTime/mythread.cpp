#include "mythread.h"
#include<QThread>
#include<QDebug>
myThread::myThread(QObject *parent) : QObject(parent)
{
    isStop=false;
}
void myThread::myTimeout(){
    while (isStop==false) {
        QThread::sleep(1);
        emit mySingal();
        qDebug()<<"子线程号"<<QThread::currentThread();
    }
}
void myThread::setStop(bool flag){
    isStop=flag;
}
