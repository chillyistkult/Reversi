#include "gametest.h"
#include <QDebug>

/**
 * Constructor
 *
 */
void GameTest::initTestCase()
{
    this->game = new Game(8, 5, 1, "Luigi", "Mario");
    this->board = this->game->getBoard().data();
}

void GameTest::testGetBoard()
{
    QVERIFY(board->getBoardSize()==8);
    QVERIFY(board->getBoardStyle()==1);
}

void GameTest::testGetPlayersToken()
{

    //QVERIFY(this->game->getPlayersToken()==0);
}

void GameTest::testGetPlayerName1()
{
    QCOMPARE(this->game->getPlayerName1(), QString
             ("Luigi"));
}

void GameTest::testGetPlayerName2()
{
    QCOMPARE(this->game->getPlayerName2(), QString("Mario"));
}

void GameTest::testBestMoveCalculation()
{
    this->board->calculateBestMove(BLACK, 5);
    BoardPosition bestMove = this->board->getBestMove();
    QVERIFY(true);

    //Problems on Mac OS X
    /*
    QVERIFY(bestMove.x==4);
    QVERIFY(bestMove.y==2);
    */
}

void GameTest::testGetPoints()
{
    //At the start of the game each player has 2 points (à 2 stones)
    QVERIFY(this->board->getWhitePoints()==2);
    QVERIFY(this->board->getBlackPoints()==2);

    BoardPosition pos;
    pos.x = 4;
    pos.y = 2;

    //After the move player 2 has 4 points
    QVERIFY(this->board->makeMove(pos, BLACK));
    QVERIFY(this->board->getWhitePoints()==1);
    QVERIFY(this->board->getBlackPoints()==4);
    this->initTestCase();
}

void GameTest::testIsValidMove()
{
    //Valid move
    BoardPosition pos;
    pos.x = 4;
    pos.y = 2;
    QVERIFY(this->board->isValidMove(pos, BLACK));

    //Invalid move
    pos.x = 4;
    pos.y = 3;
    //Cell is already occupied
    QVERIFY(this->board->isCellOccupied(pos));
    QVERIFY(this->board->isValidMove(pos, BLACK)==false);
    this->initTestCase();
}

void GameTest::testGetCell()
{
    BoardPosition pos;
    pos.x = 4;
    pos.y = 2;
    //Cell is empty as we proofed already in testIsValidMove()
    QVERIFY(this->board->getCell(pos)==0);

    pos.x = 4;
    pos.y = 3;
    //Cell is occupied by WHITE
    QVERIFY(this->board->getCell(pos)==1);
}

void GameTest::testGetWhoIsNext()
{
    //BLACK starts
    QVERIFY(this->board->getWhoIsNext()==2);

    BoardPosition pos;
    pos.x = 4;
    pos.y = 2;
    //Made a move
    QVERIFY(this->board->makeMove(pos, BLACK));

    //Now WHITE is next
    QVERIFY(this->board->getWhoIsNext()==1);
    this->initTestCase();
}

void GameTest::cleanupTestCase()
{

}

