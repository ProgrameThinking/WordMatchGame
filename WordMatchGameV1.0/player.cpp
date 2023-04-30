/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 20:58:34
 * @LastEditTime: 2023-04-30 22:28:21
 * @Description: Implement local registration and login for the player.
 */

#include "player.h"

/*constructor*/
Player::Player()
{
    
}
/*Setter*/
void Player::setPassNum(int passNum)
{
    this->passNum=passNum;
}
/*Getter*/
int Player::getPassNum()
{
    return passNum;
}
/*public method*/

/**
 * @param {Player} player
 * @return {Player}
 * @description: If this player exists in the database, return a full-info player; otherwise, return null.
 */
Player* Player::login(Player player)
{
    return nullptr;
}
