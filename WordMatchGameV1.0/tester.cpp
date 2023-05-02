/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:45
 * @LastEditTime: 2023-05-02 21:33:16
 * @Description: Implement local registration and login for the tester.
 */

#include "tester.h"
#include "dbUtil.h"

/*constructor*/
Tester::Tester(){}
Tester::Tester(QString username,QString password)
{
    this->name=username;
    this->password=password;
}
/*Setter*/
void Tester::setQuesCreatedNum(int quesCreatedNum)
{
    this->quesCreatedNum=quesCreatedNum;
}
/*Getter*/
int Tester::getQuesCreatedNum()
{
    return quesCreatedNum;
}
/*public methods*/

/**
 * @description: If this tester exists in the database, return a full-info tester; otherwise, return null.
 * @return {*}
 */
bool Tester::login()
{
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query;
    QString sql="select * from tester where uname ='";
    sql+= name+"' and pwd='"+password+"'";
    qDebug()<<sql;
    query.exec(sql);
    query.next();
    if(query.value("uname").toString()!=nullptr)
    {
        /*get all player infomation*/
        name=query.value("uname").toString();
        password=query.value("pwd").toString();
        exp=query.value("exp").toDouble();
        rank=query.value("ranker").toInt();
        quesCreatedNum=query.value("quesCreatedNum").toInt();
        //dbcon->close();
        return true;
    }
    else
    {
        //dbcon->close();
        return false;
    }
}