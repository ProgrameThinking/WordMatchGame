
#ifndef DBUTIL_H
#define DBUTIL_H


#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


class dbUtil : public QObject
{
    Q_OBJECT
    public:
        /*constructor*/
        dbUtil();
    private:
        QString hostName="localhost";
        QString dbName="wordMatchGame";
        QString userName="root";
        QString password="wenbo030605";
        QSqlDatabase dbconn;

};

#endif // DBUTIL_H
