/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 16:14:41
 * @LastEditTime: 2023-05-11 16:45:20
 * @Description: 
 */
#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QTimer>
#include <QTcpSocket>
#include "player.h"

namespace Ui {
class gamePage;
}

class gamePage : public QWidget
{
    Q_OBJECT

public:
    explicit gamePage(Player* playery,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~gamePage();

private:
    Ui::gamePage *ui;
    /*private variable*/
    Player player;
    int nowRank=1;        //the current level number in the game
    int finishedWord=0;   //the number of words passed at the current level
    QString word;         //answer
    int pastExp;          //exp when the level is not completed
    int pastRank;         //rank when the level is not completed
    QTcpSocket* tcp;
    /*Timer*/
    QTimer* processBarTimer;
    QTimer* memoryTimer;
    
    /*private methods*/
    void initGame();
    int rankNum();
    void submit();
    void gameStart();
};

#endif // GAMEPAGE_H
