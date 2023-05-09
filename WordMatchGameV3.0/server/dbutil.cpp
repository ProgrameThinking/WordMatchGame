/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 10:54:43
 * @LastEditTime: 2023-05-10 00:08:38
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
    this->deleteLater();
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
        query.finish();
        return res;
    }
    else
    {
        query.finish();
        return "0";
    }
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
        query.finish();
        return res;
    }
    else
    {
        query.finish();
        return "0";
    }
}
void dbUtil::playerLogout(QString uname)
{
    QSqlQuery query(dbconn);
    query.prepare("update player set isOnline=0 where uname =?");
    query.bindValue(0, uname);
    query.exec();
    query.finish();
}
void dbUtil::testerLogout(QString uname)
{
    QSqlQuery query(dbconn);
    query.prepare("update tester set isOnline=0 where uname =?");
    query.bindValue(0, uname);
    query.exec();
    query.finish();
}
bool dbUtil::addWord(QString word,int difficult)
{
    QSqlQuery query(dbconn);
    query.prepare("insert into vocabulary (word, difficulty) values (?,?)");
    query.bindValue(0, word);
    query.bindValue(1, difficult);
    if(query.exec())
    {
        query.finish();
        return true;
    }
    else
    {
        query.finish();
        return false;
    }
}
void dbUtil::testerInfoUpdate(int exp,int rank,int quesCreatedNum,QString name)
{
    QSqlQuery query(dbconn);
    /*update tester's info in database*/
    query.prepare("update tester set exp = ?, ranker = ?, quesCreatedNum = ? where uname = ? ");
    query.bindValue(0, exp);
    query.bindValue(1, rank);
    query.bindValue(2, quesCreatedNum);
    query.bindValue(3, name);
    query.exec();
    query.finish();
}