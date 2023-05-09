/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 16:14:41
 * @LastEditTime: 2023-05-09 17:57:20
 * @Description: In this version,player has a unlimited time to spell word.
 */
#include "gamepage.h"
#include "ui_gamepage.h"
#include "dbutil.h"
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
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
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

    word=selectWord();
    ui->wordShowLabel->setText(word);
    int difficuty=(int)((1+(word.length()-3)/2)+0.5);
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
 * @description: select word from word bank(no removal of duplicates)
 * @return {*}
 */
QString gamePage::selectWord()
{
    /*in this page,new words will not be add.As a result, we can get all word in word bank.*/
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query;
    QString sql="select * from vocabulary where difficulty <=";
    qDebug()<<sql;
    sql+=QString::number(nowRank);
    query.exec(sql);
    /*get the size of result set*/
    int rowCount = query.size();
    /*get a random number*/
    qsrand(QTime::currentTime().msec());
    int index=(qrand()%rowCount);
    qDebug() << "Random number:" << index;
    /*using a random number, return a word*/
    if (query.seek(index)) 
    {
        QString res = query.value(0).toString();
        QString difficuly = query.value(1).toString();
        qDebug() << "The row is:" << res << difficuly;
        return res;
    } 
    else 
        qDebug() << "Failed to seek the row";
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
    else
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
        dbUtil* dbcon=new dbUtil();
        QSqlQuery query;
        player.addExp(player.calExp(word.length()));
        player.setPassNum(player.getPassNum()+1);
        /*update player's info*/
        ui->username->setText(player.getName());
        ui->ranklevel->setText(QString::number(nowRank));
        ui->expNum->setText(QString::number(player.getExp()));
        ui->rankNum->setText(QString::number(player.getRank()));
        ui->passLevel->setText(QString::number(player.getPassNum()));
        /*update player's info in database*/
        query.prepare("update player set exp = ?, ranker = ?, passNum = ? where uname = ? and pwd = ?");
        query.bindValue(0, player.getExp());
        query.bindValue(1, player.getRank());
        query.bindValue(2, player.getPassNum());
        query.bindValue(3, player.getName());
        query.bindValue(4, player.getPassword());
        query.exec();
        /*update now rank*/
        if(finishedWord==rankNum())
        {
            finishedWord=0;
            nowRank++;
            pastExp=player.getExp();
            pastRank=player.getRank();
        }
        /*start next word*/
        initGame();
    }
    else//player challenge the same rank again
    {
        QMessageBox::warning(this, tr("答案错误"), tr("重新开始该关卡"));
        finishedWord=0;
        player.setExp(pastExp);
        player.setRank(pastRank);
        ui->username->setText(player.getName());
        ui->ranklevel->setText(QString::number(nowRank));
        ui->expNum->setText(QString::number(player.getExp()));
        ui->rankNum->setText(QString::number(player.getRank()));
        ui->passLevel->setText(QString::number(player.getPassNum()));
        initGame();
    }
}
