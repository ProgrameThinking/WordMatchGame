/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:39:50
 * @LastEditTime: 2023-05-04 14:17:12
 * @Description: player and tester have a same page
 */
#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include "playerpage.h"
#include "testerpage.h"
#include "player.h"
#include "tester.h"

namespace Ui {
class searchPage;
}

class searchPage : public QWidget
{
    Q_OBJECT

public:
    explicit searchPage(int type,QTcpSocket* m_tcp,Player* player = nullptr ,Tester* tester = nullptr ,QWidget *parent = nullptr);
    ~searchPage();

private:
    Ui::searchPage *ui;
    bool isPlayer;  //true--player  false--tester
    /*private method*/
    void setPlayerTable();
    void setTesterTable();
    void searchInfo();
    void sortByNum();
    void sortByRank();
};

#endif // SEARCHPAGE_H
