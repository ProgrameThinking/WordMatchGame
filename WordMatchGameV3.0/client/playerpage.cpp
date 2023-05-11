/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:44
 * @LastEditTime: 2023-05-11 17:27:22
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
        disconnect(tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
        gamePageWidget->show();
        this->close();
    });
    /*jump to login page*/
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
        Widget *widget=new Widget();
        widget->show();
        disconnect(tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
        QString msg="playerQuit "+player.getName();
        m_tcp->write(msg.toUtf8().data());
        m_tcp->close();
        m_tcp->deleteLater();
        this->close();
    });
    /*jump to search page*/
    connect(ui->searchButton,&QPushButton::clicked,[this,m_tcp,playery](){
        searchPage* searchPageWidget=new searchPage(0,m_tcp,playery);
        disconnect(tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
        searchPageWidget->show();
        this->close();
    });
    /*ready to battle*/
    connect(ui->battleButton,&QPushButton::clicked,[this,m_tcp,playery](){
        battleSelectPage* battleSelectPageWidget=new battleSelectPage(playery,m_tcp);
        disconnect(tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
        battleSelectPageWidget->show();
        this->close();
    });
}

playerPage::~playerPage()
{
    delete ui;
}

void playerPage::isBattle()
{
    QString msg = tcp->readAll();
    QStringList strList = msg.split(" ");
    qDebug()<<"receive isBattle Msg:"<<msg;
    if(strList.at(0)=="ballteReady")
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "对战申请",(strList.at(1)+"向你发起对战,是否接受?"),QMessageBox::Yes | QMessageBox::No );
        if (reply == QMessageBox::Yes) 
        {
            disconnect(tcp,&QTcpSocket::readyRead, this, playerPage::isBattle);
            QStringList strList = msg.split(" ");
            QString res="battleStart "+strList.at(1)+" "+player.getName();
            qDebug()<<"send isBattle Msg:"<<res;
            tcp->write(res.toUtf8().data());
            battlePage* battlePageWidget=new battlePage(0,strList.at(1),&player,tcp);
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