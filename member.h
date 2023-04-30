/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:06
 * @LastEditTime: 2023-04-30 21:29:09
 * @Description: The class that need to be inherited by the Player class and Tester class.
 */

#ifndef MEMBER_H
#define MEMBER_H

#include<string>
using namespace std;

class Member
{
    protected:
        string password;    //user's pwd
        int exp;            //user's exp
        string name;        //user's name
        int rank;           //user's rank(need to be calculated)
    public:
        /*constructor*/
        Member();
        /*Setter*/
        void setPassword(string password);
        void setExp(int exp);
        void setName(string name);
        void setRank(int rank);
        /*Getter*/
        string getPassword();
        int getExp();
        string getName();
        int getRank();
        /*public method*/
        void userRegister(); 
};
#endif