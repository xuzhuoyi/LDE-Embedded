#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    void setLabelTrans();

protected:

   void timerEvent( QTimerEvent *event );

private slots:
   void on_label_16_clicked();
};

#endif // WIDGET_H
