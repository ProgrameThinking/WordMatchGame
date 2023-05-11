/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 12:10:01
 * @LastEditTime: 2023-05-11 13:49:59
 * @Description: users' registation
 */
#include "registration.h"
#include "ui_registration.h"
#include "playerpage.h"
#include "testerpage.h"
#include "member.h"
#include <QMessageBox>
#include "widget.h"

registration::registration(QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    setFixedSize(1080,720);
    tcp=m_tcp;
    /*jump to login page*/
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp](){
        disconnect(tcp, &QTcpSocket::readyRead, this, registration::transPage);
        Widget *widget=new Widget();
        widget->show();
        m_tcp->close();
        m_tcp->deleteLater();
        this->close();
    });
    connect(ui->confirmButton,&QPushButton::clicked,this,userRegister);
    /*accept server info to send suitable signal*/
    connect(tcp, &QTcpSocket::readyRead, this, registration::transPage);
}

registration::~registration()
{
    delete ui;
}

void registration::userRegister()
{
    QString msg="";
    QString username=ui->unameText->toPlainText();
    QString pwd=ui->pwdText->toPlainText();
    QString type=ui->typeCbx->currentText();
    if(type=="玩家")
        msg+="playerRegistation ";
    else if(type=="出题者")
        msg+="testerRegistation ";
    msg+=username+" "+pwd+" ";
    tcp->write(msg.toUtf8().data());
}

void registration::transPage()
{
    QString msg = tcp->readAll();
    qDebug() << "receive registation msg:" <<msg;
    QStringList info = msg.split(" ");
    if(info.at(0)=="playerRegistationRecv")
    {
        if(info.at(1)=="1")
        {
            /*jump to player page*/
            Player* player=new Player(info.at(2),info.at(3),0,0,0);
            playerPage *playerPageWidget = new playerPage(player,tcp);
            playerPageWidget->show();
            this->close();
        }
        else if(info.at(1)=="0")
            QMessageBox::warning(this, tr("注册失败"), tr("用户名重复！"));
    }
    else if(info.at(0)=="testerRegistationRecv")
    {
        if(info.at(1)=="1")
        {
            /*jump to tester page*/
            Tester* tester=new Tester(info.at(2),info.at(3),0,0,0);
            testerPage *testerPageWidge=new testerPage(tester,tcp);
            testerPageWidge->show();
            this->close();
        }
        else if(info.at(1)=="0")
            QMessageBox::warning(this, tr("注册失败"), tr("用户名重复！"));
    }
}