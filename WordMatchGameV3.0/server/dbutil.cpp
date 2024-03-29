/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 10:54:43
 * @LastEditTime: 2023-05-11 14:19:28
 * @Description: 
 */

#include "dbutil.h"
#include <QTime>

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

QString dbUtil::allPlayerInfo()
{
    QSqlQuery query(dbconn);
    QString res="";
    query.exec("select * from player");
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}   

QString dbUtil::allTesterInfo()
{
    QSqlQuery query(dbconn);
    QString res="";
    query.exec("select * from tester");
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}

QString dbUtil::allSearchUname(int type,QString uname)
{
    QSqlQuery query(dbconn);
    QString res="";
    if(type==0)
    {
        query.prepare("select * from player where uname = ? ");
        query.bindValue(0, uname);
        query.exec();
    }
    else if(type==1)
    {
        query.prepare("select * from tester where uname = ? ");
        query.bindValue(0, uname);
        query.exec();
    }
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}

QString dbUtil::allSearchNum(int type,int number)
{
    QSqlQuery query(dbconn);
    QString res="";
    if(type==0)
    {
        query.prepare("select * from player where passNum = ? ");
        query.bindValue(0, number);
        query.exec();
    }
    else if(type==1)
    {
        query.prepare("select * from tester where quesCreatedNum = ? ");
        query.bindValue(0, number);
        query.exec();
    }
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}

QString dbUtil::allSearchRank(int type,int rank)
{
    QSqlQuery query(dbconn);
    QString res="";
    if(type==0)
    {
        query.prepare("select * from player where ranker = ? ");
        query.bindValue(0, rank);
        query.exec();
    }
    else if(type==1)
    {
        query.prepare("select * from tester where ranker = ? ");
        query.bindValue(0, rank);
        query.exec();
    }
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}

QString dbUtil::allSortByNum(int type)
{   
    QSqlQuery query(dbconn);
    QString res;
    if(type==0)
        query.exec("select * from player order by passNum desc");
    else if(type==1)
        query.exec("select * from tester order by quesCreatedNum desc");
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}   

QString dbUtil::allSortByRank(int type)
{
    QSqlQuery query(dbconn);
    QString res;
    if(type==0)
        query.exec("select * from player order by ranker desc,exp desc");
    else if(type==1)
        query.exec("select * from tester order by ranker desc,exp desc");
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}             

void dbUtil::playerInfoUpdate(int exp,int rank,int passNum,QString name)
{
    QSqlQuery query(dbconn);
    /*update tester's info in database*/
    query.prepare("update player set exp = ?, ranker = ?, passNum = ? where uname = ? ");
    query.bindValue(0, exp);
    query.bindValue(1, rank);
    query.bindValue(2, passNum);
    query.bindValue(3, name);
    query.exec();
    query.finish();
}

QString dbUtil::getSignalGameWord(int rank)
{   
    /*in this page,new words will not be add.As a result, we can get all word in word bank.*/
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query;
    QString sql="select * from vocabulary where difficulty <=";
    sql+=QString::number(rank);
    query.exec(sql);
    /*get the size of result set*/
    int rowCount = query.size();
    /*get a random number*/
    qsrand(QTime::currentTime().msec());
    int index=(qrand()%rowCount);
    qDebug() << "Random number:" << index;
    /*using a random number, return a word*/
    if (query.seek(index)) 
    {
        QString res = query.value(0).toString();
        QString difficuly = query.value(1).toString();
        qDebug() << "The row is:" << res << difficuly;
        return res;
    } 
    else 
        qDebug() << "Failed to seek the row";
}

QString dbUtil::playerRegiste(QString uname,QString pwd)
{
    QSqlQuery query(dbconn);
    query.prepare("insert into player(uname,pwd,exp,ranker,passNum,isOnline) values(?,?,0,0,0,1)");
    query.bindValue(0, uname);
    query.bindValue(1, pwd);
    if(query.exec())
        return "1 "+uname+" "+pwd;
    else
        return "0";
}
QString dbUtil::testerRegiste(QString uname,QString pwd)
{
    QSqlQuery query(dbconn);
    query.prepare("insert into tester(uname,pwd,exp,ranker,quesCreatedNum,isOnline) values(?,?,0,0,0,1)");
    query.bindValue(0, uname);
    query.bindValue(1, pwd);
    if(query.exec())
        return "1 "+uname+" "+pwd;
    else
        return "0 ";
}

QString dbUtil::allPlayerOnline(QString uname)
{
    QSqlQuery query(dbconn);
    QString res;
    query.prepare("select * from player where isOnline=1 and uname != ? ");
    query.bindValue(0, uname);
    query.exec();
    while(query.next())
       res+= query.value(0).toString() +' '+ query.value(2).toString()+' '+ query.value(3).toString() +' '+ query.value(4).toString()+'\n';
    return res;
}