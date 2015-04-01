#include "tmcore.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

TmCore::TmCore(QObject *parent) : QObject(parent)
{

}

TmCore::~TmCore()
{

}

QString TmCore::getdata()
{
    QFile f("test.txt");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Open failed." << endl;
        return -1;
    }

    QTextStream txtInput(&f);
    QString lineStr;
    while(!txtInput.atEnd())
        lineStr = txtInput.readLine();

    f.close();
    return lineStr;
}

QString TmCore::gettemp(QString str)
{
    QStringList strlist=str.split(" ");
    return str.at(0);
}

QString TmCore::gethumi(QString str)
{
    QStringList strlist=str.split(" ");
    return str.at(1);
}



