#ifndef OPERATINGINTERFACE_H
#define OPERATINGINTERFACE_H

#include <QDialog>

namespace Ui {
class operatinginterface;
}

class operatinginterface : public QDialog
{
    Q_OBJECT

public:
    explicit operatinginterface(QWidget *parent = 0);
    ~operatinginterface();

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_do_2_clicked();

private:
    Ui::operatinginterface *ui;
};

#endif // OPERATINGINTERFACE_H
