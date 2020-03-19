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

private slots:
    void on_ExitButton_clicked();

    void on_StartButton_clicked();
    void DealNum();

    void on_pushButton_sug_clicked();
    void on_pushButton_del_clicked();

    void on_pushButton_ag_clicked();

    void on_pushButton_menu_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_rest_clicked();

private:
    Ui::Widget *ui;
    int timeID;
    int OverTime;
    int caitime;
    int totaltime;
    QString resultStr;
    QString resulthistory;
    QString randstr;
    QString GenRand();
    int time;
protected:
    void timerEvent(QTimerEvent *ev);
    void closeEvent(QCloseEvent *event);
};
#endif // WIDGET_H
