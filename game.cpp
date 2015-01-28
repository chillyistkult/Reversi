#include "game.h"
#include "gamedialog.h"
#include "settingsdialog.h"

#include <QTimer>
#include <QtGlobal>
#include <QtDebug>



Game::Game(int boardSize, int difficulty, int style, QString playerName1, QString playerName2)
{
    this->playerName1 = playerName1;
    this->playerName2 = playerName2;
    this->difficulty = difficulty;
    this->setBoard(QSharedPointer<Board>(new Board(boardSize, style)));
}


Game::Game(CELL_STATE player, int boardSize, int difficulty, int style, QString playerName1) : player(player)
{
    this->playerName1 = playerName1;
    this->playerName2 = "Computer";
    this->player = player;
    this->difficulty = difficulty;
    this->setBoard(QSharedPointer<Board>(new Board(boardSize, style)));
    if (player == WHITE) {
        this->aiPlayer = BLACK;
    }
    if (player == BLACK) {
        this->aiPlayer = WHITE;
    }
    this->handleTurnTaken(WHITE,this->getBoard()->getWhoIsNext());
}

Game::~Game()
{

}

QSharedPointer<Board> Game::getBoard() const
{
    return this->board;
}

CELL_STATE Game::getPlayersToken() {
    return this->player;
}

QString Game::getPlayerName1() {
    return this->playerName1;
}

QString Game::getPlayerName2() {
    return this->playerName2;
}


void Game::handleCellClicked(BoardPosition where)
{
    this->board->makeMove(where, this->board->getWhoIsNext());
}

void Game::handleTurnTaken(CELL_STATE byWhom, CELL_STATE nextTurn)
{
    qDebug() << this->getBoard()->getScore();
    Q_UNUSED(byWhom);
    if (this->getBoard()->isGameOver()) {
        return;
    }
    if (nextTurn == this->aiPlayer)
    {
        QTimer::singleShot(50,this,SLOT(makeAIMove()));
    }
}

void Game::handleGameOver(CELL_STATE winner)
{
    //this->gameOver(winner);
}

void Game::handleScoreChanged(int white, int black)
{
    //this->scoreChanged(white,black);
}

//private slot
void Game::makeAIMove()
{
    if (this->aiPlayer == BLACK) {
            this->getBoard()->calculateBestMove(this->aiPlayer, difficulty);
    }
    if (this->aiPlayer == WHITE) {
            this->getBoard()->calculateBestMove(this->aiPlayer, difficulty);
    }
    this->getBoard()->makeMove(this->getBoard()->getBestMove(),this->aiPlayer);
}

//private
void Game::setBoard(QSharedPointer<Board> nBoard)
{
    if (nBoard.isNull()) {
        return;
    }

    Board * raw = nBoard.data();
    connect(raw,
            SIGNAL(moveMade(CELL_STATE,CELL_STATE)),
            this,
            SLOT(handleTurnTaken(CELL_STATE,CELL_STATE)));
    connect(raw,
            SIGNAL(moveMade(CELL_STATE,CELL_STATE)),
            this,
            SIGNAL(turnTaken(CELL_STATE,CELL_STATE)));
    connect(raw,
            SIGNAL(gameOver(CELL_STATE)),
            this,
            SLOT(handleGameOver(CELL_STATE)));
    connect(raw,
            SIGNAL(gameOver(CELL_STATE)),
            this,
            SIGNAL(gameOver(CELL_STATE)));
    connect(raw,
            SIGNAL(scoreChanged(int,int)),
            this,
            SLOT(handleScoreChanged(int,int)));
    connect(raw,
            SIGNAL(scoreChanged(int,int)),
            this,
            SIGNAL(scoreChanged(int,int)));
    connect(raw,
            SIGNAL(updateProgress(int)),
            this,
            SIGNAL(updateProgress(int)));

    this->board = nBoard;
}



