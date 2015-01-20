#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamedialog.h"
#include "game.h"

#include <QtDebug>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    if (whiteScore > blackScore) {
        if(this->game->getPlayersToken() == WHITE) {
                QSound::play(":/sound/win.wav");
        }
        this->ui->statusBar->showMessage("White wins " + QString::number(whiteScore) + " - " + QString::number(blackScore));
    }
    else if (blackScore > whiteScore) {
        this->ui->statusBar->showMessage("Black wins " + QString::number(blackScore) + " - " + QString::number(whiteScore));
    }
    else {
        this->ui->statusBar->showMessage("Tie! " + QString::number(blackScore) + " - " + QString::number(whiteScore));
    }
}

void MainWindow::on_actionPlayer_vs_Player_triggered()
{
    GameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(gameDialog.getBoardSize(),gameDialog.getDifficulty(),gameDialog.getPlayerName1(),gameDialog.getPlayerName2())));
}

void MainWindow::on_actionPlayer_vs_Computer_triggered()
{
    GameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(gameDialog.getToken(),gameDialog.getBoardSize(),gameDialog.getDifficulty(),gameDialog.getPlayerName1())));
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
            this->game = game;
    connect(raw,
            SIGNAL(scoreChanged(int,int)),
            this,
            SLOT(countChange(int,int)));
}

void MainWindow::on_exit_triggered()
{
    this->close();
}
