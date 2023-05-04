/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 16:14:41
 * @LastEditTime: 2023-05-03 19:45:04
 * @Description: 
 */
#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QTimer>
#include "player.h"

namespace Ui {
class gamePage;
}

class gamePage : public QWidget
{
    Q_OBJECT

public:
    explicit gamePage(Player* playery,QWidget *parent = nullptr);
    ~gamePage();

private:
    Ui::gamePage *ui;
    /*private variable*/
    Player player;
    int nowRank=1;        //the current level number in the game
    int finishedWord=0;   //the number of words passed at the current level
    QString word;         //answer
    /*Timer*/
    QTimer* processBarTimer;
    QTimer* memoryTimer;
    /*private methods*/
    void initGame();
    QString selectWord();
    int rankNum();
    void submit();
};

#endif // GAMEPAGE_H
