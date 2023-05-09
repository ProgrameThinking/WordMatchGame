/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 21:59:27
 * @LastEditTime: 2023-05-08 22:38:59
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
    //指定该套接字的描述符
    this->setSocketDescriptor(socket);    

    connect(this, SIGNAL(readyRead()), this, SLOT(on_connected()));
    qDebug() << QThread::currentThread()<<" socket";
}

void MySocket::on_connected()
{
    //读到数据的操作
    QString msg = this->readAll();
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

}