#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);
    void myTimeout();
    void setStop(bool flag=true);
signals:
    void mySingal();
private:
    bool isStop;


};

#endif // MYTHREAD_H
