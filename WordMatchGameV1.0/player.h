/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:34
 * @LastEditTime: 2023-05-02 14:17:59
 * @Description: Implement local registration and login for players.
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "member.h"

class Player : public Member
{
    Q_OBJECT
    private:
        int passNum; //The number of challenges passed.
    public:
        /*constructor*/
        Player();
        Player(QString username,QString password);
        /*Setter*/
        void setPassNum(int passNum);
        /*Getter*/
        int getPassNum();
        /*public method*/
        bool login();       
};

#endif // PLAYER_H