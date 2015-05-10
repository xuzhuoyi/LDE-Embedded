#include "preference.h"
#include "ui_preference.h"
#include <QPropertyAnimation>

Preference::Preference(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
     animation->setDuration(3000);
     animation->setStartValue(0);
     animation->setEndValue(1);
     animation->start();
}

Preference::~Preference()
{
    delete ui;
}

void Preference::on_pushButton_clicked()
{
   this->hide();
}

void Preference::on_pushButton_2_clicked()
{
    this->hide();
}
