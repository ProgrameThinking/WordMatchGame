/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 22:15:50
 * @LastEditTime: 2023-05-01 19:53:42
 * @Description: 
 */
#include "widget.h"
#include "ui_widget.h"
#include "dbutil.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setFixedSize(1080,720);
    ui->setupUi(this);
    dbUtil* con=new dbUtil();
}

Widget::~Widget()
{
    delete ui;
}
