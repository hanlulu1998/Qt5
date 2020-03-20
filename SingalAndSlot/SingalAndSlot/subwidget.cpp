#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(QString("副窗口"));
    b.setParent(this);
    b.setText(QString("切换"));
    connect(&b,&QPushButton::pressed,this,&SubWidget::SendSolt);
    this->resize(500,600);

}
void SubWidget::SendSolt(){

    emit MySingal();
    emit MySingal(250,"切换回主窗口");

}
