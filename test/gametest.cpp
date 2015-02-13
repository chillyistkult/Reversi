#include "gametest.h"
#include <QDebug>

void GameTest::initTestCase()
{
    this->game = new Game(8, 5, 1, "Luigi", "Mario");
}

void GameTest::getPlayersToken()
{

    //QVERIFY(this->game->getPlayersToken()==0);
}

void GameTest::getPlayerName1()
{
    QCOMPARE(this->game->getPlayerName1(), QString("Luigi"));
}

void GameTest::getPlayerName2()
{
    QCOMPARE(this->game->getPlayerName2(), QString("Mario"));
}


void GameTest::cleanupTestCase()
{

}

