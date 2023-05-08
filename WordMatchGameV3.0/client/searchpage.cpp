#include "searchpage.h"
#include "ui_searchpage.h"
#include <QSqlQueryModel>
#include "dbUtil.h"

searchPage::searchPage(int type,Player* player,Tester* tester,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
    connect(ui->playerButton,&QPushButton::clicked,this,searchPage::setPlayerTable);
    connect(ui->testerbutton,&QPushButton::clicked,this,searchPage::setTesterTable);
    connect(ui->searchButton,&QPushButton::clicked,this,searchPage::searchInfo);
    connect(ui->exitButton,&QPushButton::clicked,[this,type,player,tester](){
        if(type==0)
        {
            /*jump to player page*/
            playerPage *playerPageWidget = new playerPage(player);
            playerPageWidget->show();
            this->close();
        }
        else if(type==1)
        {
            /*jump to tester page*/
            testerPage *testerPageWidge=new testerPage(tester);
            testerPageWidge->show();
            this->close();
        }
    });
    connect(ui->numButton,&QPushButton::clicked,this,searchPage::sortByNum);
    connect(ui->rankButton,&QPushButton::clicked,this,searchPage::sortByRank);
}

searchPage::~searchPage()
{
    delete ui;
}


/**
 * @description: when you click player button,this method will show all players' info
 * @return {*}
 */
void searchPage::setPlayerTable()
{
    //set query model
    QSqlQueryModel *model = new QSqlQueryModel();
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query("select uname,exp,ranker,passnum from player");
    model->setQuery(query);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
    model->setHeaderData(1, Qt::Horizontal, tr("经验"));
    model->setHeaderData(2, Qt::Horizontal, tr("等级"));
    model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
    isPlayer=true;
    ui->tableView->show();
    dbcon->close();
}
/**
 * @description: when you click tester button,this method will show all testers' info
 * @return {*}
 */
void searchPage::setTesterTable()
{
    //set query model
    QSqlQueryModel *model = new QSqlQueryModel();
    dbUtil* dbcon=new dbUtil();
    QSqlQuery query("select uname,exp,ranker,quesCreatedNum from tester");
    model->setQuery(query);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
    model->setHeaderData(1, Qt::Horizontal, tr("经验"));
    model->setHeaderData(2, Qt::Horizontal, tr("等级"));
    model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
    isPlayer=false;
    ui->tableView->show();
    dbcon->close();
}
/**
 * @description: search input in current table
 * @return {*}
 */
void searchPage::searchInfo()
{
    dbUtil* dbcon=new dbUtil();
    QString sname=ui->selectCbx->currentText();
    QString input=ui->infoEdit->text();

    QString sql="";
    if(isPlayer)
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        sql+="select uname,exp,ranker,passnum from player where ";
        if(sname=="用户名")
            sql+="uname='"+input+"'";
        else if(sname=="等级")
            sql+="ranker="+input;
        else if(sname=="通关/出题数")
            sql+="passNum="+input;
        qDebug()<<sql;
        QSqlQuery query(sql);
        model->setQuery(query);
        ui->tableView->setModel(model);
        model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
        model->setHeaderData(1, Qt::Horizontal, tr("经验"));
        model->setHeaderData(2, Qt::Horizontal, tr("等级"));
        model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
        ui->tableView->show();
    }
    else 
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        sql+="select uname,exp,ranker,quesCreatedNum from tester where ";
        if(sname=="用户名")
            sql+="uname='"+input+"'";
        else if(sname=="等级")
            sql+="ranker="+input;
        else if(sname=="通关/出题数")
            sql+="quesCreatedNum="+input;
        qDebug()<<sql;
        QSqlQuery query(sql);
        model->setQuery(query);
        ui->tableView->setModel(model);
        model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
        model->setHeaderData(1, Qt::Horizontal, tr("经验"));
        model->setHeaderData(2, Qt::Horizontal, tr("等级"));
        model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
        ui->tableView->show();
    }
    dbcon->close();
}

/**
 * @description: 
 * @return {*}
 */
void searchPage::sortByNum()
{
    dbUtil* dbcon=new dbUtil();
    QString sql="";
    if(isPlayer)
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        sql+="select uname,exp,ranker,passnum from player order by passNum desc";
        qDebug()<<sql;
        QSqlQuery query(sql);
        model->setQuery(query);
        ui->tableView->setModel(model);
        model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
        model->setHeaderData(1, Qt::Horizontal, tr("经验"));
        model->setHeaderData(2, Qt::Horizontal, tr("等级"));
        model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
        ui->tableView->show();
    }
    else 
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        sql+="select uname,exp,ranker,quesCreatedNum from tester order by quesCreatedNum desc";
        qDebug()<<sql;
        QSqlQuery query(sql);
        model->setQuery(query);
        ui->tableView->setModel(model);
        model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
        model->setHeaderData(1, Qt::Horizontal, tr("经验"));
        model->setHeaderData(2, Qt::Horizontal, tr("等级"));
        model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
        ui->tableView->show();
    }
    dbcon->close();
}

/**
 * @description: 
 * @return {*}
 */
void searchPage::sortByRank()
{
    dbUtil* dbcon=new dbUtil();
    QString sql="";
    if(isPlayer)
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        sql+="select uname,exp,ranker,passnum from player order by ranker desc,exp desc";
        qDebug()<<sql;
        QSqlQuery query(sql);
        model->setQuery(query);
        ui->tableView->setModel(model);
        model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
        model->setHeaderData(1, Qt::Horizontal, tr("经验"));
        model->setHeaderData(2, Qt::Horizontal, tr("等级"));
        model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
        ui->tableView->show();
    }
    else 
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        sql+="select uname,exp,ranker,quesCreatedNum from tester order by ranker desc,exp desc";
        qDebug()<<sql;
        QSqlQuery query(sql);
        model->setQuery(query);
        ui->tableView->setModel(model);
        model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
        model->setHeaderData(1, Qt::Horizontal, tr("经验"));
        model->setHeaderData(2, Qt::Horizontal, tr("等级"));
        model->setHeaderData(3, Qt::Horizontal, tr("通关数"));
        ui->tableView->show();
    }
    dbcon->close();
}