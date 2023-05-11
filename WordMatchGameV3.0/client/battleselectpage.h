/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-11 11:43:18
 * @LastEditTime: 2023-05-11 13:06:41
 * @Description: 
 */

#ifndef BATTLESELECTPAGE_H
#define BATTLESELECTPAGE_H

#include <QWidget>
#include <QTcpSocket>
#include "player.h"

namespace Ui {
class battleSelectPage;
}

class battleSelectPage : public QWidget
{
    Q_OBJECT

signals:
    void recvInfo(QString msg);
    void battleBeginSignal(QString msg);

public:
    explicit battleSelectPage(Player* playery,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~battleSelectPage();

private:
    Ui::battleSelectPage *ui;
    QTcpSocket* tcp;
    Player* player;
    /*private method*/
    void setPlayerInfo(QString msg);
    void readyBattle();
    void battleBegin(QString msg);
    void setSignals();
};

#endif // BATTLESELECTPAGE_H
