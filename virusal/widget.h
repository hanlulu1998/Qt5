#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlTableModel>
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
    void on_AddpushButton_clicked();

    void on_OKpushButton_clicked();

    void on_CancelpushButton_clicked();

    void on_DeletepushButton_clicked();

    void on_FindpushButton_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *mod;
};
#endif // WIDGET_H
