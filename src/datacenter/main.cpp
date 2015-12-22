#include "form.h"
#include <QApplication>
#include <QProcess>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w;
    w.show();
    w.showFullScreen();

    QProcess *mainProcess = new QProcess;
    QStringList runArgsList;
    runArgsList << "0314668945ff";
    mainProcess->start("./ds18b20_test", runArgsList);


    return a.exec();
}
