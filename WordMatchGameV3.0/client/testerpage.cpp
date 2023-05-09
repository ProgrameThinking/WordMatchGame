/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:32:55
 * @LastEditTime: 2023-05-09 21:00:04
 * @Description: Implement some methods about tester
 */
#include "testerpage.h"
#include "ui_testerpage.h"
#include "searchpage.h"
#include "addwordpage.h"
#include "widget.h"

testerPage::testerPage(Tester* tester,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testerPage)
{
    /*Pass a parameter to a private variable, and use the private tester for all next calls. */
    this->tester.setName(tester->getName());
    this->tester.setPassword(tester->getPassword());
    this->tester.setExp(tester->getExp());
    this->tester.setRank(tester->getRank());
    this->tester.setQuesCreatedNum(tester->getQuesCreatedNum());

    /*real start code*/
    ui->setupUi(this);
    ui->username->setText(this->tester.getName());
    ui->expNum->setText(QString::number(this->tester.getExp()));
    ui->rankNum->setText(QString::number(this->tester.getRank()));
    ui->passLevel->setText(QString::number(this->tester.getQuesCreatedNum()));
    /*jump to add word page*/
    connect(ui->setProblemButton,&QPushButton::clicked,[this,m_tcp,tester]()
    {
        addWordPage *addWordPageWidget=new addWordPage(tester,m_tcp);
        addWordPageWidget->show();
        this->close();
    });
    /*jump to login page*/
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
        Widget *widget=new Widget();
        QString msg="testerQuit "+(this->tester).getName();
        m_tcp->write(msg.toUtf8().data());
        m_tcp->close();
        m_tcp->deleteLater();
        widget->show();
        this->close();
    });
    /*jump to search page*/
    connect(ui->searchButton,&QPushButton::clicked,[this,m_tcp,tester](){
        searchPage* searchPageWidget=new searchPage(1,m_tcp,nullptr,tester);
        searchPageWidget->show();
        this->close();
    });
    
}

testerPage::~testerPage()
{
    delete ui;
}
