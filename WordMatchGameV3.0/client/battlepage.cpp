#include "battlepage.h"
#include "ui_battlepage.h"
#include "playerpage.h"
#include <QMessageBox>
#include <QTime>

battlePage::battlePage(int type,QString opponent,Player* playery,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlePage)
{
    ui->setupUi(this);
    ui->player1->setText(playery->getName());
    ui->player2->setText(opponent);
    tcp=m_tcp;
    player=playery;
    emery=opponent;
    /*when you jump to this page,game has been started*/
    if(type==1)
        initGame();
    else
    {
        ui->answerEdit->setEnabled(false);
        ui->submitButton->setEnabled(false);
        ui->timeLimitBar->setValue(100);
        ui->answerEdit->setText("");
    }
    /*player submit the answer*/
    connect(ui->submitButton,&QPushButton::clicked,this,battlePage::submit);
    //After receiving the information from the server, a ready signal will be sent
    connect(tcp, &QTcpSocket::readyRead, this, battlePage::gameStart);
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp,opponent](){
        disconnect(tcp, &QTcpSocket::readyRead, this, battlePage::gameStart);
        if(round==5)
        {   if(correctWord>=3)         
                player->addExp(200);
            QString msg="playerUpdate "+player->getName()+" "+QString::number(player->getExp())+" "+QString::number(player->getRank())+" "+QString::number(player->getPassNum());
            tcp->write(msg.toUtf8().data());
        }
        else
        {
            QString msg="battleLose "+player->getName()+" "+opponent;
            tcp->write(msg.toUtf8().data());
        }
        /*jump to player page*/
        playerPage *playerPageWidget = new playerPage(player,m_tcp);
        playerPageWidget->show();
        this->close();
    });
}

battlePage::~battlePage()
{
    delete ui;
}

void battlePage::initGame()
{
    if(round<5)
    {
        /*ban textLine and confirm button*/
        ui->answerEdit->setEnabled(false);
        ui->submitButton->setEnabled(false);
        ui->timeLimitBar->setValue(100);
        ui->answerEdit->setText("");
        QString msg="battleGameWord "+player->getName()+" "+emery;
        qDebug()<<"send battleGameWord msg:"<<msg;
        tcp->write(msg.toUtf8().data());
    }
    else
    {
        ui->submitButton->setDisabled(true);
        if(correctWord<3)
            QMessageBox::information(this, tr("对战结果"), tr("你输了!不损失经验"));
        else
            QMessageBox::information(this, tr("对战结果"), tr("你赢了!获得200经验"));
    }
    qDebug()<<QString::number(round);
}

void battlePage::gameStart()
{
    ui->answerEdit->setEnabled(false);
    ui->submitButton->setEnabled(false);
    ui->timeLimitBar->setValue(100);
    ui->answerEdit->setText("");
    QString array = tcp->readAll();
    qDebug() << "receive battleGameWord msg:" <<array;
    QStringList info = array.split(' ');
    if(info.at(0)=="battleGameWordRecv")
    {
        word=info.at(1);
        ui->wordShowLabel->setText(word);
        int difficuty=(int)((1+(word.length()-3)/2)+0.5);
        int interval=(difficuty/(1+3*0.2))*1000;
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
        round++;
    }
    else if(info.at(0)=="youAreWinner")
    {
        QMessageBox::information(this, tr("对战结果"), tr("对手逃跑,你赢得了这场比赛!\n获得200经验"));
        ui->submitButton->setDisabled(true);
        player->addExp(200);
    }
}

/**
 * @description: 
 * @return {*}
 */
void battlePage::submit()
{
    QString answer=ui->answerEdit->text();
    if(answer==word)//update player info in database and get a new word
    {
        correctWord++;
        initGame();
    }
    else//player challenge the same rank again
        QMessageBox::warning(this, tr("答案错误"), tr("答案错误!"));
}