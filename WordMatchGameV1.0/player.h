/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:34
 * @LastEditTime: 2023-05-01 10:39:20
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
        /*Setter*/
        void setPassNum(int passNum);
        /*Getter*/
        int getPassNum();
        /*public method*/
        Player* login(Player player);       
};

#endif // PLAYER_H