#include "gamedialog.h"
#include "ui_gamedialog.h"
#include<QDebug>

/**
 * Constructor
 *
 * @param parent
 */
GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Play!"));
}

/**
 * Destructor
 *
 */
GameDialog::~GameDialog()
{
    delete ui;
}

/**
 * Get the ai difficulty
 *
 * @return int
 */
int GameDialog::getDifficulty() {
    return settings.difficulty;
}

/**
 * Get the configured board size
 *
 * @return int
 */
int GameDialog::getBoardSize() {
    return settings.boardSize;
}

/**
 * Get the token which indicates who start the game
 *
 * @return CELL_STATE
 */
CELL_STATE GameDialog::getToken() {
    if(this->ui->player1CheckBox->checkState()) {
        return BLACK;
    }
    else {
        return WHITE;
    }
}

/**
 * Get the name of player 1
 *
 * @return QString
 */
QString GameDialog::getPlayerName1() {
    return playerName1;
}

/**
 * Get the name of player 2
 *
 * @return QString
 */
QString GameDialog::getPlayerName2() {
    return playerName2;
}

/**
 * Enables the input for a second player if the game mode is player vs player
 *
 */
void GameDialog::enablePlayer2Input() {
    this->ui->playerName2Edit->setEnabled(true);
}

/**
 * Save event
 *
 */
void GameDialog::on_buttonBox_accepted()
{
    playerName1 = this->ui->playerName1Edit->text();
    playerName2 = this->ui->playerName2Edit->text();
}

/**
 * Board size changed event (slider)
 *
 * @param value
 */
void GameDialog::on_boardSizeSlider_valueChanged(int value)
{
    this->ui->boardSizeValueLabel->setText(QString::number(this->ui->boardSizeSlider->value()));
    settings.boardSize = this->ui->boardSizeSlider->value();
}

/**
 * AI difficulty box changed event
 *
 * @param index
 */
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

/**
 * Player 1 checkbox clicked
 *
 * @param checked
 */
void GameDialog::on_player1CheckBox_clicked(bool checked)
{
    if(!checked && !this->ui->player1CheckBox->checkState()) {
        this->ui->player2CheckBox->setChecked(true);
    }
    else {
        this->ui->player2CheckBox->setChecked(false);
    }
}

/**
 * Player 2 checkbox clicked
 *
 * @param checked
 */
void GameDialog::on_player2CheckBox_clicked(bool checked)
{
    if(!checked && !this->ui->player2CheckBox->checkState()) {
        this->ui->player1CheckBox->setChecked(true);
    }
    else {
        this->ui->player1CheckBox->setChecked(false);
    }
}
