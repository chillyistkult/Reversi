#include "board.h"

#include <cstring>
#include <QtDebug>
#include <QtConcurrent/QtConcurrentRun>
#include <QCoreApplication>

#include "Minimax.h"

const int cornerPoints = 50;
const int edgePoints = 2;

Board::Board(int size) :
    QObject(0),boardSize(size), board(0), whiteCount(0), blackPoints(0), boolGameOver(false), whiteCornerPoints(0),
    blackCornerPoints(0), whiteEdgePoints(0),blackEdgePoints(0)
{
    this->initializeBoard();
}

Board::Board(const Board & other) :
    QObject(0)
{
    this->boardSize = other.getBoardSize();
    this->whoseNext = other.getWhoIsNext();
    this->whiteCount = other.getWhiteCount();
    this->blackPoints = other.getBlackPoints();
    this->boolGameOver = other.isGameOver();
    this->whiteCornerPoints = other.getwhiteCornerPoints();
    this->blackCornerPoints = other.getblackCornerPoints();
    this->whiteEdgePoints = other.getwhiteEdgePoints();
    this->blackEdgePoints = other.getblackEdgePoints();

    const int numCells = this->boardSize*this->boardSize;
    this->board = new CELL_STATE[numCells];
    memcpy(this->board,other.board,numCells*sizeof(CELL_STATE));
}

Board::~Board()
{
    if (this->board != 0) {
        delete this->board;
    }
}

int Board::getWhiteCount() const
{
    return this->whiteCount;
}

int Board::getBlackPoints() const
{
    return this->blackPoints;
}

int Board::getwhiteCornerPoints() const
{
    return this->whiteCornerPoints;
}

int Board::getblackCornerPoints() const
{
    return this->blackCornerPoints;
}

int Board::getwhiteEdgePoints() const
{
    return this->whiteEdgePoints;
}

int Board::getblackEdgePoints() const
{
    return this->blackEdgePoints;
}

int Board::getScore() const
{
    const int basic = this->getWhiteCount() - this->getBlackPoints();
    const int edges = this->getwhiteEdgePoints() * edgePoints - this->getblackEdgePoints() * edgePoints;
    const int corners = (cornerPoints*this->getwhiteCornerPoints()) - (cornerPoints*this->getblackCornerPoints());
    const int score = basic + corners + edges;

    /*
    if ((score > 0 && basic < 0)
            || (score < 0 && basic > 0))
    {
        qDebug() << "Mismatch";
    }
    */

    //return score;
    return corners;
}

QList<BoardPosition> Board::getValidMoves(CELL_STATE player) const
{
    QList<BoardPosition> validMoves;
    for (int x = 0; x < this->getBoardSize(); x++)
    {
        for (int y = 0; y < this->getBoardSize(); y++)
        {
            BoardPosition position = {x,y};
            if (this->isValidMove(position, player))
                validMoves.append(position);
        }
    }
    return validMoves;
}

