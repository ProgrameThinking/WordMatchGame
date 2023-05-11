/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:44
 * @LastEditTime: 2023-05-11 14:09:38
 * @Description: Implement some methods about players
 */
#include "playerpage.h"
#include "ui_playerpage.h"
#include "battleselectpage.h"
#include "battlepage.h"
#include "searchpage.h"
#include "gamepage.h"
#include "widget.h"
#include <QMessageBox>

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
    tcp=m_tcp;

    /*real start code*/
    ui->setupUi(this);
    ui->username->setText(player.getName());
    ui->expNum->setText(QString::number(player.getExp()));
    ui->rankNum->setText(QString::number(player.getRank()));
    ui->passLevel->setText(QString::number(player.getPassNum()));

    connect(m_tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
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
        this->close();
    });
    /*jump to search page*/
    connect(ui->searchButton,&QPushButton::clicked,[this,m_tcp,playery](){
        searchPage* searchPageWidget=new searchPage(0,m_tcp,playery);
        searchPageWidget->show();
        this->close();
    });
    /*ready to battle*/
    connect(ui->battleButton,&QPushButton::clicked,[this,m_tcp,playery](){
        battleSelectPage* battleSelectPageWidget=new battleSelectPage(playery,m_tcp);
        battleSelectPageWidget->show();
        this->close();
    });
}

playerPage::~playerPage()
{
    delete ui;
    disconnect(tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
    QString msg="playerQuit "+player.getName();
    tcp->write(msg.toUtf8().data());
    tcp->close();
    tcp->deleteLater();
}

void playerPage::isBattle()
{
    QString msg = tcp->readAll();
    QStringList strList = msg.split(" ");
    if(strList.at(0)=="ballteReady")
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "对战申请",(strList.at(1)+"向你发起对战,是否接受?"),QMessageBox::Yes | QMessageBox::No );
        if (reply == QMessageBox::Yes) 
        {
            QStringList strList = msg.split(" ");
            QString res="battleStart "+strList.at(1)+player.getName();
            tcp->write(res.toUtf8().data());
            battlePage* battlePageWidget=new battlePage(player.getName(),&player,tcp);
            battlePageWidget->show();
            this->close();
        }
        else if (reply == QMessageBox::No) 
        {
            QString res="battleRefused "+strList.at(1);
            tcp->write(res.toUtf8().data());
        }
    }
}