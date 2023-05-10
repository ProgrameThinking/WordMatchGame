/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 19:47:23
 * @LastEditTime: 2023-05-10 23:25:08
 * @Description: player and tester will search all infomation in this page
 */
#include "searchpage.h"
#include "ui_searchpage.h"
#include <QSqlQueryModel>

searchPage::searchPage(int type,QTcpSocket* m_tcp,Player* player,Tester* tester,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
    tcp=m_tcp;
    /*send request to server*/
    connect(ui->playerButton,&QPushButton::clicked,this,searchPage::sendPlayerInfo);
    connect(ui->testerbutton,&QPushButton::clicked,this,searchPage::sendTesterInfo);
    connect(ui->searchButton,&QPushButton::clicked,this,searchPage::sendSearchInfo);
    connect(ui->numButton,&QPushButton::clicked,this,searchPage::sendSortByNum);
    connect(ui->rankButton,&QPushButton::clicked,this,searchPage::sendSortByRank);
    /*accept server info to send suitable signal*/
    connect(tcp, &QTcpSocket::readyRead, this, searchPage::sendSignal);
    /*deal with different signals*/
    connect(this,searchPage::playerInfo,this,searchPage::setPlayerInfo);
    connect(this,searchPage::testerInfo,this,searchPage::setTesterInfo);
    connect(this,searchPage::searchInfo,this,searchPage::setSearchInfo);
    connect(this,searchPage::SortByNumInfo,this,searchPage::setSortByNum);
    connect(this,searchPage::SortByRankInfo,this,searchPage::setSortByRank);

    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp,type,player,tester](){
        disconnect(tcp, &QTcpSocket::readyRead, this, searchPage::sendSignal);
        if(type==0)
        {
            /*jump to player page*/
            playerPage *playerPageWidget = new playerPage(player,m_tcp);
            playerPageWidget->show();
            this->close();
        }
        else if(type==1)
        {
            /*jump to tester page*/
            testerPage *testerPageWidge=new testerPage(tester,m_tcp);
            testerPageWidge->show();
            this->close();
        }
    });
}

searchPage::~searchPage()
{
    delete ui;
}


void searchPage::sendSearchInfo()
{
    QString sname=ui->selectCbx->currentText();
    QString input=ui->infoEdit->text();
    QString msg;
    if(isPlayer)
    {
        if(sname=="用户名")
            msg+="playerUserName "+input;
        else if(sname=="等级")
            msg+="playerRank "+input;
        else if(sname=="通关/出题数")
            msg+="playerNum "+input;
    }
    else
    {
        if(sname=="用户名")
            msg+="testerUserName "+input;
        else if(sname=="等级")
            msg+="testerRank "+input;
        else if(sname=="通关/出题数")
            msg+="testerNum "+input;
    }
    tcp->write(msg.toUtf8().data());
}
void searchPage::sendPlayerInfo()
{
    QString msg="allPlayerInfo ";
    isPlayer=true;
    tcp->write(msg.toUtf8().data());
}

void searchPage::sendTesterInfo()
{
    QString msg="allTesterInfo ";
    isPlayer=false;
    tcp->write(msg.toUtf8().data());
}

void searchPage::sendSortByNum()
{
    QString msg;
    if(isPlayer)
        msg="playerSortByNum ";
    else
        msg="testerSortByNum ";
    tcp->write(msg.toUtf8().data());
}

void searchPage::sendSortByRank()
{
    QString msg;
    if(isPlayer)
        msg="playerSortByRank ";
    else
        msg="testerSortByRank ";
    tcp->write(msg.toUtf8().data());
}

void searchPage::sendSignal()
{
    QString msg = tcp->readAll();
    qDebug() << "receive searchPage msg:" <<msg;
    QStringList info = msg.split("\n");
    if(info.at(0)=="playerInfo")
        emit playerInfo(msg);
    else if(info.at(0)=="testerInfo")
        emit testerInfo(msg);
    else if(info.at(0)=="searchPage")
        emit searchInfo(msg);
    else if(info.at(0)=="sortByNum")
        emit SortByNumInfo(msg);
    else if(info.at(0)=="sortByRank")
        emit SortByRankInfo(msg);
}

void searchPage::setSearchInfo(QString msg)
{
    if(isPlayer)
        setPlayerInfo(msg);
    else
        setTesterInfo(msg);
}

void searchPage::setPlayerInfo(QString msg)
{
    QStringList strList = msg.split("\n");
    //remove the first element
    strList.removeAt(strList.count() - 1);
    strList.removeFirst();
    //table appearance
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(strList.count());
    ui->tableWidget->setWindowTitle("玩家信息");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//read only
    ui->tableWidget->setShowGrid(true);

    QStringList header;
    header <<"玩家"<<"经验"<<"等级"<<"通关数";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    
    /*table infomation show*/
    int j = 0;
    for(int i = 0; i < strList.count(); i++)
    {
        QString str_row = strList.at(i);
        QStringList element = str_row.split(" ");//break down each piece of information

        QTableWidgetItem *item_level= new QTableWidgetItem;
        QTableWidgetItem *item_exp= new QTableWidgetItem;
        QTableWidgetItem *item_count= new QTableWidgetItem;

        ui->tableWidget->setItem(i,j,new QTableWidgetItem(element.at(0)));j++;
        //change string to number
        item_level->setData(Qt::DisplayRole,(element.at(1)).toInt());
        ui->tableWidget->setItem(i,j,item_level);j++;
        item_exp->setData(Qt::DisplayRole,(element.at(2)).toInt());
        ui->tableWidget->setItem(i,j,item_exp);j++;
        item_count->setData(Qt::DisplayRole,(element.at(3)).toInt());
        ui->tableWidget->setItem(i,j,item_count);j++;
        j=0;
    }
    ui->tableWidget->show();
}   

void searchPage::setTesterInfo(QString msg)
{
    QStringList strList = msg.split("\n");
    //remove the first element
    strList.removeAt(strList.count() - 1);
    strList.removeFirst();
    //table appearance
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(strList.count());
    ui->tableWidget->setWindowTitle("出题者信息");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//read only
    ui->tableWidget->setShowGrid(true);

    QStringList header;
    header <<"出题者"<<"经验"<<"等级"<<"出题数";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    
    //table infomation show
    int j = 0;
    for(int i = 0; i < strList.count(); i++)
    {
        QString str_row = strList.at(i);
        QStringList element = str_row.split(" ");//break down each piece of information

        QTableWidgetItem *item_level= new QTableWidgetItem;
        QTableWidgetItem *item_exp= new QTableWidgetItem;
        QTableWidgetItem *item_count= new QTableWidgetItem;

        ui->tableWidget->setItem(i,j,new QTableWidgetItem(element.at(0)));j++;
        //change string to number
        item_level->setData(Qt::DisplayRole,(element.at(1)).toInt());
        ui->tableWidget->setItem(i,j,item_level);j++;
        item_exp->setData(Qt::DisplayRole,(element.at(2)).toInt());
        ui->tableWidget->setItem(i,j,item_exp);j++;
        item_count->setData(Qt::DisplayRole,(element.at(3)).toInt());
        ui->tableWidget->setItem(i,j,item_count);j++;
        j=0;
    }
    ui->tableWidget->show();
}

void searchPage::setSortByNum(QString msg)
{
    if(isPlayer)
        setPlayerInfo(msg);
    else
        setTesterInfo(msg);
}

void searchPage::setSortByRank(QString msg)
{
    if(isPlayer)
        setPlayerInfo(msg);
    else
        setTesterInfo(msg);
}