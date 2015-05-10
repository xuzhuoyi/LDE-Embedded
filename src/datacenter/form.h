#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QTimer>
#include <qwt_plot_curve.h>
#include "preference.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

public slots:
    void ontimeout();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Form *ui;
    Preference reference;
    QTimer *timer;
    QwtPlotCurve curve;
    QVector<double> xs;
    QVector<double> ys;

protected:

   void timerEvent( QTimerEvent *event );
};

#endif // FORM_H
