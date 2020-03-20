#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
# include <QPushButton>
# include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void MySlot();
    void Change();
    void DealSolt();
    void DealSingal(int,QString);
private:
    QPushButton b1,*b2,b3,*b4;
    SubWidget w;

};
#endif // MAINWIDGET_H
