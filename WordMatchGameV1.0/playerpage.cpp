/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:44
 * @LastEditTime: 2023-05-03 14:45:33
 * @Description: Implement some methods about players
 */
#include "playerpage.h"
#include "ui_playerpage.h"
#include "gamepage.h"
#include "widget.h"

playerPage::playerPage(Player* playery,QWidget *parent) :
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
    connect(ui->playButton,&QPushButton::clicked,[this,playery](){
        gamePage *gamePageWidget=new gamePage(playery);
        gamePageWidget->show();
        this->close();
    });
    /*jump to login page*/
    connect(ui->exitButton,&QPushButton::clicked,[this](){
        Widget *widget=new Widget();
        widget->show();
        this->close();
    });
}

playerPage::~playerPage()
{
    delete ui;
}
