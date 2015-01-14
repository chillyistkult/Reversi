#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Settings.h"

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
    this->setGame(QSharedPointer<Game>(new Game()));
}

void MainWindow::on_playAsWhite_triggered()
{
    this->setGame(QSharedPointer<Game>(new Game(WHITE)));
}

void MainWindow::on_playAsBlack_triggered()
{
    this->setGame(QSharedPointer<Game>(new Game(BLACK)));
}

void MainWindow::on_settings_triggered()
{
    Settings * widget = new Settings();
    widget->setAttribute(Qt::WA_DeleteOnClose);

    widget->setDifficulty(options.difficulty);

    connect(widget,
            SIGNAL(optionsChanged(Options)),
            this,
            SLOT(changeOptions(Options)));

    widget->show();
}

void MainWindow::changeOptions(Options options)
{
    if (game.isNull()) {
        return;
    }
    this->options = options;
    game->setDifficulty(options.difficulty);
}

void MainWindow::setGame(QSharedPointer<Game> game)
{
    if (game.isNull()) {
        return;
    }

    this->changeOptions(this->options);

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
