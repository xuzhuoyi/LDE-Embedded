#include "form.h"
#include "ui_form.h"
#include <QDateTime>
#include <qwt_point_data.h>
#include <qwt_plot_curve.h>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->labelInfo1->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfo2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfo3->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfo4->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfo5->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfo6->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfo1->setAlignment(Qt::AlignCenter);
    ui->labelInfo2->setAlignment(Qt::AlignCenter);
    ui->labelInfo3->setAlignment(Qt::AlignCenter);
    ui->labelInfo4->setAlignment(Qt::AlignCenter);
    ui->labelInfo5->setAlignment(Qt::AlignCenter);
    ui->labelInfo6->setAlignment(Qt::AlignCenter);
    ui->labelInfoIcon1->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfoIcon2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfoIcon3->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfoIcon4->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfoIcon5->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->labelInfoIcon6->setAttribute(Qt::WA_TranslucentBackground, true);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(ontimeout()));
    timer->start(1000);
    QVector<double> xs;
        QVector<double> ys;
        for (double x = 0; x < 2.0 * M_PI; x+=(M_PI / 10.0))
        {
            xs.append(x);
            ys.append(qSin(x));
        }
        curve.attach(ui->qwtPlot);//把曲线附加到plot上
            curve.setSamples(xs,ys);
            curve.setStyle(QwtPlotCurve::Lines);//设置曲线上是点还是线，默认是线，所以此行可不加
            curve.setCurveAttribute(QwtPlotCurve::Fitted, true);//使曲线更光滑，不加这句曲线会很硬朗，有折点
            curve.setPen(QPen(Qt::blue));//设置画笔


}

Form::~Form()
{
    delete ui;
}

void Form::ontimeout()
{
    ui->label_2->setText([=]
    {
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
        return current_date;
    }());

}

void Form::on_pushButton_3_clicked()
{
    qApp->quit();
}
