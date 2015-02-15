#ifndef game_h
#define game_h

#include <QSharedPointer>
#include <QObject>

#include "board.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game(int boardSize, int difficulty, int style, QString playerName1, QString playerName2);
    Game(CELL_STATE player, int boardSize, int difficulty, int style, QString playerName1);
    ~Game();

    QSharedPointer<Board> getBoard() const;

signals:
    void turnTaken(CELL_STATE byWhom, CELL_STATE nextTurn);
    void scoreChanged(int white, int black);
    void gameOver(CELL_STATE winner, int white, int black);
    void updateProgress(int value);

public slots:
    void handleCellClicked(BoardPosition where);
    QString getPlayerName1();
    QString getPlayerName2();
    CELL_STATE getPlayersToken();

private slots:
    void handleTurnTaken(CELL_STATE byWhom, CELL_STATE nextTurn);
    void handleGameOver(CELL_STATE winner, int white, int black);
    void handleScoreChanged(int white, int black);
    void makeAIMove();
    void saveHighscore(int white, int black);

protected:
    void setBoard(QSharedPointer<Board> nBoard);

private:
    QSharedPointer<Board> board;
    CELL_STATE aiPlayer;
    CELL_STATE player;
    int difficulty;
    QString playerName1;
    QString playerName2;
};

#endif // game_h
