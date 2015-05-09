#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>
#include <QFile>
#include <QProcess>
#include <QTextStream>
#include <unistd.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setLabelTrans();
    this->startTimer(1000);
    if (isServerRunning())
        ui->label_7->setText("运行");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent( QTimerEvent *)
{
    ui->label_3->setText([=]
        {
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("yyyy-MM-dd");
            return current_date;
        }());
    ui->label_5->setText([=]
        {
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("hh:mm:ss");
            return current_date;
        }());
    ui->label_11->setText([=]
        {
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("ddd");
            return current_date;
        }());
}

void Widget::setLabelTrans()
{
    ui->label->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_3->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_4->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_5->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_6->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_7->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_8->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_9->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_10->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_11->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_12->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_13->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_14->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_15->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_16->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_17->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_18->setAttribute(Qt::WA_TranslucentBackground, true);
}

void Widget::on_label_16_clicked()
{
    QProcess *mainProcess = new QProcess;
    QStringList runArgsList;
    runArgsList << "../../../LWebBox/PiBox/start.sh";
    mainProcess->start("sh", runArgsList);
    sleep(3);
    ui->label_9->setText([=]
    {
        QFile f("../../../LWebBox/PiBox/ip");
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {

        }

        QTextStream txtInput(&f);
        QString lineStr;
        while(!txtInput.atEnd())
            lineStr = txtInput.readLine();

        f.close();
        return lineStr;
    }());
    ui->label_7->setText("运行");
}

void Widget::on_label_17_clicked()
{
    QProcess *mainProcess = new QProcess;
    QStringList runArgsList;
    runArgsList << "../../../LWebBox/PiBox/stop.sh";
    mainProcess->start("sh", runArgsList);
    ui->label_7->setText("停止");
}

bool Widget::isServerRunning()
{
    QFile f("../../../LWebBox/PiBox/ip");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        f.close();
        return false;
    }
    else
    {
        f.close();
        return true;
    }
}

void Widget::on_pushButton_clicked()
{
    exit(0);
}
