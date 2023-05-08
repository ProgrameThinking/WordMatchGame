
#ifndef MYSERVER_H
#define MYSERVER_H


#include <QTcpServer>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QWidget *parent,int port);
    virtual void incomingConnection(qintptr socketDescriptor);
signals:

};

#endif // MYSERVER_H
