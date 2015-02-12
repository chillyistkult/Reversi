#ifndef GAMETEST_H
#define GAMETEST_H

#include "AutoTest.h"
#include "game.h"

class GameTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void getPlayersToken();
    void getPlayerName1();
    void getPlayerName2();
    void cleanupTestCase();

private:
    Game * game;
};

DECLARE_TEST(GameTest)

#endif // GAMETEST_H

