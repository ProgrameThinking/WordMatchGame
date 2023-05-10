/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 19:47:23
 * @LastEditTime: 2023-05-10 12:32:22
 * @Description: player and tester will search all infomation in this page
 */
#include "searchpage.h"
#include "ui_searchpage.h"
#include <QSqlQueryModel>
#include "dbUtil.h"

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
    connect(m_tcp, &QTcpSocket::readyRead, this, searchPage::sendSignal);
    /*deal with different signals*/
    connect(this,searchPage::playerInfo,this,searchPage::setPlayerInfo);
    connect(this,searchPage::testerInfo,this,searchPage::setTesterInfo);
    connect(this,searchPage::searchInfo,this,searchPage::setSearchInfo);
    connect(this,searchPage::SortByNumInfo,this,searchPage::setSortByNum);
    connect(this,searchPage::SortByRankInfo,this,searchPage::setSortByRank);

    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp,type,player,tester](){
        disconnect(m_tcp, &QTcpSocket::readyRead, this, searchPage::sendSignal);
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

void searchPage::sendSignal(QString msg)
{
    QString array = tcp->readAll();
    qDebug() << "receive searchPage msg:" <<array;
    QStringList info = array.split('\n');
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

}

void searchPage::setPlayerInfo(QString msg)
{

}

void searchPage::setTesterInfo(QString msg)
{

}

void searchPage::setSortByNum(QString msg)
{

}

void searchPage::setSortByRank(QString msg)
{

}

// /**
//  * @description: when you click player button,this method will show all players' info
//  * @return {*}
//  */
// void searchPage::setPlayerTable()
// {
//     //set query model
//     QSqlQueryModel *model = new QSqlQueryModel();
//     dbUtil* dbcon=new dbUtil();
//     QSqlQuery query("select uname,exp,ranker,passnum from player");
//     model->setQuery(query);
//     ui->tableView->setModel(model);
//     model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//     model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//     model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//     model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//     isPlayer=true;
//     ui->tableView->show();
//     dbcon->close();
// }
// /**
//  * @description: when you click tester button,this method will show all testers' info
//  * @return {*}
//  */
// void searchPage::setTesterTable()
// {
//     //set query model
//     QSqlQueryModel *model = new QSqlQueryModel();
//     dbUtil* dbcon=new dbUtil();
//     QSqlQuery query("select uname,exp,ranker,quesCreatedNum from tester");
//     model->setQuery(query);
//     ui->tableView->setModel(model);
//     model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//     model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//     model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//     model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//     isPlayer=false;
//     ui->tableView->show();
//     dbcon->close();
// }
// /**
//  * @description: search input in current table
//  * @return {*}
//  */
// void searchPage::searchInfo()
// {
//     dbUtil* dbcon=new dbUtil();
//     QString sname=ui->selectCbx->currentText();
//     QString input=ui->infoEdit->text();

//     QString sql="";
//     if(isPlayer)
//     {
//         QSqlQueryModel *model = new QSqlQueryModel();
//         sql+="select uname,exp,ranker,passnum from player where ";
//         if(sname=="用户名")
//             sql+="uname='"+input+"'";
//         else if(sname=="等级")
//             sql+="ranker="+input;
//         else if(sname=="通关/出题数")
//             sql+="passNum="+input;
//         qDebug()<<sql;
//         QSqlQuery query(sql);
//         model->setQuery(query);
//         ui->tableView->setModel(model);
//         model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//         model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//         model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//         model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//         ui->tableView->show();
//     }
//     else 
//     {
//         QSqlQueryModel *model = new QSqlQueryModel();
//         sql+="select uname,exp,ranker,quesCreatedNum from tester where ";
//         if(sname=="用户名")
//             sql+="uname='"+input+"'";
//         else if(sname=="等级")
//             sql+="ranker="+input;
//         else if(sname=="通关/出题数")
//             sql+="quesCreatedNum="+input;
//         qDebug()<<sql;
//         QSqlQuery query(sql);
//         model->setQuery(query);
//         ui->tableView->setModel(model);
//         model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//         model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//         model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//         model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//         ui->tableView->show();
//     }
//     dbcon->close();
// }

// /**
//  * @description: 
//  * @return {*}
//  */
// void searchPage::sortByNum()
// {
//     dbUtil* dbcon=new dbUtil();
//     QString sql="";
//     if(isPlayer)
//     {
//         QSqlQueryModel *model = new QSqlQueryModel();
//         sql+="select uname,exp,ranker,passnum from player order by passNum desc";
//         qDebug()<<sql;
//         QSqlQuery query(sql);
//         model->setQuery(query);
//         ui->tableView->setModel(model);
//         model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//         model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//         model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//         model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//         ui->tableView->show();
//     }
//     else 
//     {
//         QSqlQueryModel *model = new QSqlQueryModel();
//         sql+="select uname,exp,ranker,quesCreatedNum from tester order by quesCreatedNum desc";
//         qDebug()<<sql;
//         QSqlQuery query(sql);
//         model->setQuery(query);
//         ui->tableView->setModel(model);
//         model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//         model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//         model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//         model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//         ui->tableView->show();
//     }
//     dbcon->close();
// }

// /**
//  * @description: 
//  * @return {*}
//  */
// void searchPage::sortByRank()
// {
//     dbUtil* dbcon=new dbUtil();
//     QString sql="";
//     if(isPlayer)
//     {
//         QSqlQueryModel *model = new QSqlQueryModel();
//         sql+="select uname,exp,ranker,passnum from player order by ranker desc,exp desc";
//         qDebug()<<sql;
//         QSqlQuery query(sql);
//         model->setQuery(query);
//         ui->tableView->setModel(model);
//         model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//         model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//         model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//         model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//         ui->tableView->show();
//     }
//     else 
//     {
//         QSqlQueryModel *model = new QSqlQueryModel();
//         sql+="select uname,exp,ranker,quesCreatedNum from tester order by ranker desc,exp desc";
//         qDebug()<<sql;
//         QSqlQuery query(sql);
//         model->setQuery(query);
//         ui->tableView->setModel(model);
//         model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
//         model->setHeaderData(1, Qt::Horizontal, tr("经验"));
//         model->setHeaderData(2, Qt::Horizontal, tr("等级"));
//         model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
//         ui->tableView->show();
//     }
//     dbcon->close();
// }