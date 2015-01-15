#include "game.h"

#include <QTimer>
#include <QtGlobal>
#include <QtDebug>

int difficulty = 3;

Game::Game()
{
    this->setBoard(QSharedPointer<Board>(new Board(8)));
}


Game::Game(CELL_STATE player) : player(player)
{
    this->setBoard(QSharedPointer<Board>(new Board(8)));
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

void Game::handleCellClicked(BoardPosition where)
{
    this->board->makeMove(where, this->board->getWhoIsNext());
}

void Game::setDifficulty(int level)
{
    switch(level) {
        case 0:
            difficulty = 3;
            break;
        case 1:
            difficulty = 5;
            break;
        case 2:
            difficulty = 19;
            break;
        default:
            break;
    }
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

//private slot
void Game::_gameOver(CELL_STATE winner)
{
    Q_UNUSED(winner);
    //this->gameOver(winner);
}

//private slot
void Game::handleScoreChanged(int white, int black)
{
    Q_UNUSED(white);
    Q_UNUSED(black);
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
    this->getBoard()->makeMove(this->getBoard
                               ()->getBestMove(),this->aiPlayer);
}

//private
void Game::setBoard(QSharedPointer<Board> nBoard)
{
    if (nBoard.isNull())
        return;

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
            SLOT(_gameOver(CELL_STATE)));
    connect(raw,
            SIGNAL(gameOver(CELL_STATE)),
            this,
            SIGNAL(gameOver(CELL_STATE)));
    connect(raw,
            SIGNAL(countChanged(int,int)),
            this,
            SLOT(handleScoreChanged(int,int)));
    connect(raw,
            SIGNAL(countChanged(int,int)),
            this,
            SIGNAL(scoreChanged(int,int)));

    this->board = nBoard;
}



