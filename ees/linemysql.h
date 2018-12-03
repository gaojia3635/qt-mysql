#ifndef LINEMYSQL_H
#define LINEMYSQL_H
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlDatabase>

class linemysql
{
public:
    linemysql();
public:
    static QString usename;
    static QString password;
    static QString position;
    static int a;
};

#endif // LINEMYSQL_H
