#include "customerqlabel.h"

CustomerQLabel::CustomerQLabel(QWidget *parent, Qt::WindowFlags f):
    QLabel(parent,f)
{

}

CustomerQLabel::CustomerQLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    QLabel(text,parent,f)
{

}

void CustomerQLabel::mouseReleaseEvent(QMouseEvent * ev)
{
    Q_UNUSED(ev)
    emit clicked();
}

CustomerQLabel::~CustomerQLabel()
{

}

