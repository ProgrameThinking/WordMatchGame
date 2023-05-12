/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 16:14:41
 * @LastEditTime: 2023-05-12 11:23:03
 * @Description: In this version,player has a unlimited time to spell word.
 */
#include "gamepage.h"
#include "ui_gamepage.h"
#include "playerpage.h"
#include <QMessageBox>
#include <QTime>

gamePage::gamePage(Player* playery,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamePage)
{
    /*Pass a parameter to a private variable, and use the private player for all next calls. */
    player.setName(playery->getName());
    player.setPassword(playery->getPassword());
    player.setExp(playery->getExp());
    player.setRank(playery->getRank());
    player.setPassNum(playery->getPassNum());
    pastExp=player.getExp();
    pastRank=player.getRank();
    tcp=m_tcp;
    /*real start code*/
    ui->setupUi(this);
    ui->username->setText(player.getName());
    ui->ranklevel->setText(QString::number(nowRank));
    ui->expNum->setText(QString::number(player.getExp()));
    ui->rankNum->setText(QString::number(player.getRank()));
    ui->passLevel->setText(QString::number(player.getPassNum()));
    /*when you jump to this page,game has been started*/
    initGame();
    /*player submit the answer*/
    connect(ui->submitButton,&QPushButton::clicked,this,gamePage::submit);
    //After receiving the information from the server, a ready signal will be sent
    connect(tcp, &QTcpSocket::readyRead, this, gamePage::gameStart);
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
        disconnect(tcp, &QTcpSocket::readyRead, this, gamePage::gameStart);
        /*update tester info in server*/
        QString msg="playerUpdate "+player.getName()+" "+QString::number(pastExp)+" "+QString::number(pastRank)+" "+QString::number(player.getPassNum());
        tcp->write(msg.toUtf8().data());
        /*jump to player page*/
        player.setExp(pastExp);
        player.setRank(pastRank);
        playerPage *playerPageWidget = new playerPage(&player,m_tcp);
        playerPageWidget->show();
        this->close();
    });
}

gamePage::~gamePage()
{
    delete ui;
}

void gamePage::initGame()
{
    /*ban textLine and confirm button*/
    ui->answerEdit->setEnabled(false);
    ui->submitButton->setEnabled(false);
    ui->timeLimitBar->setValue(100);
    ui->answerEdit->setText("");
    QString msg="singalGameWord "+ QString::number(nowRank);
    qDebug()<<"send singalGameWord msg:"<<msg;
    tcp->write(msg.toUtf8().data());
}

void gamePage::gameStart()
{
    QString array = tcp->readAll();
    qDebug() << "receive singalGameWord msg:" <<array;
    QStringList info = array.split(' ');
    if(info.at(0)=="singalGameWordRecv")
        word=info.at(1);
    ui->wordShowLabel->setText(word);
    int difficuty=(int)((1.5+(word.length()-3)/2));
    int interval=(difficuty/(1+nowRank*0.2))*1000;
    qDebug()<<interval;
    processBarTimer=new QTimer(this);

    /*a progress bar display with a minor bug.*/
    processBarTimer->start(interval/50);
    connect(processBarTimer, &QTimer::timeout, [=]() {
        int value = ui->timeLimitBar->value();
        if (value <= ui->timeLimitBar->minimum()) {
            processBarTimer->stop();
            return;
        }
        ui->timeLimitBar->setValue(value - 1);
    });

    memoryTimer=new QTimer(this);
    memoryTimer->start(interval*2);
    /*when the memorization time is up*/
    connect(memoryTimer,&QTimer::timeout,[this](){
        ui->answerEdit->setEnabled(true);
        ui->submitButton->setEnabled(true);
        ui->wordShowLabel->setText("");
        ui->timeLimitBar->setValue(0);
        memoryTimer->stop();
    });
}

/**
 * @description: increase in the number of rounds played
 * @return {*}
 */
int gamePage::rankNum()
{
    if(nowRank%2==1&&nowRank!=1)
        return (nowRank-1);
    else if(nowRank%2==0)
        return nowRank;
    else if(nowRank==1)
        return 1;
}

/**
 * @description: 
 * @return {*}
 */
void gamePage::submit()
{
    QString answer=ui->answerEdit->text();
    if(answer==word)//update player info in database and get a new word
    {
        finishedWord++;
        player.addExp(player.calExp(word.length()));
        player.setPassNum(player.getPassNum()+1);
        /*update now rank*/
        if(finishedWord==rankNum())
        {
            finishedWord=0;
            nowRank++;
            pastExp=player.getExp();
            pastRank=player.getRank();
        }
    }
    else//player challenge the same rank again
    {
        QMessageBox::warning(this, tr("答案错误"), tr("重新开始该关卡"));
        finishedWord=0;
        player.setExp(pastExp);
        player.setRank(pastRank);
    }
    /*update player's info*/
    ui->username->setText(player.getName());
    ui->ranklevel->setText(QString::number(nowRank));
    ui->expNum->setText(QString::number(player.getExp()));
    ui->rankNum->setText(QString::number(player.getRank()));
    ui->passLevel->setText(QString::number(player.getPassNum()));
    /*start a new game*/
    initGame();
}
