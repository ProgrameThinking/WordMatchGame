/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 21:59:27
 * @LastEditTime: 2023-05-09 16:28:53
 * @Description: 
 */
#include "mysocket.h"
#include <QMessageBox>
#include <QThread>
#include <QDebug>
#include "dbutil.h"

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
        this->write(s.toUtf8().data());
        return;
    }
    /*cope with tester login*/
    else if(info.at(0)=="testerLogin")
    {
        QString s="testerLoginBack ";
        s+=dbcon->playerLogin(info.at(1),info.at(2));
        this->write(s.toUtf8().data());
        return;
    }
}