/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:12
 * @LastEditTime: 2023-05-01 19:41:12
 * @Description: Implement the methods in member.h.
 */

#include "member.h"

/*constructor*/
Member::Member()
{
    
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
 * @description: carry out user and challenger registration.
 */
void Member::userRegister()
{
    
}