#include "minimax.h"

#include <QList>
#include <QCoreApplication>
#include <QtDebug>

/**
 * Constructor
 *
 * @param rootNode
 * @param maxDepth
 */
Minimax::Minimax(QSharedPointer<Board> rootNode,int maxDepth) :
        rootNode(rootNode), maxDepth(maxDepth)
{
    BoardPosition bestMove = {0,0};
    this->bestMove = bestMove;
}

/**
 * Desctructor
 *
 */
Minimax::~Minimax()
{

}

/**
 * Search the tree
 * Begins at the root node
 *
 * @return int
 */
int Minimax::search()
{
    return calculate(this->rootNode,0,-10000,10000, 0);
}

/**
 * Evaluates all possible moves and returns best move
 * http://de.wikipedia.org/wiki/Minimax-Algorithmus
 *
 * @param board
 * @param depth
 * @param alpha
 * @param beta
 * @param level
 * @return int
 */
int Minimax::calculate(QSharedPointer<Board> board, int depth, int alpha, int beta, int level=1)
{
    if (++depth > this->maxDepth || board->isGameOver()) {
        return board->getScore();
    }

    const CELL_STATE whoseNext = board->getWhoIsNext();
    const QList<BoardPosition> moves = board->getValidMoves(whoseNext);

    BoardPosition bestMove = {0,0};
    foreach(const BoardPosition move, moves)
    {
        QSharedPointer<Board> simBoard(new Board(*board));
        simBoard->makeMove(move,whoseNext);

        int score = this->calculate(simBoard,depth,alpha,beta,level++);

        if (whoseNext == WHITE)
        {
            if (score > alpha)
            {
                alpha = score;
                bestMove = move;
            }
            else if (score == alpha && qrand() % 2) {
                bestMove = move;
            }

            if (beta <= alpha) {
                break;
            }
        }
        else if (whoseNext == BLACK)
        {
            if (score < beta)
            {
                beta = score;
                bestMove = move;
            }
            else if (score == beta && qrand() % 2) {
                bestMove = move;
            }

            if (beta <= alpha) {
                break;
            }
        }
    }

    if (depth == 1) {
        this->bestMove = bestMove;
    }

    /*
      Return the score of the board configuration created by optimal-play by both players if the
      so-called best move is taken
    */
    if (whoseNext == WHITE) {
        return alpha;
    }
    else {
        return beta;
    }
}

/**
 * Just a getter to get the last calculated best move
 * because the algorithm is too heavy to recalculate every single time
 *
 * @return BoardPosition
 */
BoardPosition Minimax::getBestMove() const
{
    return this->bestMove;
}
