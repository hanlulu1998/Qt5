#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QImage>
#include"painterthread.h"
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
public slots:
    void getImge(QImage imge);
private:
    Ui::Widget *ui;
    QImage imge;
    painterThread *pthread;
    QThread *thread;
protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // WIDGET_H
