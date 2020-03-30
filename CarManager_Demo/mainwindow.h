#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlError>
#include"domxml.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectDB();
    void initialDB();

private slots:
    void on_actionCar_triggered();

    void on_actionCalc_triggered();

    void on_factorycomboBox_currentIndexChanged(const QString &arg1);

    void on_brandcomboBox_currentIndexChanged(const QString &arg1);

    void on_numspinBox_valueChanged(int arg1);

    void on_cancelpushButton_clicked();

    void on_OKpushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
