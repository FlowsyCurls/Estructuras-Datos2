#include "util.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    Util util;
    util.runServer();

    return a.exec();
}
