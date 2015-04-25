#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
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
    ui->label->setText("<html><head/><body><p><span style=\" font-style:italic;\">DataCenter LDE 数据1监测系统</span></p></body></html>");
}
