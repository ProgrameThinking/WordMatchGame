/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:43
 * @LastEditTime: 2023-05-02 22:12:43
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
};

#endif // PLAYERPAGE_H
