#include "tmcore.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <iostream>

TmCore::TmCore(QObject *parent) : QObject(parent)
{

}

TmCore::~TmCore()
{

}

QString TmCore::getdata()
{
    QFile f("tmdata");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       // std::cout << "Open failed." << endl;
        return "N/A N/A";
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
    return strlist.at(0);
}

QString TmCore::gethumi(QString str)
{
    QStringList strlist=str.split(" ");
    return strlist.at(1);
}

QString TmCore::temp() const
{
    return qs_temp;
}

void TmCore::setTemp()
{
    qs_temp = gettemp(getdata());
}

QString TmCore::humi() const
{
    return qs_humi;
}

void TmCore::setHumi()
{
    qs_humi = gethumi(getdata());
}

QString TmCore::hitm() const
{
    return qs_hitm;
}



