#include "form.h"
#include "ui_form.h"
#include "core/tmcore.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->labelTemp->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    ui->labelHumi->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    getInfo();
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    qApp->quit();
}

void Form::getInfo()
{
    ui->labelTemp->setText([=]
    {
        TmCore tmCore;
        tmCore.setTemp();
        return tmCore.temp();
    }());
    ui->labelHumi->setText([=]
    {
        TmCore tmCore;
        tmCore.setHumi();
        QString h QString::number((int)tmCore.humi().toDouble());
        return h;
    }());
}
