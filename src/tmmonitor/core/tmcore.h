#ifndef TMCORE_H
#define TMCORE_H

#include <QObject>

class TmCore : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString temp READ temp)
    Q_PROPERTY(QString humi READ humi)

public:
    explicit TmCore(QObject *parent = 0);
    ~TmCore();

    QString temp() const;
    QString humi() const;

    Q_INVOKABLE void setTemp();
    Q_INVOKABLE void setHumi();


signals:

public slots:



private:
    QString getdata();
    QString gettemp(QString str);
    QString gethumi(QString str);

    QString qs_temp;
    QString qs_humi;
};

#endif // TMCORE_H
