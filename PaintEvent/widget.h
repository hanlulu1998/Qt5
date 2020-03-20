#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    int x_foot;
protected:
    //绘图事件会自动调用，只要窗口状态改变
    //在窗口绘图必须在绘图事件中
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
};
#endif // WIDGET_H
