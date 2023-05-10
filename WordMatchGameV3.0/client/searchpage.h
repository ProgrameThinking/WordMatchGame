/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:39:50
 * @LastEditTime: 2023-05-10 20:59:10
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

signals:
    void playerInfo(QString msg);
    void testerInfo(QString msg);
    void searchInfo(QString msg);
    void SortByNumInfo(QString msg);
    void SortByRankInfo(QString msg);

private:
    Ui::searchPage *ui;
    bool isPlayer;  //true--player  false--tester
    QTcpSocket* tcp;
    /*private method*/
    //send tcp request
    void sendSearchInfo();
    void sendPlayerInfo();
    void sendTesterInfo();
    void sendSortByNum();
    void sendSortByRank();
    //send signal
    void sendSignal();
    //receive tcp messages
    void setSearchInfo(QString msg);
    void setPlayerInfo(QString msg);
    void setTesterInfo(QString msg);
    void setSortByNum(QString msg);
    void setSortByRank(QString msg);
};

#endif // SEARCHPAGE_H
