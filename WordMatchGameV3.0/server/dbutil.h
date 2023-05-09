/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 10:54:43
 * @LastEditTime: 2023-05-09 22:57:23
 * @Description: Provide initialize and execute sql methods for database.
 */

#ifndef DBUTIL_H
#define DBUTIL_H


#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


class dbUtil : public QObject
{
    Q_OBJECT
    public:
        /*constructor*/
        dbUtil();
        void close();
        /*public method*/
        QString playerLogin(QString uname,QString pwd);
        QString testerLogin(QString uname,QString pwd);
        void playerLogout(QString uname);
        void testerLogout(QString uname);
        bool addWord(QString word,int difficult);
        void testerInfoUpdate(int exp,int rank,int quesCreatedNum,QString name);
    private:
        QString hostName="localhost";
        QString dbName="wordMatchGame";
        QString userName="root";
        QString password="wenbo030605";
        QSqlDatabase dbconn;

};

#endif // DBUTIL_H
