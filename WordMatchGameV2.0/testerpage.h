/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:32:55
 * @LastEditTime: 2023-05-02 20:13:39
 * @Description: define some methods about tester
 */
#ifndef TESTERPAGE_H
#define TESTERPAGE_H

#include <QWidget>
#include "tester.h"

namespace Ui {
class testerPage;
}

class testerPage : public QWidget
{
    Q_OBJECT

public:
    explicit testerPage(Tester* tester,QWidget *parent = nullptr);
    ~testerPage();

private:
    Ui::testerPage *ui;
    Tester tester;
};

#endif // TESTERPAGE_H
