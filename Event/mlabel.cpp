#include "mlabel.h"
#include<QMouseEvent>
#include <QDebug>
MLabel::MLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标跟踪
    this->setMouseTracking(true);

}
void MLabel::mousePressEvent(QMouseEvent *ev){
    int x=ev->x();
    int y=ev->y();
    if (ev->button()==Qt::RightButton){
        qDebug()<<"Right";

    }
    else if (ev->button()==Qt::LeftButton) {
        qDebug()<<"Left";
    }
    else if(ev->button()==Qt::MidButton) {
        qDebug()<<"Mid";
    }
    QString str=QString("<center><h>Mouse Pressed:"
                        "(%1,%2)</h></center>").arg(x).arg(y);
    this->setText(str);

}
void MLabel::mouseMoveEvent(QMouseEvent *ev){
    int x=ev->globalX();
    int y=ev->globalY();
    if (ev->button()==Qt::RightButton){
        qDebug()<<"Right";

    }
    else if (ev->button()==Qt::LeftButton) {
        qDebug()<<"Left";
    }
    else if(ev->button()==Qt::MidButton) {
        qDebug()<<"Mid";
    }
    QString str=QString("<center><h>Mouse Move:"
                        "(%1,%2)</h></center>").arg(x).arg(y);
    this->setText(str);



}
void MLabel::mouseReleaseEvent(QMouseEvent *ev){
    int x=ev->x();
    int y=ev->y();
    if (ev->button()==Qt::RightButton){
        qDebug()<<"Right";

    }
    else if (ev->button()==Qt::LeftButton) {
        qDebug()<<"Left";
    }
    else if(ev->button()==Qt::MidButton) {
        qDebug()<<"Mid";
    }
    QString str=QString("<center><h>Mouse Release:"
                        "(%1,%2)</h></center>").arg(x).arg(y);
    this->setText(str);


}

