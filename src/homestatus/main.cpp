#include "homestatus.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeStatus w;
    w.show();
    w.showFullScreen();

    return a.exec();
}
