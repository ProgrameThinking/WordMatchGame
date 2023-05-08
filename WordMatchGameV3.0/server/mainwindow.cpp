/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 20:55:48
 * @LastEditTime: 2023-05-08 21:53:46
 * @Description: 
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server  = new MyServer(this, port);
}

MainWindow::~MainWindow()
{
    delete ui;
}


