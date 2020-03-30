#include "painterthread.h"
#include<QPainter>
#include<QPen>
#include<QBrush>
painterThread::painterThread(QObject *parent) : QObject(parent)
{

}
void painterThread::drawImge(){
    QImage imge(500,500,QImage::Format_ARGB32);

    QPainter p(&imge);
    QPen pen;
    pen.setWidth(5);
    p.setPen(pen);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    pen.setBrush(brush);

    QPoint a[]={
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500)

    };

    p.drawPolygon(a,5);

    emit updateImge(imge);
}
