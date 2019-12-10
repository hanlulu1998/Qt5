#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidegt.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void MySlot();
    void ChaSubWin();
    void ChaMainWin();
private:
    QPushButton b1;
    QPushButton *b2;
     QPushButton b3;
     SubWidegt w;

};
#endif // WIDGET_H
