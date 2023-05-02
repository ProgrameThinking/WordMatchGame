#include "testerpage.h"
#include "ui_testerpage.h"

testerPage::testerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testerPage)
{
    ui->setupUi(this);
}

testerPage::~testerPage()
{
    delete ui;
}
