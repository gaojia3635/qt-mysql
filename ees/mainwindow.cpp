#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectionmenu.h"
#include "QMessageBox"
#include "operatinginterface.h"
#include <QtDebug>
#include "form.h"
#include "linemysql.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString use;
    QString pas;
    QString pos;
    QString pos1;

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
         pos=position;
         pos1= ui->comboBox->currentText();//currentText返回选择的文本，这里要注意的是如果使用currentindex返回的值不是纯粹的0或者1，而是/u0000,/u0001。
         //在数据库中enum数据类型中无法储存“/”，但是可以储存中文
         /*qDebug() << usename
                  << ui->usernameEdit->text()
                  << password
                  << ui->passwordEdit->text()
                  << position
                  << pos1;
          测试中可以使用debug查看服务器返回的数值和输入框的数值，方便修改数据库或者代码
*/
         if(use == ui->usernameEdit->text() && pas == ui->passwordEdit->text() && pos == pos1)
         {
             QMessageBox::warning(NULL,"","帐号密码正确");
             this->hide();
             Selectionmenu *qw=new Selectionmenu;
             qw->show();
             goto a;
         }
      }
      QMessageBox::warning(NULL,"","帐号密码错误");
      a:ui->usernameEdit->clear();
        ui->passwordEdit->clear();
}


void MainWindow::on_close_2_clicked()
{
    this->hide();
    Form *zx=new Form;
    zx->show();
}

