#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mythread.h"
#include<QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void dealSingal();
    void on_pushButton_2_clicked();

signals:
    void startThread();
private:
    Ui::Widget *ui;
    myThread *mt;
    QThread *thread;
};
#endif // WIDGET_H
