/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:12
 * @LastEditTime: 2023-05-10 23:26:35
 * @Description: Implement the methods in member.h.
 */

#include "member.h"
#include <math.h>
#include <QDebug>

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

/**
 * @description: check if upgrade is needed when adding experience.
 * @param {int} expNum
 * @return {*}
 */
void Member::addExp(int expNum)
{
    int upExp=(100+rank*50); //exp required for level up
    qDebug()<<expNum+" "+upExp;
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