#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
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
    ui->label_19->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_20->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_2->setVisible(true);
    ui->frame_3->setVisible(false);
    //ui->frame_4->setVisible(false);
}

Form::~Form()
{
    delete ui;
}
