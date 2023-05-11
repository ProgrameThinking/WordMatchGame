/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-11 11:43:40
 * @LastEditTime: 2023-05-11 13:22:19
 * @Description: 
 */
#ifndef BATTLEPAGE_H
#define BATTLEPAGE_H

#include <QWidget>
#include <QTcpSocket>
#include "player.h"

namespace Ui {
class battlePage;
}

class battlePage : public QWidget
{
    Q_OBJECT

public:
    explicit battlePage(QString opponent,Player* playery,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~battlePage();

private:
    Ui::battlePage *ui;
};

#endif // BATTLEPAGE_H
