/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 19:27:06
 * @LastEditTime: 2023-05-12 13:56:25
 * @Description: Implement some methods for adding word
 */

#include "addwordpage.h"
#include "ui_addwordpage.h"
#include "testerpage.h"
#include <QMessageBox>

addWordPage::addWordPage(Tester* testerp,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWordPage)
{
    /*Pass a parameter to a private variable, and use the private tester for all next calls. */
    tester.setName(testerp->getName());
    tester.setPassword(testerp->getPassword());
    tester.setExp(testerp->getExp());
    tester.setRank(testerp->getRank());
    tester.setQuesCreatedNum(testerp->getQuesCreatedNum());
    tcp=m_tcp;
    /*real start code*/
    ui->setupUi(this);
    ui->username->setText(tester.getName());
    ui->expNum->setText(QString::number(tester.getExp()));
    ui->rankNum->setText(QString::number(tester.getRank()));
    ui->passLevel->setText(QString::number(tester.getQuesCreatedNum()));
    /*to implement add word method*/
    connect(ui->submitButton,&QPushButton::clicked,this,addWordPage::sentword);
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
        /*jump to tester page*/
        testerPage *testerPageWidge=new testerPage(&tester,m_tcp);
        disconnect(tcp, &QTcpSocket::readyRead, this, addWordPage::wordRecv);
        testerPageWidge->show();
        this->close();
    });
    //After receiving the information from the server, a ready signal will be sent
    connect(tcp, &QTcpSocket::readyRead, this, addWordPage::wordRecv);
}

addWordPage::~addWordPage()
{
    delete ui;
}

void addWordPage::sentword()
{
    QString word=ui->answerEdit->text();
    int difficuty=(int)((1+(word.length()-3)/2)+0.5);
    QString msg="testerAddWord "+word+" "+QString::number(difficuty);
    tcp->write(msg.toUtf8().data());
}

void addWordPage::wordRecv()
{
    QString array = tcp->readAll();
    QString word=ui->answerEdit->text();
    qDebug() << "receive word receive msg:" <<array;
    QStringList info = array.split(' ');
    if(info.at(0)=="testerWordRecv")
    {
        if(info.at(1)=="0")
            QMessageBox::warning(this, tr("添加失败"), tr("该单词已存在题库中！"));
        else if(info.at(1)=="1")
        {
            tester.addExp(tester.calExp(word.length()));
            tester.setQuesCreatedNum(tester.getQuesCreatedNum()+1);
            QMessageBox::information(this, tr("添加成功"), tr("添加成功"));
            /*update tester's info*/
            ui->username->setText(tester.getName());
            ui->expNum->setText(QString::number(tester.getExp()));
            ui->rankNum->setText(QString::number(tester.getRank()));
            ui->passLevel->setText(QString::number(tester.getQuesCreatedNum()));
            /*update tester info in server*/
            QString msg="testerUpdate "+tester.getName()+" "+QString::number(tester.getExp())+" "+QString::number(tester.getRank())+" "+QString::number(tester.getQuesCreatedNum());
            tcp->write(msg.toUtf8().data());
        }
        ui->answerEdit->setText("");
    }
}
