#include "searchpage.h"
#include "ui_searchpage.h"

searchPage::searchPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
}

searchPage::~searchPage()
{
    delete ui;
}
