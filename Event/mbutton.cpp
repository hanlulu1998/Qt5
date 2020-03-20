#include "mbutton.h"
#include<QDebug>
MButton::MButton(QWidget *parent) : QPushButton(parent)
{

}
void MButton::mousePressEvent(QMouseEvent *ev){
    if(ev->button()==Qt::LeftButton){
        //事件传递后就不再进行传递
        qDebug()<<"按下的是左键";
        //事件忽略，继续传递给与父组件
        ev->ignore();
    }
    else {

        QPushButton::mousePressEvent(ev);
    }





}
