#include "operatinginterface.h"
#include "ui_operatinginterface.h"
#include "selectionmenu.h"
#include "mainwindow.h"
#include "yonhuzhuce.h"

int T1;
int T2;
int i=0;

operatinginterface::operatinginterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operatinginterface)
{
    ui->setupUi(this);
}

operatinginterface::~operatinginterface()
{
    delete ui;
}


void operatinginterface::on_pushButton_4_clicked()
{
    this->hide();
    yonhuzhuce *qw=new yonhuzhuce;
    qw->show();
}

void operatinginterface::on_pushButton_2_clicked()
{
    this->hide();
    MainWindow *wq=new MainWindow;
    wq->show();
}

void operatinginterface::on_pushButton_clicked()
{
    QString use;
    QString pas;
    QString pos="用户";
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
    query.exec("SELECT * FROM admin");
       while(query.next())
      {
         QString usename =query.value(1).toString().trimmed();//trimmed函数表示去除QString两边的空格
         QString password=query.value(2).toString().trimmed();
         QString position=query.value(3).toString().trimmed();//从数据库返回的值付给用qstring设定的变量，value（这里是数据库中对应的行序号）
         use=usename;
         pas=password;
         /*qDebug() << usename
                  << ui->usernameEdit->text()
                  << password
                  << ui->passwordEdit->text()
                  << position
                  << pos1;
          测试中可以使用debug查看服务器返回的数值和输入框的数值，方便修改数据库或者代码
*/
         if(use == ui->czus->text() && pas == ui->czps->text() && pos == position)
         {
             QMessageBox::warning(NULL,"","帐号密码正确");
             T1=1;
             ui->xztext->setText("操作员验证成功");
             goto a;
         }
      }
      QMessageBox::warning(NULL,"","帐号密码错误");
      a:ui->czus->clear();
        ui->czps->clear();
}

void operatinginterface::on_pushButton_3_clicked()
{
    QString use;
    QString pas;
    QString pos2="监管";
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
    query.exec("SELECT * FROM admin");
       while(query.next())
      {
         QString usename =query.value(1).toString().trimmed();//trimmed函数表示去除QString两边的空格
         QString password=query.value(2).toString().trimmed();
         QString position=query.value(3).toString().trimmed();//从数据库返回的值付给用qstring设定的变量，value（这里是数据库中对应的行序号）
         use=usename;
         pas=password;
         /*qDebug() << usename
                  << ui->usernameEdit->text()
                  << password
                  << ui->passwordEdit->text()
                  << position
                  << pos1;
          测试中可以使用debug查看服务器返回的数值和输入框的数值，方便修改数据库或者代码
*/
         if(use == ui->jgus->text() && pas == ui->jgps->text() && pos2 == position)
         {
             QMessageBox::warning(NULL,"","帐号密码正确");
             T2=1;
             ui->jgtext->setText("监管员验证成功");
             goto b;
         }
      }
      QMessageBox::warning(NULL,"","帐号密码错误");
      b:ui->jgus->clear();
        ui->jgps->clear();
}

void operatinginterface::on_do_2_clicked()
{
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
        query.exec("SELECT * FROM task");
        QString pos=query.value(1).toString();
    if(T1==1 && T2==1 && i==0)
    {
        if(ui->radioButton->isChecked())
        {
            query.exec("update `task`set `kind`='1' where `task`='p1'");
            ui->progressBar->setValue(1);
            T1=0;
            T2=0;
            i=1;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_2->isChecked())
        {
            query.exec("update `task`set `kind`='1' where `task`='p2'");
            ui->progressBar->setValue(1);
            T1=0;
            T2=0;
            i=1;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_3->isChecked())
        {
            query.exec("update `task`set `kind`='1' where `task`='p3'");
            ui->progressBar->setValue(1);
            T1=0;
            T2=0;
            i=1;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
    }
    else if(T1==1 && T2==1 && i==1)
    {
        if(ui->radioButton->isChecked())
        {
            query.exec("update `task`set `kind`='2' where `task`='p1'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=2;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_2->isChecked())
        {
            query.exec("update `task`set `kind`='2' where `task`='p2'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=2;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_3->isChecked())
        {
            query.exec("update `task`set `kind`='2' where `task`='p3'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=2;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
    }
    else if (T1==1 && T2==1 && i==2) {
        if(ui->radioButton->isChecked())
        {
            query.exec("update `task`set `kind`='3' where `task`='p1'");
            ui->progressBar->setValue(3);
            T1=0;
            T2=0;
            i=3;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_2->isChecked())
        {
            query.exec("update `task`set `kind`='3' where `task`='p2'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=3;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_2->isChecked())
        {
            query.exec("update `task`set `kind`='3' where `task`='p3'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=3;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
    }
    else if (T1==1 && T2==1 && i==3) {
        if(ui->radioButton->isChecked())
        {
            query.exec("update `task`set `kind`='4' where `task`='p1'");
            ui->progressBar->setValue(4);
            T1=0;
            T2=0;
            i=4;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_2->isChecked())
        {
            query.exec("update `task`set `kind`='4' where `task`='p2'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=4;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
        else if(ui->radioButton_2->isChecked())
        {
            query.exec("update `task`set `kind`='4' where `task`='p3'");
            ui->progressBar->setValue(2);
            T1=0;
            T2=0;
            i=4;
            ui->xztext->clear();
            ui->jgtext->clear();
        }
    }
    else {
        QMessageBox::warning(NULL,"","票据执行失败");
    }
}
