#include "homestatus.h"
#include "ui_homestatus.h"
#include <qwt_color_map.h>

HomeStatus::HomeStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeStatus)
{
    ui->setupUi(this);



#if 1
    QwtLinearColorMap *colorMap =
    new QwtLinearColorMap( Qt::blue, Qt::red );
    colorMap->addColorStop( 0.2, Qt::cyan );
    colorMap->addColorStop( 0.4, Qt::green );
    colorMap->addColorStop( 0.6, Qt::yellow );
    colorMap->addColorStop( 0.8, Qt::magenta );
    colorMap->setMode( QwtLinearColorMap::ScaledColors );
    ui->Thermo->setColorMap( colorMap );
#endif
    QwtLinearColorMap *colorMap2 =
    new QwtLinearColorMap( Qt::black, Qt::lightGray );
    colorMap2->addColorStop( 0.3, Qt::darkGray );
    colorMap2->addColorStop( 0.6, Qt::gray );

    colorMap2->setMode( QwtLinearColorMap::ScaledColors );
    ui->Thermo_2->setColorMap( colorMap2 );

}

HomeStatus::~HomeStatus()
{
    delete ui;
}
