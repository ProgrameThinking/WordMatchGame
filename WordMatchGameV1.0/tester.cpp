/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:45
 * @LastEditTime: 2023-04-30 22:27:46
 * @Description: Implement local registration and login for the tester.
 */

#include "tester.h"

/*constructor*/
Tester::Tester()
{

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
 * @param {Tester} tester
 * @return {Tester}
 * @description: If this tester exists in the database, return a full-info tester; otherwise, return null.
 */
Tester* Tester::login(Tester tester)
{
    return nullptr;
}