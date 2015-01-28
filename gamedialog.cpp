#include "gamedialog.h"
#include "ui_gamedialog.h"
#include<QDebug>

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Play!"));
}

GameDialog::~GameDialog()
{
    delete ui;
}

int GameDialog::getDifficulty() {
    return settings.difficulty;
}

int GameDialog::getBoardSize() {
    return settings.boardSize;
}

CELL_STATE GameDialog::getToken() {
    if(this->ui->player1CheckBox->checkState()) {
        return BLACK;
    }
    else {
        return WHITE;
    }
}

QString GameDialog::getPlayerName1() {
    return playerName1;
}

QString GameDialog::getPlayerName2() {
    return playerName2;
}

void GameDialog::enablePlayer2Input() {
    this->ui->playerName2Edit->setEnabled(true);
}

void GameDialog::on_buttonBox_accepted()
{
    playerName1 = this->ui->playerName1Edit->text();
    playerName2 = this->ui->playerName2Edit->text();
}

void GameDialog::on_boardSizeSlider_valueChanged(int value)
{
    this->ui->boardSizeValueLabel->setText(QString::number(this->ui->boardSizeSlider->value()));
    settings.boardSize = this->ui->boardSizeSlider->value();
}

void GameDialog::on_difficultyBox_currentIndexChanged(int index)
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

void GameDialog::on_player1CheckBox_clicked(bool checked)
{
    if(!checked && !this->ui->player1CheckBox->checkState()) {
        this->ui->player2CheckBox->setChecked(true);
    }
    else {
        this->ui->player2CheckBox->setChecked(false);
    }
}

void GameDialog::on_player2CheckBox_clicked(bool checked)
{
    if(!checked && !this->ui->player2CheckBox->checkState()) {
        this->ui->player1CheckBox->setChecked(true);
    }
    else {
        this->ui->player1CheckBox->setChecked(false);
    }
}
