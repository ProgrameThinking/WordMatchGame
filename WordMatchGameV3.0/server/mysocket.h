/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 21:59:27
 * @LastEditTime: 2023-05-11 16:16:00
 * @Description: 
 */

#ifndef MYSOCKET_H
#define MYSOCKET_H


#include <QObject>
#include <QTcpSocket>
#include "dbutil.h"

class MySocket : public QTcpSocket
{
    Q_OBJECT
public:
    MySocket(QWidget *parent, qintptr socket);

    //处理新来的链接
public slots:
    void on_connected();
    void slot_update(QString msg, qintptr descriptor);
    void slot_disconnect();
    Q_INVOKABLE void sendData(QString s);
signals:
    void update_serve(QString msg,qintptr descriptor);
};

#endif // MYSOCKET_H
