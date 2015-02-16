#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamedialog.h"
#include "game.h"
#include "settingsdialog.h"
#include "highscore.h"

#include <QtDebug>
#include <QSound>


/**
 * Constructor
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * Destructor
 *
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Score changed and status bar gets updated
 *
 * @param white
 * @param black
 */
void MainWindow::countChange(int white, int black)
{
    this->ui->statusBar->showMessage(game->getPlayerName1() + ": " + QString::number(white) + "  " + game->getPlayerName2() + ": " + QString::number(black));
}

/**
 * Game over event signal
 *
 * @param CELL_STATE
 * @param white
 * @param black
 */
void MainWindow::gameOver(CELL_STATE, int white, int black)
{
    int whiteScore = this->game->getBoard()->getWhitePoints();
    int blackScore = this->game->getBoard()->getBlackPoints();
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

/**
 * Click on Player vs. Player menue point
 *
 */
void MainWindow::on_actionPlayer_vs_Player_triggered()
{
    SettingsDialog settings(this);
    GameDialog gameDialog(this);
    gameDialog.enablePlayer2Input();
    if(gameDialog.exec()==1) {
    this->setGame(QSharedPointer<Game>(new Game(
                                          gameDialog.getBoardSize(),
                                          gameDialog.getDifficulty(),
                                          settings.settings().style,
                                          gameDialog.getPlayerName1(),
                                          gameDialog.getPlayerName2()
                                        )));
    }
}


/**
 * Click on Player vs. Computer menue point
 *
 */
void MainWindow::on_actionPlayer_vs_Computer_triggered()
{
    SettingsDialog settings(this);
    GameDialog gameDialog(this);
    if(gameDialog.exec()==1) {
    this->setGame(QSharedPointer<Game>(new Game(
                                          gameDialog.getToken(),
                                          gameDialog.getBoardSize(),
                                          gameDialog.getDifficulty(),
                                          settings.settings().style,
                                          gameDialog.getPlayerName1()
                                      )));
    }
}

/**
 * Click on settings
 *
 */
/**
 * @brief
 *
 */
void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog settings(this);
    settings.exec();
}

/**
 * Click on highscore
 *
 */
void MainWindow::on_actionHighscore_triggered()
{
    Highscore highscore(this);
    highscore.exec();
}

/**
 * Initialize slots and signal for new game
 *
 * @param game
 */
void MainWindow::setGame(QSharedPointer<Game> game)
{
    this->ui->widget->setBoard(game->getBoard());

    Game * raw = game.data();
    connect(this->ui->widget,
            SIGNAL(cellClicked(BoardPosition)),
            raw,
            SLOT(handleCellClicked(BoardPosition)));
    connect(raw,
            SIGNAL(gameOver(CELL_STATE,int,int)),
            this,
            SLOT(gameOver(CELL_STATE,int,int)));
    connect(raw,
            SIGNAL(scoreChanged(int,int)),
            this,
            SLOT(countChange(int,int)));
    this->game = game;
}

/**
 * Exit event
 *
 */
void MainWindow::on_exit_triggered()
{
    this->close();
}

/**
 * Change event (need for runtime translation but doesn't work atm)
 *
 * @param event
 */
void MainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    QMainWindow::changeEvent(event);
}
