/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 12:10:01
 * @LastEditTime: 2023-05-02 14:28:30
 * @Description: 
 */
#include "registration.h"
#include "ui_registration.h"
#include "member.h"
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    setFixedSize(1080,720);

    /*implement registration*/
    connect(ui->confirmButton,&QPushButton::clicked,[this](){
        QString username=ui->unameText->toPlainText();
        QString pwd=ui->pwdText->toPlainText();
        QString type=ui->typeCbx->currentText();
        Member* temp=new Member(username,pwd);
        /*sucessful insertion will jump to logging in page*/
        if(temp->userRegister(type))
        {
            QMessageBox::information(this, tr("注册成功!"), tr("转入登录后界面!"));
        }
        /*failed insertion will alart and log error info*/
        else
            QMessageBox::warning(this, tr("注册失败"), tr("用户名重复！"));
    });
}

registration::~registration()
{
    delete ui;
}
