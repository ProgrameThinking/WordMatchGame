/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 19:27:06
 * @LastEditTime: 2023-05-02 21:53:31
 * @Description: Implement some methods for adding word
 */

#include "addwordpage.h"
#include "ui_addwordpage.h"
#include "dbUtil.h"
#include "testerpage.h"
#include <QMessageBox>

addWordPage::addWordPage(Tester* testerp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWordPage)
{
    /*Pass a parameter to a private variable, and use the private tester for all next calls. */
    tester.setName(testerp->getName());
    tester.setPassword(testerp->getPassword());
    tester.setExp(testerp->getExp());
    tester.setRank(testerp->getRank());
    tester.setQuesCreatedNum(testerp->getQuesCreatedNum());

    /*real start code*/
    ui->setupUi(this);
    ui->username->setText(tester.getName());
    ui->expNum->setText(QString::number(tester.getExp()));
    ui->rankNum->setText(QString::number(tester.getRank()));
    ui->passLevel->setText(QString::number(tester.getQuesCreatedNum()));
    /*to implement add word method*/
    connect(ui->submitButton,&QPushButton::clicked,this,addWordPage::submitWord);
    connect(ui->exitButton,&QPushButton::clicked,[this](){
        /*jump to tester page*/
        testerPage *testerPageWidge=new testerPage(&tester);
        testerPageWidge->show();
        this->close();
    });
}

addWordPage::~addWordPage()
{
    delete ui;
}

/**
 * @description: in this method,I will update tester's info and add word if same word isn't in question bank
 * @return {*}
 */
void addWordPage::submitWord()
{
    QString word=ui->answerEdit->text();
    int difficuty=(int)((1+(word.length()-3)/2)+0.5);
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query;
    QString sql="insert into vocabulary (word, difficulty) VALUES ('";
    sql+=word+"',"+QString::number(difficuty)+")";
    qDebug()<<sql;
    if(query.exec(sql))
    {
        tester.addExp(tester.calExp(word.length()));
        tester.setQuesCreatedNum(tester.getQuesCreatedNum()+1);
        QMessageBox::information(this, tr("添加成功"), tr("添加成功"));
        /*update tester's info*/
        ui->username->setText(tester.getName());
        ui->expNum->setText(QString::number(tester.getExp()));
        ui->rankNum->setText(QString::number(tester.getRank()));
        ui->passLevel->setText(QString::number(tester.getQuesCreatedNum()));
        /*update tester's info in database*/
        query.prepare("update tester set exp = ?, ranker = ?, quesCreatedNum = ? where uname = ? and pwd = ?");
        query.bindValue(0, tester.getExp());
        query.bindValue(1, tester.getRank());
        query.bindValue(2, tester.getQuesCreatedNum());
        query.bindValue(3, tester.getName());
        query.bindValue(4, tester.getPassword());
        query.exec();
    }
    else
        QMessageBox::warning(this, tr("添加失败"), tr("该单词已存在题库中！"));
}