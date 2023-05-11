/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-11 11:43:18
 * @LastEditTime: 2023-05-11 14:04:10
 * @Description: select a online player to battle
 */
#include "battleselectpage.h"
#include "ui_battleselectpage.h"
#include "playerPage.h"
#include "battlepage.h"
#include <QMessageBox>

battleSelectPage::battleSelectPage(Player* playery,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battleSelectPage)
{
    ui->setupUi(this);
    tcp=m_tcp;
    player=playery;
    QString msg="playerOnline ";
    msg+=playery->getName();
    m_tcp->write(msg.toUtf8().data());
    /*accept server info to send suitable signal*/
    connect(m_tcp, &QTcpSocket::readyRead, this, battleSelectPage::setSignals);
    connect(this,battleSelectPage::recvInfo,this,battleSelectPage::setPlayerInfo);
    connect(this,battleSelectPage::battleBeginSignal,this,battleSelectPage::battleBegin);
    connect(ui->confirmButton,&QPushButton::clicked,this,readyBattle);
    connect(ui->exitButton,&QPushButton::clicked,[this,m_tcp,playery](){
        /*jump to player page*/
        playerPage *playerPageWidget = new playerPage(playery,m_tcp);
        playerPageWidget->show();
        this->close();
    });
}

battleSelectPage::~battleSelectPage()
{
    disconnect(tcp, &QTcpSocket::readyRead, this, battleSelectPage::setSignals);
    delete ui;
}

void battleSelectPage::setSignals()
{
    QString msg = tcp->readAll();
    QStringList strList = msg.split("\n");
    qDebug() << "receive onlinePlayer msg:" <<msg;
    if(strList.at(0)=="playerOnlineRecv")
        emit recvInfo(msg);
    else if(strList.at(0)=="battleStart")
        emit battleBeginSignal(msg);
    else if(strList.at(0)=="battleRefused")
        QMessageBox::warning(this, tr("对战失败"), tr("对方拒绝与你战斗!"));
}

void battleSelectPage::setPlayerInfo(QString msg)
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
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //select whole row
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
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

void battleSelectPage::readyBattle()
{
    // 获取当前选中的行号
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    QModelIndex cellIndex = ui->tableWidget->model()->index(selectedRows.at(0).row(), 0);
    QString value = cellIndex.data().toString()+" ";
    QString msg="ballteReady "+player->getName()+" "+value;
    tcp->write(msg.toUtf8().data());
    ui->exitButton->setDisabled(true);
}

/*jump to battle page*/
void battleSelectPage::battleBegin(QString msg)
{
    QStringList strList = msg.split("\n");
    battlePage* battlePageWidget=new battlePage(strList.at(2),player,tcp);
    battlePageWidget->show();
    this->close();
}