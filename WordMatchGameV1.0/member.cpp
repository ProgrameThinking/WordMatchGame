/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:12
 * @LastEditTime: 2023-05-02 21:29:43
 * @Description: Implement the methods in member.h.
 */

#include "member.h"
#include "dbutil.h"
#include <math.h>

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
    {
        //dbcon->close();
        return true;
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
        //dbcon->close();
        return false;
    }
}

/**
 * @description: check if upgrade is needed when adding experience.
 * @param {int} expNum
 * @return {*}
 */
void Member::addExp(int expNum)
{
    int upExp=(100+rank*50); //exp required for level up
    if(expNum+exp<upExp)
        exp+=expNum;
    else
    {
        exp=exp+expNum-upExp;
        rank++;
    }
}

/**
 * @description: according word length to calculate exp
 * @param {int} wordLength
 * @return {*}
 */
int Member::calExp(int wordLength)
{
    return (int)((1+log2(wordLength)*10)+0.5);
}