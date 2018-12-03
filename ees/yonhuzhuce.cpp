#include "yonhuzhuce.h"
#include "ui_yonhuzhuce.h"
#include <QSqlDatabase>
#include <QtDebug>
#include "mainwindow.h"
#include "selectionmenu.h"


QString usenamezc;
QString passwordzc;
QString pos1;

yonhuzhuce::yonhuzhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yonhuzhuce)
{
    ui->setupUi(this);
}

yonhuzhuce::~yonhuzhuce()
{
        delete ui;

}

void yonhuzhuce::on_doit_clicked()
{
    QString usenamezc=ui->usernamezc->text();
    QString passwordzc=ui->passwordzc->text();
    QString pos1=ui->comboBox->currentText();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("10.42.0.123");
    db.setDatabaseName("ees");
    db.setPort(8000);
    db.setUserName("root");
    db.setPassword("Qwe12345!");
    db.open();
    QSqlQuery query(db);
    QString sql;
    query.exec("SELECT * FROM admin");
    sql = QString("insert into admin(username,password,position)"  "VALUES('%1','%2','%3')")
            .arg(usenamezc).arg(passwordzc).arg(pos1);
    bool ok = query.exec(sql);
   if(ok)
   {

    QMessageBox::information(this ,tr("提示") , tr("注册成功!"));
  }
  else
  {
    QMessageBox::information(this ,tr("提示") , tr("注册失败!"));
  }
   ui->passwordzc->clear();
   ui->usernamezc->clear();
}

void yonhuzhuce::on_back_clicked()
{
    this->hide();
    Selectionmenu *qw=new Selectionmenu;
    qw->show();
}
