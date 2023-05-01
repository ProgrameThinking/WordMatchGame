/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 22:15:50
 * @LastEditTime: 2023-05-01 19:34:19
 * @Description: 
 */
#include "widget.h"
#include "ui_widget.h"
#include "dbUtil.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ConnectionInfo conInfo;
    setFixedSize(1080,720);
    dbUtil* con=new dbUtil();
    con->Init(conInfo);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
