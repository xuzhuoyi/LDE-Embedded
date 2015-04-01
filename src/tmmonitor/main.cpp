#include <QApplication>
#include <QQmlApplicationEngine>
#include "core/tmcore.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<TmCore>("LDE.Tmmonitor.TmCore", 0, 1, "TmCore");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
