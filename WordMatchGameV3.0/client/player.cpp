/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:34
 * @LastEditTime: 2023-05-09 15:22:31
 * @Description: Implement local registration and login for the player.
 */

#include "player.h"

/*constructor*/
Player::Player(QString username,QString password,int exp,int rank,int passNum)
{
    this->name=username;
    this->password=password;
    this->exp=exp;
    this->rank=rank;
    this->passNum=passNum;
}
Player::Player(){}
Player::Player(QString username,QString password)
{
    this->name=username;
    this->password=password;
}
/*Setter*/
void Player::setPassNum(int passNum)
{
    this->passNum=passNum;
}
/*Getter*/
int Player::getPassNum()
{
    return passNum;
}
/*public method*/


// /**
//  * @description: If this player exists in the database, return a full-info player; otherwise, return null.
//  * @return {*}
//  */
// bool Player::login()
// {
//     dbUtil* dbcon=new dbUtil();
//     QSqlQuery query;
//     QString sql="select * from player where uname ='";
//     sql+= name+"' and pwd='"+password+"'";
//     qDebug()<<sql;
//     query.exec(sql);
//     query.next();
//     if(query.value("uname").toString()!=nullptr)
//     {
//         /*get all player infomation*/
//         name=query.value("uname").toString();
//         password=query.value("pwd").toString();
//         exp=query.value("exp").toDouble();
//         rank=query.value("ranker").toInt();
//         passNum=query.value("passNum").toInt();
//         //dbcon->close();
//         return true;
//     }
//     else
//     {
//         //dbcon->close();
//         return false;
//     }
// }