bool Board::isValidMove(BoardPosition position,CELL_STATE player, QList<BoardPosition> * flips) const
{
    Q_UNUSED(flips);
    if (player == EMPTY) {
        return false;
    }
    if (this->isCellOccupied(position)) {
        return false;
    }

    const CELL_STATE enemy = this->getEnemyOf(player);

    bool valid = false;

    //Check moving left
    {
        bool gotEnemy = false;
        for (int x = position.x-1; x >= 0; x--)
        {
            const BoardPosition consider = {x,position.y};
            const CELL_STATE considerCell = this->getCell(consider);
            //Found empty cell
            if (considerCell == EMPTY)
                break;
            //Found enemy cell
            else if (considerCell == enemy)
                gotEnemy = true;
            //Found friendly cell
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
        }
    } //End left-moving check

    //Check moving right
    {
        bool gotEnemy = false;
        for (int x = position.x+1; x < this->getBoardSize(); x++)
        {
            const BoardPosition consider = {x,position.y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
        }
    } //End right-moving check

    //Check moving up
    {
        bool gotEnemy = false;
        for (int y = position.y+1; y < this->getBoardSize(); y++)
        {
            const BoardPosition consider = {position.x,y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
        }
    }//End up-moving check

    //Check moving down
    {
        bool gotEnemy = false;
        for (int y = position.y-1; y >= 0; y--)
        {
            const BoardPosition consider = {position.x,y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
        }
    }//End up-moving check

    //Diagonal up-right check
    {
        bool gotEnemy = false;
        int x = position.x+1;
        int y = position.y+1;
        while (x < this->getBoardSize() && y < this->getBoardSize())
        {
            const BoardPosition consider = {x,y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
            ++x;
            ++y;
        }
    } //End diagonal up-right check

    //Diagonal up-left check
    {
        bool gotEnemy = false;
        int x = position.x-1;
        int y = position.y+1;
        while (x >= 0 && y < this->getBoardSize())
        {
            const BoardPosition consider = {x,y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
            --x;
            ++y;
        }
    }//End diagonal up-left check

    //Diagonal down-right check
    {
        bool gotEnemy = false;
        int x = position.x+1;
        int y = position.y-1;
        while (x < this->getBoardSize()&& y >= 0)
        {
            const BoardPosition consider = {x,y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
            ++x;
            --y;
        }
    }//End diagonal down-right check

    //Diagonal down-left check
    {
        bool gotEnemy = false;
        int x = position.x-1;
        int y = position.y-1;
        while (x >= 0 && y >= 0)
        {
            const BoardPosition consider = {x,y};
            const CELL_STATE considerCell = this->getCell(consider);
            if (considerCell == EMPTY)
                break;
            else if (considerCell == enemy)
                gotEnemy = true;
            else
            {
                if (gotEnemy)
                {
                    valid = true;
                    if (flips)
                        flips->append(this->getCellsBetween(consider,position));
                }
                break;
            }
            --x;
            --y;
        }
    }//End diagonal down-left check

    return valid;
}

bool Board::makeMove(BoardPosition position, CELL_STATE player)
{
    if (player != this->getWhoIsNext())
    {
        return false;
    }

    QList<BoardPosition> flips;
    if (!this->isValidMove(position,player,&flips)) {
        return false;
    }

    const int boardSize = this->getBoardSize();
    //Update corner counts
    if ((position.x == 0 && position.y == 0) || (position.x == 0 && position.y == boardSize-1)
            || (position.x == boardSize-1 && position.y == 0) || (position.x == boardSize-1 && position.y == boardSize-1))
    {
        if (player == WHITE)
            this->whiteCornerPoints++;
        else
            this->blackCornerPoints++;
    }


    //do the move with flips
    foreach(BoardPosition theirPos, flips)
    {
        this->setCell(theirPos,player);
        this->incrementCount(player);
        this->decrementCount(this->getEnemyOf(player));
    }
    this->setCell(position,player);
    this->incrementCount(player);

    this->whoseNext = this->getEnemyOf(this->getWhoIsNext());
    if (this->getValidMoves(this->getWhoIsNext()).isEmpty())
    {
        this->whoseNext = this->getEnemyOf(this->getWhoIsNext());
        if (this->getValidMoves(this->getWhoIsNext()).isEmpty())
        {
            this->whoseNext = EMPTY;
            this->boolGameOver = true;
            this->gameOver(this->getWinningColor());
        }
    }

    //Update edge counts
    int wCount = 0;
    int bCount = 0;
    for (int x = 0; x < boardSize; x++)
    {
        for (int y = 0; y < boardSize; y++)
        {
            BoardPosition position = {x,y};
            if (position.x == 0 || position.y == 0 || position.x == boardSize-1 || position.y == boardSize-1)
            {
                const CELL_STATE owner = this->getCell(position);
                if (owner == WHITE)
                {
                    ++wCount;
                    //qDebug() << position.x << position.y << "is white";
                }
                else if (owner == BLACK)
                {
                    ++bCount;
                    //qDebug() << position.x << position.y << "is black";
                }
            }
        }
    }
    this->whiteEdgePoints = wCount;
    this->blackEdgePoints = bCount;

    this->moveMade(player,this->getWhoIsNext());
    return true;
}

int Board::getBoardSize() const
{
    return this->boardSize;
}

bool Board::isCellOccupied(BoardPosition position) const
{
    return (this->getCell(position) != EMPTY);
}

CELL_STATE Board::getCell(BoardPosition position) const
{
    return this->board[this->xy2index(position)];
}

CELL_STATE Board::getWhoIsNext() const
{
    return this->whoseNext;
}

bool Board::isGameOver() const
{
    return this->boolGameOver;
}

CELL_STATE Board::getWinningColor() const
{
    if (this->getWhiteCount() > this->getBlackPoints())
        return BLACK;
    else if (this->getWhiteCount() < this->getBlackPoints())
        return WHITE;
    else
        return EMPTY;

}

BoardPosition Board::getBestMove() const
{
    return this->bestMove;
}

void Board::calculateBestMove(CELL_STATE player,int difficulty)
{
    QSharedPointer<Board> board(new Board(*this));
    Minimax minimax(board, difficulty);
    minimax.search();
    this->bestMove = minimax.getBestMove();
}

//private
void Board::initializeBoard()
{
    if (this->board != 0)
    {
        delete this->board;
        this->board = 0;
    }

    const int numCells = this->boardSize*this->boardSize;
    this->board = new CELL_STATE[numCells];

    for (int x = 0; x < this->boardSize; x++)
    {
        for (int y = 0; y < this->boardSize; y++)
        {
            const BoardPosition position = {x,y};
            this->board[this->xy2index(position)] = EMPTY;
        }
    }

    int size = this->getBoardSize();

    //Initialize board positions
    const BoardPosition ul = {size/2-1,size/2};
    const BoardPosition ur = {size/2,size/2};
    const BoardPosition bl = {size/2-1,size/2-1};
    const BoardPosition br = {size/2,size/2-1};
    //const BoardPosition temp = {5,3};


    this->board[this->xy2index(ul)] = WHITE;
    this->board[this->xy2index(ur)] = BLACK;
    this->board[this->xy2index(bl)] = BLACK;
    this->board[this->xy2index(br)] = WHITE;


    //this->board[this->xy2index(temp)] = WHITE;

    this->whoseNext = BLACK;
    this->whiteCount = 2;
    this->blackPoints = 2;
    this->boolGameOver = false;

    this->boardChanged();
    this->countChanged(this->getWhiteCount(),this->getBlackPoints());
    //this->calculateBestMove(this->getWhoIsNext());
}

//private
int Board::xy2index(BoardPosition position) const
{
    return position.y*this->getBoardSize() + position.x;
}

//private
int Board::xy2index(int x, int y) const
{
    return y*this->getBoardSize() + x;
}


//private
CELL_STATE Board::getEnemyOf(CELL_STATE color) const
{
    if (color == WHITE)
        return BLACK;
    else if (color == BLACK)
        return WHITE;
    return EMPTY;
}

//private
QList<BoardPosition> Board::getCellsBetween(BoardPosition p1, BoardPosition p2) const
{
    QList<BoardPosition> toRet;
    int dx;
    int dy;
    if (p2.x < p1.x)
        dx = 1;
    else if (p2.x > p1.x)
        dx = -1;
    else
        dx = 0;

    if (p2.y < p1.y)
        dy = 1;
    else if (p2.y > p1.y)
        dy = -1;
    else
        dy = 0;

    BoardPosition start = {p2.x + dx, p2.y + dy};
    while (start.x != p1.x || start.y != p1.y)
    {
        toRet.append(start);
        start.x += dx;
        start.y += dy;
    }

    return toRet;
}

//private
void Board::setCell(BoardPosition position, CELL_STATE color)
{
    this->board[this->xy2index(position)] = color;
    this->boardChanged();
}

//private
void Board::incrementCount(CELL_STATE color)
{
    if (color == EMPTY)
        return;
    else if (color == BLACK)
        this->blackPoints++;
    else
        this->whiteCount++;
    this->countChanged(this->getWhiteCount(),this->getBlackPoints());
}

//private
void Board::decrementCount(CELL_STATE color)
{
    if (color == EMPTY) {
        return;
    }

    else if (color == BLACK) {
        this->blackPoints--;
    }
    else {
        this->whiteCount--;
    }
    this->countChanged(this->getWhiteCount(),this->getBlackPoints());
}


