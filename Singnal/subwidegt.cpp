#include "subwidegt.h"

SubWidegt::SubWidegt(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("sub");
    b.setParent(this);
    b.setText("switch to mian");
    connect(&b,&QPushButton::clicked,this,&SubWidegt::SendSlot);
    this->resize(400,300);

}
void SubWidegt::SendSlot(){
    emit MySignal();
}
