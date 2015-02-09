#include "highscore.h"
#include "ui_highscore.h"

Highscore::Highscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Highscore)
{
    ui->setupUi(this);
}

Highscore::~Highscore()
{
    delete ui;
}
