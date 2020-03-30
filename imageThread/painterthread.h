#ifndef PAINTERTHREAD_H
#define PAINTERTHREAD_H

#include <QObject>
#include<QImage>
class painterThread : public QObject
{
    Q_OBJECT
public:
    explicit painterThread(QObject *parent = nullptr);
public slots:
    void drawImge();
signals:
    void updateImge(QImage temp);

};

#endif // PAINTERTHREAD_H
