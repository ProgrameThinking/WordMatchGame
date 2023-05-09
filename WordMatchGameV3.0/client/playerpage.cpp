/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:44
 * @LastEditTime: 2023-05-09 17:59:48
 * @Description: Implement some methods about players
 */
#include "playerpage.h"
#include "ui_playerpage.h"
#include "searchpage.h"
#include "gamepage.h"
#include "widget.h"

playerPage::playerPage(Player* playery,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPage)
{
    /*Pass a parameter to a private variable, and use the private player for all next calls. */
    player.setName(playery->getName());
    player.setPassword(playery->getPassword());
    player.setExp(playery->getExp());
    player.setRank(playery->getRank());
    player.setPassNum(playery->getPassNum());

    /*real start code*/
    ui->setupUi(this);
    ui->username->setText(player.getName());
    ui->expNum->setText(QString::number(player.getExp()));
    ui->rankNum->setText(QString::number(player.getRank()));
    ui->passLevel->setText(QString::number(player.getPassNum()));

    /*game start*/
    connect(ui->playButton,&QPushButton::clicked,[this,m_tcp,playery](){
        gamePage *gamePageWidget=new gamePage(playery,m_tcp);
        gamePageWidget->show();
        this->close();
    });
    /*jump to login page*/
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
        Widget *widget=new Widget();
        widget->show();
        m_tcp->close();
        m_tcp->deleteLater();
        this->close();
    });
    /*jump to search page*/
    connect(ui->searchButton,&QPushButton::clicked,[this,m_tcp,playery](){
        searchPage* searchPageWidget=new searchPage(0,m_tcp,playery);
        searchPageWidget->show();
        this->close();
    });
}

playerPage::~playerPage()
{
    delete ui;
}
