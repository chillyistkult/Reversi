#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamedialog.h"
#include "game.h"
#include "settingsdialog.h"

#include <QtDebug>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countChange(int white, int black)
{
    this->ui->statusBar->showMessage(game->getPlayerName1() + ": " + QString::number(white) + "  " + game->getPlayerName2() + ": " + QString::number(black));
}

void MainWindow::gameOver(CELL_STATE)
{
    int whiteScore = this->game->getBoard()->getWhiteCount();
    int blackScore = this->game->getBoard()->getBlackPoints();
    if(this->game->getPlayersToken() == WHITE) {
        if (whiteScore > blackScore) {
            QSound::play(":/sound/win.wav");
            this->ui->statusBar->showMessage(game->getPlayerName1() + " wins with " + QString::number(whiteScore) + " - " + QString::number(blackScore));
        }
        else if (blackScore > whiteScore) {
            QSound::play(":/sound/gameover.wav");
            this->ui->statusBar->showMessage(game->getPlayerName2() + " wins with " + QString::number(blackScore) + " - " + QString::number(whiteScore));
        }
        else {
            this->ui->statusBar->showMessage("Draw! " + QString::number(blackScore) + " - " + QString::number(whiteScore));
        }
    }
}

void MainWindow::on_actionPlayer_vs_Player_triggered()
{
    SettingsDialog settings(this);
    GameDialog gameDialog(this);
    gameDialog.enablePlayer2Input();
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(gameDialog.getBoardSize(),gameDialog.getDifficulty(), settings.settings().style,gameDialog.getPlayerName1(),gameDialog.getPlayerName2())));
}

void MainWindow::on_actionPlayer_vs_Computer_triggered()
{
    SettingsDialog settings(this);
    GameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(gameDialog.getToken(),gameDialog.getBoardSize(),gameDialog.getDifficulty(), settings.settings().style,gameDialog.getPlayerName1())));
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog settings(this);
    settings.exec();
}

void MainWindow::setGame(QSharedPointer<Game> game)
{
    this->ui->widget->setBoard(game->getBoard());

    Game * raw = game.data();
    connect(this->ui->widget,
            SIGNAL(cellClicked(BoardPosition)),
            raw,
            SLOT(handleCellClicked(BoardPosition)));
    connect(raw,
            SIGNAL(gameOver(CELL_STATE)),
            this,
            SLOT(gameOver(CELL_STATE)));
    connect(raw,
            SIGNAL(scoreChanged(int,int)),
            this,
            SLOT(countChange(int,int)));
    connect(raw,
            SIGNAL( updateProgress(int) ),
            this->ui->progressBar,
            SLOT( setValue(int) ) );
    this->game = game;
}

void MainWindow::on_exit_triggered()
{
    this->close();
}

void MainWindow::on_progressBar_destroyed()
{

}

void MainWindow::updateProgressBar(int value) {
    this->ui->progressBar->setValue(value);
}
