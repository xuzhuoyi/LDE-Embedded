#include "form.h"
#include "ui_form.h"
#include <QProcess>

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
    ui->label_21->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_22->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_23->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_3->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_2->setVisible(true);
    ui->frame_3->setVisible(false);
    //ui->frame_4->setVisible(false);
}

Form::~Form()
{
    delete ui;
}

void Form::on_label_clicked()
{

}

void Form::on_label_2_clicked()
{
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(true);
}

void Form::on_label_6_clicked()
{
    ui->frame_3->setVisible(false);
    ui->frame_2->setVisible(true);
}

void Form::on_pushButton_clicked()
{
    qApp->quit();
}

void Form::on_label_23_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./ldeabout",NULL);
}

void Form::on_label_21_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./ldecc",NULL);
}

void Form::on_label_22_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./loogout",NULL);
}
