/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:32:55
 * @LastEditTime: 2023-05-09 17:51:12
 * @Description: define some methods about tester
 */
#ifndef TESTERPAGE_H
#define TESTERPAGE_H

#include <QWidget>
#include <QTcpSocket>
#include "tester.h"

namespace Ui {
class testerPage;
}

class testerPage : public QWidget
{
    Q_OBJECT

public:
    explicit testerPage(Tester* tester,QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~testerPage();

private:
    Ui::testerPage *ui;
    Tester tester;
};

#endif // TESTERPAGE_H
