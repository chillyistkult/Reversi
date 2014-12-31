
#ifndef GAME_H
#define GAME_H

#include <QSharedPointer>
#include <QObject>

enum CELL_STATE
{
    EMPTY_CELL=0,
    WHITE_CELL=1,
    BLACK_CELL=2
};

struct BoardPosition
{
    quint8 x;
    quint8 y;
};

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    virtual ~Game();

signals:
    void turnTaken(CELL_STATE byWhom, CELL_STATE nextTurn);
    void scoreChanged(quint16 white, quint16 black);
    void gameOver(CELL_STATE winner);

public slots:
    virtual void cellClicked(BoardPosition where);
    virtual void setBlackAIDepth(quint8 depth);
    virtual void setWhiteAIDepth(quint8 depth);

private slots:
    virtual void handleTurnTaken(CELL_STATE byWhom, CELL_STATE nextTurn);
    virtual void gameOver(CELL_STATE winner);
    virtual void scoreChanged(quint16 white, quint16 black);


protected:


#endif // REVERSIGAME_H
