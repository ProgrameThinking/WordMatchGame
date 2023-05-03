/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 22:15:50
 * @LastEditTime: 2023-05-03 14:39:38
 * @Description: main window
 */
#include "widget.h"
#include "ui_widget.h"
#include "registration.h"
#include "player.h"
#include "tester.h"
#include "playerpage.h"
#include "testerpage.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setFixedSize(1080,720);
    ui->setupUi(this);

    /*jump to registration*/
    connect(ui->registrationButton,&QPushButton::clicked,[this](){
        registration *registrationWidget = new registration();
        registrationWidget->show();
        this->close();
    });
    /*login authentication*/
    connect(ui->loginButton,&QPushButton::clicked,[this](){
        QString username=ui->unameText->toPlainText();
        QString password=ui->pwdText->toPlainText();
        QString type=ui->typeCbx->currentText();
        if(type=="玩家")
        {
            Player* player=new Player(username,password);
            if(player->login())
            {
                /*jump to player page*/
                playerPage *playerPageWidget = new playerPage(player);
                playerPageWidget->show();
                this->close();
                QMessageBox::information(this, tr("登录成功"), tr("登录成功"));
            }
            else
                QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码有误"));
        }
        else if(type=="出题者")
        {
            Tester* tester=new Tester(username,password);
            if(tester->login())
            {
                /*jump to tester page*/
                testerPage *testerPageWidge=new testerPage(tester);
                testerPageWidge->show();
                this->close();
                QMessageBox::information(this, tr("登录成功"), tr("登录成功"));
            }
            else
                QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码有误"));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
