#ifndef CUSTOMERQLABEL_H
#define CUSTOMERQLABEL_H

#include <QObject>
#include <QLabel>

class CustomerQLabel : public QLabel
{
    Q_OBJECT

public:

    explicit CustomerQLabel(QWidget *parent=0, Qt::WindowFlags f=0);
    explicit CustomerQLabel(const QString &text, QWidget *parent=0, Qt::WindowFlags f=0);
    ~CustomerQLabel();

protected:

    /*!
      由Qt自己调用的鼠标事件处理函数,在此发射clicked信号
    */
    virtual void mouseReleaseEvent(QMouseEvent * ev);

signals:

    void clicked(void);

};

#endif // CUSTOMERQLABEL_H
