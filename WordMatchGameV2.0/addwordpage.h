/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 19:27:06
 * @LastEditTime: 2023-05-02 21:41:30
 * @Description: define some methods for adding word
 */
#ifndef ADDWORDPAGE_H
#define ADDWORDPAGE_H

#include <QWidget>
#include "tester.h"

namespace Ui {
class addWordPage;
}

class addWordPage : public QWidget
{
    Q_OBJECT

public:
    explicit addWordPage(Tester* testerp,QWidget *parent = nullptr);
    ~addWordPage();
    void submitWord();

private:
    Ui::addWordPage *ui;
    Tester tester;
};

#endif // ADDWORDPAGE_H
