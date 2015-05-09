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
    ui->label_24->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_25->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_26->setAttribute(Qt::WA_TranslucentBackground, true);

    ui->label_28->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_29->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_30->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->label_31->setAttribute(Qt::WA_TranslucentBackground, true);

    ui->frame_2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_3->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_4->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
    ui->frame_4->setVisible(true);
    ui->label_4->setVisible(false);
    ui->label_13->setVisible(false);
}

Form::~Form()
{
    delete ui;
}

void Form::on_label_clicked()
{
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
    ui->frame_4->setVisible(true);
}

void Form::on_label_2_clicked()
{
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(true);
    ui->frame_4->setVisible(false);
}

void Form::on_label_6_clicked()
{
    ui->frame_3->setVisible(false);
    ui->frame_2->setVisible(true);
    ui->frame_4->setVisible(false);
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

void Form::on_label_3_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./lcalc",NULL);
}

void Form::on_label_5_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./loofm",NULL);
}

void Form::on_label_7_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./lootepad",NULL);
}

void Form::on_label_11_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./looplorer",NULL);
}

void Form::on_label_24_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./tmmonitor",NULL);
}

void Form::on_label_25_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./datacenter",NULL);
}

void Form::on_label_26_clicked()
{
    QProcess *mainProcess = new QProcess;
    QStringList runArgsList;
    runArgsList << "Main.py";
    mainProcess->start("python2", runArgsList);
}

void Form::on_label_12_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./LWebBoxCon",NULL);
}

void Form::on_label_10_clicked()
{
    QProcess *mainProcess = new QProcess;
    mainProcess->start("./looget",NULL);
}
