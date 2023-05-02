/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:32:55
 * @LastEditTime: 2023-05-02 19:48:53
 * @Description: Implement some methods about tester
 */
#include "testerpage.h"
#include "ui_testerpage.h"

testerPage::testerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testerPage)
{
    ui->setupUi(this);
    /*jump to add word page*/
    connect(ui->setProblemButton,&QPushButton::clicked,[this]()
    {
        
    });
}

testerPage::~testerPage()
{
    delete ui;
}
