/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 21:54:40
 * @LastEditTime: 2023-05-08 22:02:36
 * @Description: 
 */

#include "myserver.h"

MyServer::MyServer(QWidget *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    MyThread *thread = new MyThread(0, socketDescriptor);
    connect(thread, &MyThread::finished, [&]{ qDebug() << "thread is over:"<<QThread::currentThread(); });
    connect(thread, &MyThread::finished, &MyThread::deleteLater);
    thread->start();
}

