/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 19:27:06
 * @LastEditTime: 2023-05-09 22:17:10
 * @Description: define some methods for adding word
 */
#ifndef ADDWORDPAGE_H
#define ADDWORDPAGE_H

#include <QWidget>
#include <QTcpSocket>
#include "tester.h"

namespace Ui {
class addWordPage;
}

class addWordPage : public QWidget
{
    Q_OBJECT

public:
    explicit addWordPage(Tester* testerp,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~addWordPage();

private:
    Ui::addWordPage *ui;
    QTcpSocket* tcp;
    Tester tester;
    /*private methods*/
    void sentword();    //send word to server
    void wordRecv();    //deal with server's message
};

#endif // ADDWORDPAGE_H
