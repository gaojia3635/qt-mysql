#include "yonghuzhuce.h"
#include "ui_yonghuzhuce.h"

yonghuzhuce::yonghuzhuce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yonghuzhuce)
{
    ui->setupUi(this);
}

yonghuzhuce::~yonghuzhuce()
{
    delete ui;
}
