#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include<QTcpSocket>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_connectButton_clicked();

    void on_sentButton_clicked();

    void on_disconnectButton_clicked();

    void on_sentButton_2_clicked();

    void on_sentButton_3_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpsocket;
};

#endif // CLIENTWIDGET_H
