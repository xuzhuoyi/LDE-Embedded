#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QWidget>

namespace Ui {
class Preference;
}

class Preference : public QWidget
{
    Q_OBJECT

public:
    explicit Preference(QWidget *parent = 0);
    ~Preference();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Preference *ui;
};

#endif // PREFERENCE_H
