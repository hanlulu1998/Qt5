#include <QApplication>
# include <QWidget>
# include <QPushButton>
int main(int argc, char **argv){
    QApplication app(argc,argv);
    QWidget w;
    w.setWindowTitle(QString("第一个程序"));

    QPushButton q1,q2,q3(&w);
    q1.setText(QString("第一个按钮"));
    q1.show();
    // 对子对象设置父对象，使得子窗口在父窗口上
    // 方法一：使用setParent
    q2.setParent(& w);
    q2.setText(QString("第二个按钮"));
    // 方法二：使用构造函数（）
    q3.setText(QString("第三个按钮"));
    q3.move(200,200);
    w.show();
    app.exec();
    return 0;
}
