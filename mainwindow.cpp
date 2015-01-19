#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgamedialog.h"

#include "game.h"

#include <QtDebug>

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
    this->ui->statusBar->showMessage("White: " + QString::number(white) + " Black: " + QString::number(black));
}

void MainWindow::gameOver(CELL_STATE)
{
    int whiteScore = this->game->getBoard()->getWhiteCount();
    int blackScore = this->game->getBoard()->getBlackPoints();
    if (whiteScore > blackScore) {
        this->ui->statusBar->showMessage("White wins " + QString::number(whiteScore) + " - " + QString::number(blackScore));
    }
    else if (blackScore > whiteScore) {
        this->ui->statusBar->showMessage("Black wins " + QString::number(blackScore) + " - " + QString::number(whiteScore));
    }
    else {
        this->ui->statusBar->showMessage("Tie! " + QString::number(blackScore) + " - " + QString::number(whiteScore));
    }
}

void MainWindow::on_playVsPlayer_triggered()
{
    newGameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(gameDialog.getBoardSize(), 1)));
}

void MainWindow::on_playAsWhite_triggered()
{
    newGameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(WHITE, gameDialog.getBoardSize(), 1)));
}

void MainWindow::on_playAsBlack_triggered()
{
    newGameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(BLACK, gameDialog.getBoardSize(), 1)));
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
