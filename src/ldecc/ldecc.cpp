#include "ldecc.h"
#include "ui_ldecc.h"

ldecc::ldecc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ldecc)
{
    ui->setupUi(this);

    connect(&g, SIGNAL(back()), this, SLOT(showFullScreen()));
    connect(&l, SIGNAL(back()), this, SLOT(showFullScreen()));
    connect(&s, SIGNAL(back()), this, SLOT(showFullScreen()));
    connect(&d, SIGNAL(back()), this, SLOT(showFullScreen()));
}

ldecc::~ldecc()
{
    delete ui;
}

void ldecc::on_pushButton_clicked()
{
    qApp->quit();
}

void ldecc::on_toolButton_clicked()
{
    g.show();
    g.showFullScreen();
    this->hide();

}

void ldecc::on_toolButton_2_clicked()
{
    l.show();
    l.showFullScreen();
    this->hide();
}

void ldecc::on_toolButton_10_clicked()
{
    qApp->aboutQt();
}

void ldecc::on_toolButton_9_clicked()
{

}

void ldecc::on_toolButton_3_clicked()
{
    s.show();
    s.showFullScreen();
    this->hide();
}

void ldecc::on_toolButton_11_clicked()
{
    d.show();
    d.showFullScreen();
    this->hide();
}
