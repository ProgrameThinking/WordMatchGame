/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:41
 * @LastEditTime: 2023-05-03 20:38:07
 * @Description: Implement local registration and login for testers.
 */
#ifndef TESTER_H
#define TESTER_H

#include "member.h"

class Tester : public Member
{
    Q_OBJECT
    private:
        int quesCreatedNum; //Number of questions created
    public:
        /*constructor*/
        Tester(QString username,QString password,int exp,int rank,int quesCreatedNum);
        Tester();
        Tester(QString username,QString password);
        /*Setter*/
        void setQuesCreatedNum(int quesCreatedNum);
        /*Getter*/
        int getQuesCreatedNum();
        /*public methods*/
        bool login();
};

#endif // TESTER_H