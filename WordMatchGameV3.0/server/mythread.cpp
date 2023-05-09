/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 21:56:51
 * @LastEditTime: 2023-05-09 15:28:04
 * @Description: 
 */

#include "mythread.h"
#include "mysocket.h"

MyThread::MyThread(QWidget *parent, qintptr socket) : QThread(parent)
{
    qRegisterMetaType<qintptr>("qintptr");
    this->p = socket;//指定标识符
    connect(this, SIGNAL(finished()),this,SLOT(deleteLater()));
    qDebug() << "sub_thread:"<<QThread::currentThread();
}

MyThread::~MyThread()
{
    this->deleteLater();
}

void MyThread::run()
{
    socket = new MySocket(0, this->p);
    connect(socket, &MySocket::disconnected, this, &MyThread::quit, Qt::DirectConnection);
    connect(socket, &MySocket::update_serve, socket, &MySocket::slot_update);
    this->exec();
}