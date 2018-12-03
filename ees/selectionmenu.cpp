#include "selectionmenu.h"
#include "ui_selectionmenu.h"
#include "operatinginterface.h"
#include "yonhuzhuce.h"
#include "mainwindow.h"

Selectionmenu::Selectionmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selectionmenu)
{
    ui->setupUi(this);
}

Selectionmenu::~Selectionmenu()
{
    delete ui;
}

void Selectionmenu::on_zhuce_clicked()
{
    this->hide();
    yonhuzhuce *wq1=new yonhuzhuce;
    wq1->show();
}

void Selectionmenu::on_zhuxiao_clicked()
{
    this->hide();
    MainWindow *wq2=new MainWindow;
    wq2->show();
}

void Selectionmenu::on_caozuo_clicked()
{
    this->hide();
    operatinginterface *wq=new operatinginterface;
    wq->show();
}

