/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 21:59:27
 * @LastEditTime: 2023-05-11 12:15:12
 * @Description: 
 */
#include "mysocket.h"
#include <QMessageBox>
#include <QThread>
#include <QDebug>

extern QList<MySocket *> mysocketlist;
extern QList<QString> gamelist;
extern QList<qintptr> labellist;

MySocket::MySocket(QWidget *parent, qintptr socket) : QTcpSocket(parent)
{
    this->setSocketDescriptor(socket);    
    connect(this, SIGNAL(readyRead()), this, SLOT(on_connected()));
    qDebug() << QThread::currentThread()<<" socket";
}

void MySocket::on_connected()
{
    QString msg = this->readAll();
    qDebug()<<"receive msg:"<<msg;
    emit update_serve(msg,this->socketDescriptor());
}

void MySocket::slot_disconnect()
{
    for(int i = 0; i < mysocketlist.count(); i++)
    {
        MySocket *item = mysocketlist.at(i);
        if(item->socketDescriptor() == this->socketDescriptor())
        {
            mysocketlist.removeAt(i);
            labellist.removeAt(i);
            gamelist.removeAt(i);
        }
    }
}

void MySocket::slot_update(QString msg, qintptr descriptor)
{
    QStringList info = msg.split(' ');
    dbUtil* dbcon=new dbUtil();
    /*cope with player login*/
    if(info.at(0)=="playerLogin")
    {
        QString s="playerLoginBack ";
        s+=dbcon->playerLogin(info.at(1),info.at(2));
        qDebug()<<"send player login msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*cope with tester login*/
    else if(info.at(0)=="testerLogin")
    {
        QString s="testerLoginBack ";
        s+=dbcon->testerLogin(info.at(1),info.at(2));
        qDebug()<<"send tester login msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*cope with player registe*/
    else if(info.at(0)=="playerRegistation")
    {
        QString s="playerRegistationRecv ";
        s+=dbcon->playerRegiste(info.at(1),info.at(2));
        qDebug()<<"send tester login msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*cope with tester registe*/
    else if(info.at(0)=="testerRegistation")
    {
        QString s="testerRegistationRecv ";
        s+=dbcon->testerRegiste(info.at(1),info.at(2));
        qDebug()<<"send tester login msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*cope with adding word*/
    else if(info.at(0)=="testerAddWord")
    {
        QString s="testerWordRecv ";
        if(dbcon->addWord(info.at(1),info.at(2).toInt()))
            s+="1";
        else
            s+="0";
        qDebug()<<"send add word msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*cope with search page*/
    else if(info.at(0)=="playerUserName")
    {
        QString s="searchPage\n";
        s+=dbcon->allSearchUname(0,info.at(1));
        qDebug()<<"send playerUserName msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="playerRank")
    {
        QString s="searchPage\n";
        s+=dbcon->allSearchRank(0,info.at(1).toInt());
        qDebug()<<"send playerRank msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="playerNum")
    {
        QString s="searchPage\n";
        s+=dbcon->allSearchNum(0,info.at(1).toInt());
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="testerUserName")
    {
        QString s="searchPage\n";
        s+=dbcon->allSearchUname(1,info.at(1));
        qDebug()<<"send testerUserName msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="testerRank")
    {
        QString s="searchPage\n";
        s+=dbcon->allSearchRank(1,info.at(1).toInt());
        qDebug()<<"send testerRank msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="testerNum")
    {
        QString s="searchPage\n";
        s+=dbcon->allSearchNum(1,info.at(1).toInt());
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="allPlayerInfo")
    {
        QString s="playerInfo\n";
        s+=dbcon->allPlayerInfo();
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="allTesterInfo")
    {
        QString s="testerInfo\n";
        s+=dbcon->allTesterInfo();
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="playerSortByNum")
    {
        QString s="sortByNum\n";
        s+=dbcon->allSortByNum(0);
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="testerSortByNum")
    {
        QString s="sortByNum\n";
        s+=dbcon->allSortByNum(1);
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="playerSortByRank")
    {
        QString s="sortByRank\n";
        s+=dbcon->allSortByRank(0);
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="testerSortByRank")
    {
        QString s="sortByRank\n";
        s+=dbcon->allSortByRank(1);
        qDebug()<<"send playerNum msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*finish coping with search page*/
    else if(info.at(0)=="singalGameWord")
    {
        QString s="singalGameWordRecv ";
        s+=dbcon->getSignalGameWord(info.at(1).toInt());
        qDebug()<<"send singalGameWord msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    else if(info.at(0)=="playerOnline")
    {
        QString s="playerOnlineRecv\n";
        s+=dbcon->allPlayerOnline(info.at(1));
        qDebug()<<"send singalGameWord msg:"<<s<<"  My thread:"<<QThread::currentThread();
        this->write(s.toUtf8().data());
    }
    /*cope with tester info's update*/
    else if(info.at(0)=="testerUpdate")
        dbcon->testerInfoUpdate(info.at(2).toInt(),info.at(3).toInt(),info.at(4).toInt(),info.at(1));
    /*cope with player info's update*/
    else if(info.at(0)=="playerUpdate")
        dbcon->playerInfoUpdate(info.at(2).toInt(),info.at(3).toInt(),info.at(4).toInt(),info.at(1));
    /*cope with player logout*/
    else if(info.at(0)=="playerQuit")
        dbcon->playerLogout(info.at(1));
    /*cope with tester logout*/
    else if(info.at(0)=="testerQuit")
        dbcon->testerLogout(info.at(1));
    delete(dbcon);
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}