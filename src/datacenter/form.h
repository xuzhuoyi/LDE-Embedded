#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

public slots:
    void ontimeout();
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Form *ui;
    QTimer *timer;
};

#endif // FORM_H
