#include "battlepage.h"
#include "ui_battlepage.h"

battlePage::battlePage(QString opponent,Player* playery,QTcpSocket* m_tcp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlePage)
{
    ui->setupUi(this);
}

battlePage::~battlePage()
{
    delete ui;
}
