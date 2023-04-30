/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:41
 * @LastEditTime: 2023-04-30 21:54:32
 * @Description: Implement local registration and login for the tester.
 */

#ifndef TESTER_H
#define TESTER_H

#include "member.h"

class Tester:public Member
{
    private:
        int quesCreatedNum; //Number of questions created
    public:
        /*constructor*/
        Tester();
        /*Setter*/
        void setQuesCreatedNum(int quesCreatedNum);
        /*Getter*/
        int getQuesCreatedNum();
        /*public methods*/
        Tester* login(Tester tester);
};
#endif