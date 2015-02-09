#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamedialog.h"
#include "game.h"
#include "settingsdialog.h"
#include "highscore.h"

#include <QtDebug>
#include <QSound>


//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    QAction *highscoreAction = ui->menuBar->addAction("Highscore");
    connect(highscoreAction, SIGNAL(triggered()), this, SLOT(on_highscore_triggered()));

}

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//Score changed and status bar gets updated
void MainWindow::countChange(int white, int black)
{
    this->ui->statusBar->showMessage(game->getPlayerName1() + ": " + QString::number(white) + "  " + game->getPlayerName2() + ": " + QString::number(black));
}

//Game over event signal
void MainWindow::gameOver(CELL_STATE)
{
    int whiteScore = this->game->getBoard()->getWhiteCount();
    int blackScore = this->game->getBoard()->getBlackPoints();
    if(this->game->getPlayersToken() == WHITE) {
        if (whiteScore > blackScore) {
            QSound::play(":/sound/win.wav");
            this->ui->statusBar->showMessage(game->getPlayerName1() + tr(" wins with ") + QString::number(whiteScore) + " - " + QString::number(blackScore));
        }
        else if (blackScore > whiteScore) {
            QSound::play(":/sound/gameover.wav");
            this->ui->statusBar->showMessage(game->getPlayerName2() + tr(" wins with ") + QString::number(blackScore) + " - " + QString::number(whiteScore));
        }
        else {
            this->ui->statusBar->showMessage("Draw! " + QString::number(blackScore) + " - " + QString::number(whiteScore));
        }
    }
}

//Click on Player vs. Player menue point
void MainWindow::on_actionPlayer_vs_Player_triggered()
{
    SettingsDialog settings(this);
    GameDialog gameDialog(this);
    gameDialog.enablePlayer2Input();
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(
                                          gameDialog.getBoardSize(),
                                          gameDialog.getDifficulty(),
                                          settings.settings().style,
                                          gameDialog.getPlayerName1(),
                                          gameDialog.getPlayerName2()
                                        )));
}

//Click on Player vs. Computer menue point
void MainWindow::on_actionPlayer_vs_Computer_triggered()
{
    SettingsDialog settings(this);
    GameDialog gameDialog(this);
    gameDialog.exec();
    this->setGame(QSharedPointer<Game>(new Game(
                                          gameDialog.getToken(),
                                          gameDialog.getBoardSize(),
                                          gameDialog.getDifficulty(),
                                          settings.settings().style,
                                          gameDialog.getPlayerName1()
                                      )));
}

//Click on settings
void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog settings(this);
    settings.exec();
}

//Click on settings
void MainWindow::on_highscore_triggered()
{
    Highscore highscore(this);
    highscore.exec();
}

//Initialize slots and signal for new game
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

//Exit event
void MainWindow::on_exit_triggered()
{
    this->close();
}

void MainWindow::on_progressBar_destroyed()
{

}

//Update progress bar event
void MainWindow::updateProgressBar(int value) {
    this->ui->progressBar->setValue(value);
}

void MainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }

    QMainWindow::changeEvent(event);
}
