/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:12
 * @LastEditTime: 2023-05-02 13:49:40
 * @Description: Implement the methods in member.h.
 */

#include "member.h"
#include "dbutil.h"

/*constructor*/
Member::Member()
{
    
}
Member:: Member(QString name,QString password)
{
    this->name=name;
    this->password=password;
}
/*Setter*/
void Member::setPassword(QString password)
{
    this->password=password;
}
void Member::setExp(double exp)
{
    this->exp=exp;
}
void Member::setName(QString name)
{
    this->name=name;
}
void Member::setRank(int rank)
{
    this->rank=rank;
}
/*Getter*/
QString Member::getPassword()
{
    return password;
}
double Member::getExp()
{
    return exp;
}
QString Member::getName()
{
    return name;
}
int Member::getRank()
{
    return rank;
}

/*need to be completed*/

/**
 * @return {*}
 * @description: carry out player and tester registration.
 */
bool Member::userRegister(QString type)
{
    QString sql;
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query;
    /*insert user info to database*/
    if(type=="出题者")
    {
        sql="insert into tester(uname,pwd,exp,ranker,quesCreatedNum) values ('";
        sql+=name+"','"+password+"',0.0,0,0)";
    }
    else if(type=="玩家")
    {
        sql="insert into player(uname,pwd,exp,ranker,passNum) values ('";
        sql+=name+"','"+password+"',0.0,0,0)";
    }
    qDebug()<<sql;
    if(query.exec(sql))
        return true;
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    
}