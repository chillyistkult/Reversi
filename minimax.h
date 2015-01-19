#include "board.h"

#include <QSharedPointer>
#include <QtGlobal>
#include <QHash>

class Minimax
{
public:
    Minimax(QSharedPointer<Board> rootNode,int maxDepth);
    virtual ~Minimax();

    int search();

    BoardPosition getBestMove() const;

private:
    int calculate(QSharedPointer<Board> board, int depth, int alpha, int beta);
    QSharedPointer<Board> rootNode;
    const int maxDepth;
    BoardPosition bestMove;
};

