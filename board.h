#ifndef BOARD_H
#define BOARD_H

#include <QtGlobal>
#include <QList>
#include <QSharedPointer>
#include <QObject>

enum CELL_STATE
{
    EMPTY=0,
    WHITE=1,
    BLACK=2
};

struct BoardPosition
{
    int x;
    int y;
};

class Board : public QObject
{
    Q_OBJECT
public:
    Board(int size=8, int style=1);
    Board(const Board&);
    ~Board();

    int getWhiteCount() const;
    int getBlackPoints() const;
    int getwhiteCornerPoints() const;
    int getblackCornerPoints() const;
    int getwhiteEdgePoints() const;
    int getblackEdgePoints() const;
    int getScore() const;

    QList<BoardPosition> getValidMoves(CELL_STATE player) const;
    bool isValidMove(BoardPosition pos,CELL_STATE player,QList<BoardPosition> * flips=0) const;
    bool makeMove(BoardPosition pos, CELL_STATE player);

    int getBoardSize() const;
    int getBoardStyle();

    bool isCellOccupied(BoardPosition pos) const;

    CELL_STATE getCell(BoardPosition pos) const;

    CELL_STATE getWhoIsNext() const;

    bool isGameOver() const;

    CELL_STATE getWinningColor() const;

    BoardPosition getBestMove() const;

    void calculateBestMove(CELL_STATE player, int levels);


signals:
    void boardChanged();
    void moveMade(CELL_STATE player, CELL_STATE nextTurn);
    void countChanged(int white, int black);
    void gameOver(CELL_STATE winner);


private:
    void initializeBoard();
    int xy2index(BoardPosition pos) const;
    int xy2index(int x, int y) const;
    CELL_STATE getEnemyOf(CELL_STATE) const;
    QList<BoardPosition> getCellsBetween(BoardPosition p1, BoardPosition p2) const;
    void setCell(BoardPosition position, CELL_STATE color);
    void incrementCount(CELL_STATE color);
    void decrementCount(CELL_STATE color);
    int boardStyle;
    int boardSize;
    CELL_STATE * board;
    CELL_STATE whoseNext;

    int whiteCount;
    int blackPoints;
    int whiteCornerPoints;
    int blackCornerPoints;
    int whiteEdgePoints;
    int blackEdgePoints;
    bool boolGameOver;

    BoardPosition bestMove;
};

inline int qHash(const Board & b)
{
    return (b.getWhiteCount()*1000 - b.getBlackPoints()*10)*(b.getWhiteCount() + b.getBlackPoints());
}

inline bool operator==(const Board & b1, const Board & b2)
{
    if (b1.getBoardSize() != b2.getBoardSize()) {
        return false;
    }
    else if (b1.getWhoIsNext() != b2.getWhoIsNext()) {
        return false;
    }
    else if (b1.getWhiteCount() != b2.getWhiteCount()) {
        return false;
    }
    else if (b1.getBlackPoints() != b2.getBlackPoints()) {
        return false;
    }

    for (int x = 0; x < b1.getBoardSize(); x++)
    {
        for (int y = 0; y < b1.getBoardSize(); y++)
        {
            const BoardPosition temp = {x,y};
            if (b1.getCell(temp) != b2.getCell(temp))
                return false;
        }
    }
    return true;
}

#endif // BOARD_H
