/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 10:54:43
 * @LastEditTime: 2023-05-10 23:51:12
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
        QString playerRegiste(QString uname,QString pwd);
        QString testerRegiste(QString uname,QString pwd);
        QString playerLogin(QString uname,QString pwd);
        QString testerLogin(QString uname,QString pwd);
        QString allPlayerInfo();        //get all player info
        QString allTesterInfo();        //get all tester info
        QString allSearchUname(int type,QString uname); //according to username and usertype
        QString allSearchNum(int type,int number);      //according to passNum or questionCreatedNum and usertype
        QString allSearchRank(int type,int rank);       //according to rank and usertype
        QString allSortByNum(int type);                 //according usertype
        QString allSortByRank(int type);                //according usertype
        void playerLogout(QString uname);
        void testerLogout(QString uname);
        bool addWord(QString word,int difficult);
        void testerInfoUpdate(int exp,int rank,int quesCreatedNum,QString name);
        void playerInfoUpdate(int exp,int rank,int quesCreatedNum,QString name);
        QString getSignalGameWord(int rank);
    private:
        QString hostName="localhost";
        QString dbName="wordMatchGame";
        QString userName="root";
        QString password="wenbo030605";
        QSqlDatabase dbconn;

};

#endif // DBUTIL_H
