#include <QApplication>
#include "ldecc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ldecc w;
    w.show();
    w.showFullScreen();
    
    return a.exec();
}
