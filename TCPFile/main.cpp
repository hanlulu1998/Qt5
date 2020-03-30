#include "widget.h"
#include<clientwidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Server:8888");
    w.show();
    clientWidget w2;
    w2.show();
    return a.exec();
}
