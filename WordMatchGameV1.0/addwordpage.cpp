#include "addwordpage.h"
#include "ui_addwordpage.h"

addWordPage::addWordPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWordPage)
{
    ui->setupUi(this);
}

addWordPage::~addWordPage()
{
    delete ui;
}
