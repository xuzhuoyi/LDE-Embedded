#include <QApplication>
#include <form.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Form form;
    form.setWindowFlags(Qt::FramelessWindowHint);
    form.show();


    return app.exec();
}
