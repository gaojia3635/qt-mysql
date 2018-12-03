#ifndef YONHUZHUCE_H
#define YONHUZHUCE_H

#include <QWidget>

namespace Ui {
class yonhuzhuce;
}

class yonhuzhuce : public QWidget
{
    Q_OBJECT

public:
    explicit yonhuzhuce(QWidget *parent = 0);
    ~yonhuzhuce();

private slots:
    void on_doit_clicked();

    void on_back_clicked();

private:
    Ui::yonhuzhuce *ui;
};

#endif // YONHUZHUCE_H
