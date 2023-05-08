/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 22:15:50
 * @LastEditTime: 2023-05-08 20:36:55
 * @Description: 
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:
    void connectOK();
    void connectOver();

private:
    Ui::Widget *ui;
    QTcpSocket* m_tcp;
    QString ip="127.0.0.1";
    unsigned short port=8989;
    void connectServer();
};

#endif // WIDGET_H
