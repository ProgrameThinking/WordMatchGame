/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:35:06
 * @LastEditTime: 2023-04-30 22:43:26
 * @Description: The class that need to be inherited by the Player class and Tester class.
 */
#ifndef MEMBER_H
#define MEMBER_H

#include <QObject>
#include <QString>
class Member : public QObject
{
    Q_OBJECT
    protected:
        QString password;    //user's pwd
        double exp;            //user's exp
        QString name;        //user's name
        int rank;           //user's rank(need to be calculated)
    public:
        /*constructor*/
        Member();
        /*Setter*/
        void setPassword(QString password);
        void setExp(double exp);
        void setName(QString name);
        void setRank(int rank);
        /*Getter*/
        QString getPassword();
        double getExp();
        QString getName();
        int getRank();
        /*public method*/
        void userRegister(); 
};

#endif // MEMBER_H