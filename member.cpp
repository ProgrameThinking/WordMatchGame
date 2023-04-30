/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:12
 * @LastEditTime: 2023-04-30 21:51:06
 * @Description: Implement the methods in member.h.
 */

#include "member.h"

/*constructor*/
Member::Member()
{
    
}
/*Setter*/
void Member::setPassword(string password)
{
    this->password=password;
}
void Member::setExp(int exp)
{
    this->exp=exp;
}
void Member::setName(string name)
{
    this->name=name;
}
void Member::setRank(int rank)
{
    this->rank=rank;
}
/*Getter*/
string Member::getPassword()
{
    return password;
}
int Member::getExp()
{
    return exp;
}
string Member::getName()
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