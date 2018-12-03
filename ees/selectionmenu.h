#ifndef SELECTIONMENU_H
#define SELECTIONMENU_H

#include <QDialog>

namespace Ui {
class Selectionmenu;
}

class Selectionmenu : public QDialog
{
    Q_OBJECT

public:
    explicit Selectionmenu(QWidget *parent = 0);
    ~Selectionmenu();

private slots:

    void on_zhuce_clicked();

    void on_zhuxiao_clicked();

    void on_caozuo_clicked();

    void on_back_clicked();

private:
    Ui::Selectionmenu *ui;
};

#endif // SELECTIONMENU_H
