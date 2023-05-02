/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 15:06:44
 * @LastEditTime: 2023-05-02 19:49:05
 * @Description: Implement some methods about players
 */
#include "playerpage.h"
#include "ui_playerpage.h"

playerPage::playerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPage)
{
    ui->setupUi(this);
}

playerPage::~playerPage()
{
    delete ui;
}
