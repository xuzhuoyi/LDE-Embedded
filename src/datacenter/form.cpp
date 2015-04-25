#include "form.h"
#include "ui_form.h"
#include <QDateTime>

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
