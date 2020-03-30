#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_clearReceivedButton_clicked();

    void on_cleaSentButton_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;

    void closeEvent(QCloseEvent *event);
};
#endif // WIDGET_H
