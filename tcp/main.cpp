#include "widget.h"

#include <QApplication>
#include<clientwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Server：8888");
    w.show();
    ClientWidget w2;
    w2.setWindowTitle("Client");
    w2.show();
    return a.exec();
}
