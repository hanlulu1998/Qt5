#ifndef SUBWIDEGT_H
#define SUBWIDEGT_H

#include <QWidget>
#include <QPushButton>

class SubWidegt : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidegt(QWidget *parent = nullptr);
    void SendSlot();
signals:
    void MySignal();

public slots:
private:
    QPushButton b;
};

#endif // SUBWIDEGT_H
