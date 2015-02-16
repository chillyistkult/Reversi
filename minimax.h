#ifndef MINIMAX_H
#define MINIMAX_H

#include <QObject>
#include <board.h>

class Minimax : public QObject
{
    Q_OBJECT
public:
    Minimax(QSharedPointer<Board> rootNode,int maxDepth);
    virtual ~Minimax();

    int search();

    BoardPosition getBestMove() const;

private:
    int calculate(QSharedPointer<Board> board, int depth, int alpha, int beta, int level);
    QSharedPointer<Board> rootNode;
    const int maxDepth;
    BoardPosition bestMove;
};
#endif // MINIMAX_H
