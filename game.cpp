#include "game.h"
#include "gamedialog.h"
#include "settingsdialog.h"

#include <QTimer>
#include <QtGlobal>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

//Constructor Player vs. Player
Game::Game(int boardSize, int difficulty, int style, QString playerName1, QString playerName2)
{
    if(playerName1.isEmpty()) {
        this->playerName1 = "Human1";
    }
    else {
        this->playerName1 = playerName1;
    }
    if(playerName2.isEmpty()) {
        this->playerName2 = "Human2";
    }
    else {
        this->playerName2 = playerName2;
    }
    this->difficulty = difficulty;
    this->setBoard(QSharedPointer<Board>(new Board(boardSize, style)));
}

//Constructor Player vs. Computer
Game::Game(CELL_STATE player, int boardSize, int difficulty, int style, QString playerName1) : player(player)
{
    if(playerName1.isEmpty()) {
        this->playerName1 = tr("Human");
    }
    else {
        this->playerName1 = playerName1;
    }
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

//Destructor
Game::~Game()
{
    QStringList list = QSqlDatabase::connectionNames();
    for(int i = 0; i < list.count(); ++i) {
        QSqlDatabase::removeDatabase(list[i]);
    }
}

//Gets actual reference to board
QSharedPointer<Board> Game::getBoard() const
{
    return this->board;
}

//Get players token
CELL_STATE Game::getPlayersToken() {
    return this->player;
}

//Get player name
QString Game::getPlayerName1() {
    return this->playerName1;
}

//Get player name
QString Game::getPlayerName2() {
    return this->playerName2;
}

//Cell clicked slot
void Game::handleCellClicked(BoardPosition where)
{
    this->board->makeMove(where, this->board->getWhoIsNext());
}

//Handle turn taken
void Game::handleTurnTaken(CELL_STATE byWhom, CELL_STATE nextTurn)
{
    if (this->getBoard()->isGameOver()) {
        return;
    }
    if (nextTurn == this->aiPlayer)
    {
        QTimer::singleShot(50,this,SLOT(makeAIMove()));
    }
}

//Game over slot
void Game::handleGameOver(CELL_STATE winner, int white, int black)
{
    this->saveHighscore(white, black);
    //this->gameOver(winner);
}

//Score changed slot
void Game::handleScoreChanged(int white, int black)
{
    //this->scoreChanged(white,black);
}

//Make AI turn
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

void Game::saveHighscore(int white, int black)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "Highscore");
    db.setDatabaseName( "./highscore.db" );
    if (db.open()) {
        QSqlQuery query(db);
        if (!query.exec("CREATE TABLE IF NOT EXISTS score (id INTEGER UNIQUE PRIMARY KEY, player1 VARCHAR(30), player2 VARCHAR(30), score1 INTEGER, score2 INTEGER)")) {
            qDebug() << query.lastError();
        }
        query.prepare("INSERT INTO score (player1, player2, score1, score2) "
                      "VALUES (:player1, :player2, :score1, :score2)");
        query.bindValue(":player1", this->getPlayerName1());
        query.bindValue(":player2", this->getPlayerName2());
        query.bindValue(":score1", white);
        query.bindValue(":score2", black);
        if( !query.exec() ) {
            qDebug() << query.lastError();
        }
    }
    db.close();
}

//Initialize new board and connect signals / slots
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
            SIGNAL(gameOver(CELL_STATE,int,int)),
            this,
            SLOT(handleGameOver(CELL_STATE,int,int)));
    connect(raw,
            SIGNAL(gameOver(CELL_STATE,int,int)),
            this,
            SIGNAL(gameOver(CELL_STATE,int,int)));
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
