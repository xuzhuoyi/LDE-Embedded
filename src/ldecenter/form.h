#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_label_clicked();

    void on_label_2_clicked();

    void on_label_6_clicked();

    void on_pushButton_clicked();

    void on_label_23_clicked();

    void on_label_21_clicked();

    void on_label_22_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
