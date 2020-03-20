#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MWidget; }
QT_END_NAMESPACE

class MWidget : public QWidget
{
    Q_OBJECT

public:
    MWidget(QWidget *parent = nullptr);
    ~MWidget();

private:
    Ui::MWidget *ui;
    int timeID1;
    int timeID2;


protected:
    void keyPressEvent(QKeyEvent *ev);
    void timerEvent(QTimerEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void closeEvent(QCloseEvent *event);
    bool event(QEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
};
#endif // MWIDGET_H
