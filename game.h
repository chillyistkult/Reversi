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
    virtual ~Game();

    QSharedPointer<Board> getBoard() const;

signals:
    void turnTaken(CELL_STATE byWhom, CELL_STATE nextTurn);
    void scoreChanged(int white, int black);
    void gameOver(CELL_STATE winner);
    void updateProgress(int value);

public slots:
    virtual void handleCellClicked(BoardPosition where);
    virtual QString getPlayerName1();
    virtual QString getPlayerName2();
    virtual CELL_STATE getPlayersToken();

private slots:
    virtual void handleTurnTaken(CELL_STATE byWhom, CELL_STATE nextTurn);
    virtual void _gameOver(CELL_STATE winner);
    virtual void handleScoreChanged(int white, int black);
    virtual void makeAIMove();

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
