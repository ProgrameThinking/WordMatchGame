/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 10:54:43
 * @LastEditTime: 2023-05-09 16:40:51
 * @Description: 
 */

#include "dbutil.h"

dbUtil::dbUtil()
{
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);
    if(dbconn.open())
        qDebug("database open successfully!");
    else
        qDebug("database open failed!");
}

void dbUtil::close()
{
    dbconn.close();
}

QString dbUtil::playerLogin(QString uname,QString pwd)
{
    QSqlQuery query(dbconn);
    query.prepare("select * from player where uname = ? and pwd= ? and isOnline=0");
    query.bindValue(0, uname);
    query.bindValue(1, pwd);
    QString res="";
    //qDebug()<<"player login sql:"<<sql;
    query.exec();
    query.next();
    if(query.value("uname").toString()!=nullptr)
    {
        res+="1 ";
        /*get all player infomation*/
        res+=query.value("uname").toString()+" ";
        res+=query.value("pwd").toString()+" ";
        res+=query.value("exp").toString()+" ";
        res+=query.value("ranker").toString()+" ";
        res+=query.value("passNum").toString()+" ";
        /*update player online state*/
        query.prepare("update player set isOnline=1 where uname =? and pwd = ?");
        query.bindValue(0, uname);
        query.bindValue(1, pwd);
        query.exec();
        return res;
    }
    else
        return "0";
}
QString dbUtil::testerLogin(QString uname,QString pwd)
{
    QSqlQuery query(dbconn);
    query.prepare("select * from tester where uname = ? and pwd= ? and isOnline= 0");
    query.bindValue(0, uname);
    query.bindValue(1, pwd);
    QString res="";
    //qDebug()<<"tester login sql:"<<sql;
    query.exec();
    query.next();
    if(query.value("uname").toString()!=nullptr)
    {
         res+="1 ";
        /*get all player infomation*/
        res+=query.value("uname").toString()+" ";
        res+=query.value("pwd").toString()+" ";
        res+=query.value("exp").toString()+" ";
        res+=query.value("ranker").toString()+" ";
        res+=query.value("quesCreatedNum").toString()+" ";
        /*update tester online state*/
        query.prepare("update tester set isOnline=1 where uname =? and pwd = ?");
        query.bindValue(0, uname);
        query.bindValue(1, pwd);
        query.exec();
        return res;
    }
    else
        return "0";
}