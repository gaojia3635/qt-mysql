#include "linemysql.h"
#include <QSqlDatabase>
#include <QtDebug>

QString linemysql::usename;
QString linemysql::password;
QString linemysql::position;
int linemysql::a=1;

linemysql::linemysql()
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
    if(db.open())
    {
        qDebug() <<"数据库打开成功"<<endl;}
    else
    {qDebug()  << "数据库连接失败"<<endl;
    }
}
