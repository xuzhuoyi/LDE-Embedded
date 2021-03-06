#ifndef HOMESTATUS_H
#define HOMESTATUS_H

#include <QWidget>

namespace Ui {
class HomeStatus;
}

class HomeStatus : public QWidget
{
    Q_OBJECT

public:
    explicit HomeStatus(QWidget *parent = 0);
    ~HomeStatus();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HomeStatus *ui;
};

#endif // HOMESTATUS_H
