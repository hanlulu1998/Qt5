#ifndef MLABEL_H
#define MLABEL_H

#include <QLabel>

class MLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MLabel(QWidget *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

signals:


};

#endif // MLABEL_H
