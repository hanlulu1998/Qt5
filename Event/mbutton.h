#ifndef MBUTTON_H
#define MBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>

class MButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MButton(QWidget *parent = nullptr);

signals:
protected:
     void mousePressEvent(QMouseEvent *ev);

};

#endif // MBUTTON_H
