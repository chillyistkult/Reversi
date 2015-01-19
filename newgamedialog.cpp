#include "newgamedialog.h"
#include "ui_newgamedialog.h"
#include<QDebug>

newGameDialog::newGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newGameDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Play!"));
}

newGameDialog::~newGameDialog()
{
    delete ui;
}

int newGameDialog::getDifficulty() {
    return settings.difficulty;
}

int newGameDialog::getBoardSize() {
    return settings.boardSize;
}

void newGameDialog::on_buttonBox_accepted()
{
    playerName1 = this->ui->playerNameEdit->text();
}

void newGameDialog::on_buttonBox_rejected()
{

}

void newGameDialog::on_boardSizeSlider_valueChanged(int value)
{
    this->ui->boardSizeValueLabel->setText(QString::number(this->ui->boardSizeSlider->value()));
    settings.boardSize = this->ui->boardSizeSlider->value();
}

void newGameDialog::on_difficultyBox_currentIndexChanged(int index)
{
    switch(index) {
        case 0:
            settings.difficulty = 1;
            break;
        case 1:
            settings.difficulty = 5;
            break;
        case 2:
            settings.difficulty = 8;
            break;
        case 3:
            settings.difficulty = 12;
            break;
        default:
            break;
    }
}
