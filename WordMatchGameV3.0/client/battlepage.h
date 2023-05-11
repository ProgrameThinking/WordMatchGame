/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-11 11:43:40
 * @LastEditTime: 2023-05-11 16:45:06
 * @Description: 
 */
#ifndef BATTLEPAGE_H
#define BATTLEPAGE_H

#include <QWidget>
#include <QTcpSocket>
#include "player.h"
#include <QTimer>

namespace Ui {
class battlePage;
}

class battlePage : public QWidget
{
    Q_OBJECT

public:
    explicit battlePage(int type,QString opponent,Player* playery,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~battlePage();

private:
    Ui::battlePage *ui;
    Player* player;
    int correctWord=0;   //the number of words passed 
    QString word;         //answer
    QString emery;  //your opponent
    QTcpSocket* tcp;
    int round=0;    //there are five rounds of the battle, and the winner is the person who answers the most questions correctly
    /*Timer*/
    QTimer* processBarTimer;
    QTimer* memoryTimer;
    
    /*private methods*/
    void initGame();
    void submit();
    void gameStart();
};

#endif // BATTLEPAGE_H
