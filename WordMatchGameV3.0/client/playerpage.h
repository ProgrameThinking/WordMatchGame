/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:43
 * @LastEditTime: 2023-05-11 13:54:29
 * @Description: 
 */
#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include <QWidget>
#include <QTcpSocket>
#include "player.h"

namespace Ui {
class playerPage;
}

class playerPage : public QWidget
{
    Q_OBJECT

public:
    explicit playerPage(Player* playery,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~playerPage();

private:
    Ui::playerPage *ui;
    Player player;
    QTcpSocket* tcp;
    void isBattle();
};

#endif // PLAYERPAGE_H
