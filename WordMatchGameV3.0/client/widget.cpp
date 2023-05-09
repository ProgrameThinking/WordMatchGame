/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 22:15:50
 * @LastEditTime: 2023-05-09 17:52:29
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
#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setFixedSize(1080,720);
    ui->setupUi(this);

    /*initiate the connection of client and server*/
    connectServer();
    //connect successfully
    connect(this,&Widget::connectOK,this,[=](){
        QMessageBox::information(this,"连接服务器","已经成功链接服务器，恭喜！");
    });
    /*jump to registration*/
    connect(ui->registrationButton,&QPushButton::clicked,[this](){
        registration *registrationWidget = new registration(m_tcp);
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
            QString msg="playerLogin "+username+" "+password;
            m_tcp->write(msg.toUtf8().data());
            //After receiving the information from the server, a ready signal will be sent
            connect(m_tcp, &QTcpSocket::readyRead, this, &Widget::playerLogin);
        }
        else if(type=="出题者")
        {
            QString msg="testerLogin "+username+" "+password;
            m_tcp->write(msg.toUtf8().data());
            //After receiving the information from the server, a ready signal will be sent
            connect(m_tcp, &QTcpSocket::readyRead, this, &Widget::testerLogin);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectServer()
{
    m_tcp=new QTcpSocket;
    m_tcp->connectToHost(QHostAddress(ip),port);
    connect(m_tcp,&QTcpSocket::connected,this,&Widget::connectOK);
    connect(m_tcp,&QTcpSocket::disconnected,this,[=](){
        qDebug()<<"已经与服务器断开连接!";
        m_tcp->close();
        m_tcp->deleteLater();
        emit connectOver();
    });
}

void Widget::playerLogin()
{
    QString array = m_tcp->readAll();
    qDebug() << "receive msg:" <<array;
    QStringList info = array.split(' ');
    if(info.at(0)=="playerLoginBack")
    {
        if(info.at(1)=="0")         
            QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码有误或用户已登录"));
        else if(info.at(1)=="1")    //username and pwd are correct
        {
            /*jump to player page*/
            QString username=ui->unameText->toPlainText();
            QString password=ui->pwdText->toPlainText();
            Player* player=new Player(username,password,info.at(4).toDouble(),info.at(5).toInt(),info.at(6).toInt());
            playerPage *playerPageWidget = new playerPage(player,m_tcp);
            playerPageWidget->show();
            this->close();
            QMessageBox::information(this, tr("登录成功"), tr("登录成功"));
        }
    }
}

void Widget::testerLogin()
{
    QString array = m_tcp->readAll();
    qDebug() << "receive msg:" <<array;
    QStringList info = array.split(' ');
    if(info.at(0)=="testerLoginBack")
    {
        if(info.at(1)=="0")         
            QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码有误或用户已登录"));
        else if(info.at(1)=="1")    //username and pwd are correct
        {
            /*jump to player page*/
            QString username=ui->unameText->toPlainText();
            QString password=ui->pwdText->toPlainText();
            Tester* tester=new Tester(username,password,info.at(4).toDouble(),info.at(5).toInt(),info.at(6).toInt());
            testerPage *testerPageWidget = new testerPage(tester,m_tcp);
            testerPageWidget->show();
            this->close();
            QMessageBox::information(this, tr("登录成功"), tr("登录成功"));
        }
    }
}