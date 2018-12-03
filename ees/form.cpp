#include "form.h"
#include "ui_form.h"
#include <QSqlDatabase>
#include "mainwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db=QSqlDatabase::addDatabase("QMYSQL");
    /*
     *      QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db=QSqlDatabase::addDatabase("QMYSQL");
    在新的qt版本中如果不是用使用上面的一段话会报错。
    另外需要在安装的时候在qt库中加入mysql驱动程序，可以依据自己的系统百度libqsqlmysql.os
*/
    db.setHostName("10.42.0.123"); //数据库服务器地址，我这里使用的是虚拟机建的数据库服务器，实际中可以使用本地数据库服务器地址
    db.setDatabaseName("ees");//数据库名称，这里是你数据库服务器中的数据库，一定要自己建一个，别问我怎么知道的
    db.setPort(8000);//数据库服务器的端口，一般不用写，如果你数据库是在另一个服务器上的话建议写上，因为你服务器端口开放哪个只有自己知道
    db.setUserName("root");//数据库用户名，在数据库中可以自己建一个用户，权限看自己怎么设定
    db.setPassword("Qwe12345!");//数据库密码，没有密码的话""
    if(db.open())//打开数据库
        ui->label->setText("数据库连接成功");//settext的字打印在label标签中，会覆盖原来标签上的字
    else
        ui->label->setText("数据库连接失败");
}

void Form::on_pushButton_2_clicked()
{
    this->hide();
    MainWindow *a=new MainWindow;
    a->show();
}
