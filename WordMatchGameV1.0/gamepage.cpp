#include "gamepage.h"
#include "ui_gamepage.h"

gamePage::gamePage(Player* playery,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamePage)
{
    ui->setupUi(this);
}

gamePage::~gamePage()
{
    delete ui;
}
