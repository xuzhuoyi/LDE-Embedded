#ifndef TMCORE_H
#define TMCORE_H

#include <QObject>

class TmCore : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString temp READ temp)
public:
    explicit TmCore(QObject *parent = 0);
    ~TmCore();
    QString temp() const;
    Q_INVOKABLE void setTemp();



signals:

public slots:
    QString getdata();
    QString gettemp(QString str);
    QString gethumi(QString str);
    QString gette();
    QString gethu();

private:
    QString qs_temp;
};

#endif // TMCORE_H
