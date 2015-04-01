#ifndef TMCORE_H
#define TMCORE_H

#include <QObject>

class TmCore : public QObject
{
    Q_OBJECT
public:
    explicit TmCore(QObject *parent = 0);
    ~TmCore();



signals:

public slots:
    QString getdata();
    QString gettemp(QString str);
    QString gethumi(QString str);
};

#endif // TMCORE_H
