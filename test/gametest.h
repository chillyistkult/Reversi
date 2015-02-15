#ifndef GAMETEST_H
#define GAMETEST_H

#include "AutoTest.h"
#include "game.h"
#include "board.h"

class GameTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testGetBoard();
    void testGetPlayersToken();
    void testGetPlayerName1();
    void testGetPlayerName2();
    void testBestMoveCalculation();
    void testGetPoints();
    void testIsValidMove();
    void testGetCell();
    void testGetWhoIsNext();
    void cleanupTestCase();

private:
    Game * game;
    Board * board;
};

DECLARE_TEST(GameTest)

#endif // GAMETEST_H

