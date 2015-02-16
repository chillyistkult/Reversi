#include "board.h"

#include <cstring>
#include <QtDebug>
#include <QtConcurrent/QtConcurrentRun>
#include <QCoreApplication>
#include <QSound>

#include "minimax.h"

const int cornerPoints = 50; /**< TODO */
const int edgePoints = 2; /**< TODO */

/**
 * Constructor style (0=default, 1=Future, 2=Super Mario)
 *
 * @param size
 * @param style
 */
Board::Board(int size, int style) :
    QObject(0),boardSize(size), boardStyle(style), board(0), whitePoints(0), blackPoints(0), boolGameOver(false), whiteCornerPoints(0),
    blackCornerPoints(0), whiteEdgePoints(0),blackEdgePoints(0)
{
    this->initializeBoard();
}

/**
 * Copy constructor
 *
 * @param other
 */
Board::Board(const Board & other) :
    QObject(0)
{
    this->boardSize = other.getBoardSize();
    this->whoseNext = other.getWhoIsNext();
    this->whitePoints = other.getWhitePoints();
    this->blackPoints = other.getBlackPoints();
    this->boolGameOver = other.isGameOver();
    this->whiteCornerPoints = other.getWhiteCornerPoints();
    this->blackCornerPoints = other.getBlackCornerPoints();
    this->whiteEdgePoints = other.getWhiteEdgePoints();
    this->blackEdgePoints = other.getBlackEdgePoints();

    const int cells = this->boardSize*this->boardSize;
    this->board = new CELL_STATE[cells];
    memcpy(this->board,other.board,cells*sizeof(CELL_STATE));
}

/**
 * Destructor
 *
 */
Board::~Board()
{
    if (this->board != 0) {
        delete this->board;
    }
}

/**
 * Get point of WHITE player
 *
 * @return int
 */
int Board::getWhitePoints() const
{
    return this->whitePoints;
}

/**
 * Get point of BLACK player
 *
 * @return int
 */
int Board::getBlackPoints() const
{
    return this->blackPoints;
}

/**
 * Get points of WHITE corner count
 *
 * @return int
 */
int Board::getWhiteCornerPoints() const
{
    return this->whiteCornerPoints;
}

/**
 * Get points of BLACK corner count
 *
 * @return int
 */
int Board::getBlackCornerPoints() const
{
    return this->blackCornerPoints;
}

/**
 * Get points of WHITE edge count
 *
 * @return int
 */
int Board::getWhiteEdgePoints() const
{
    return this->whiteEdgePoints;
}

/**
 * Get points of BLACK edge count
 *
 * @return int
 */
int Board::getBlackEdgePoints() const
{
    return this->blackEdgePoints;
}

/**
 * Get overall score, calculated from edge, base and corner count
 * Was meant to be used in highscore view
 *
 * @return int
 */
int Board::getScore() const
{
    const int basic = this->getWhitePoints() - this->getBlackPoints();
    const int edges = this->getWhiteEdgePoints() * edgePoints - this->getBlackEdgePoints() * edgePoints;
    const int corners = (cornerPoints*this->getWhiteCornerPoints()) - (cornerPoints*this->getBlackCornerPoints());
    const int score = basic + corners + edges;
    return corners;
}

/**
 * Get a list of valid moves by player
 *
 * @param player
 * @return QList<BoardPosition>
 */
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

/**
 * Checks if the move at a specific position by an specific player is valid
 *
 * @param position
 * @param player
 * @param flips
 * @return bool
 */
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

    //TODO: Improve algorithm

    //Check move left
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
    }

    //Check move right
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
    }

    //Check move up
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
    }

    //Check move down
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
    }

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
    }

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
    }

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
    }

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
    }
    return valid;
}

/**
 * Does a move to a specific position by player
 *
 * @param position
 * @param player
 * @return bool
 */
bool Board::makeMove(BoardPosition position, CELL_STATE player)
{
    if (player != this->getWhoIsNext())
    {
        return false;
    }

    QList<BoardPosition> flips;
    if (!this->isValidMove(position,player,&flips)) {
        QSound::play(":/sound/doh.wav");
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


    // the move with flips
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
            this->gameOver(this->getWinningColor(), this->getWhitePoints(), this->getBlackPoints());
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

    this->lastMove = position;
    this->moveMade(player,this->getWhoIsNext());
    return true;
}

/**
 * Get board size dimension
 *
 * @return int
 */
int Board::getBoardSize() const
{
    return this->boardSize;
}

/**
 * Get board style (0=Default, 1=Future, 2=Super Mario)
 *
 * @return int
 */
int Board::getBoardStyle()
{
    return this->boardStyle;
}

/**
 * Checks if cell is occupied by a player at a specific position
 *
 * @param position
 * @return bool
 */
bool Board::isCellOccupied(BoardPosition position) const
{
    return (this->getCell(position) != EMPTY);
}

/**
 * Get the CELL_STATE (0=EMPTY, 1=WHITE, 2=BLACK) at a specific position
 *
 * @param position
 * @return CELL_STATE
 */
CELL_STATE Board::getCell(BoardPosition position) const
{
    return this->board[this->xy2index(position)];
}

/**
 * Get who's turn is next
 *
 * @return CELL_STATE
 */
CELL_STATE Board::getWhoIsNext() const
{
    return this->whoseNext;
}

/**
 * Is the game over?
 *
 * @return bool
 */
bool Board::isGameOver() const
{
    return this->boolGameOver;
}

/**
 * Who won?
 *
 * @return CELL_STATE
 */
CELL_STATE Board::getWinningColor() const
{
    if (this->getWhitePoints() > this->getBlackPoints())
        return BLACK;
    else if (this->getWhitePoints() < this->getBlackPoints())
        return WHITE;
    else
        return EMPTY;

}

/**
 * A getter for the actual calculated best move
 *
 * @return BoardPosition
 */
BoardPosition Board::getBestMove() const
{
    return this->bestMove;
}

/**
 * A getter for the last made move
 *
 * @return BoardPosition
 */
BoardPosition Board::getLastMove() const
{
    return this->lastMove;
}

/**
 * Calculates best move by using minimax algorithm for a specific player and ai difficulty
 *
 * @param player
 * @param difficulty
 */
void Board::calculateBestMove(CELL_STATE player,int difficulty)
{

    QSharedPointer<Board> board(new Board(*this));
    Minimax minimax(board, difficulty);
    minimax.search();
    this->bestMove = minimax.getBestMove();
}

/**
 * Initialize a new board
 *
 */
void Board::initializeBoard()
{
    if (this->board != 0)
    {
        delete this->board;
        this->board = 0;
    }

    const int cells = this->boardSize*this->boardSize;
    this->board = new CELL_STATE[cells];

    for (int x = 0; x < this->boardSize; x++)
    {
        for (int y = 0; y < this->boardSize; y++)
        {
            const BoardPosition position = {x,y};
            this->board[this->xy2index(position)] = EMPTY;
        }
    }

    int size = this->getBoardSize();
    int style = this->getBoardStyle();

    //Initialize board positions
    const BoardPosition ul = {size/2-1,size/2};
    const BoardPosition ur = {size/2,size/2};
    const BoardPosition bl = {size/2-1,size/2-1};
    const BoardPosition br = {size/2,size/2-1};
    //const BoardPosition temp = {5,3};


    //Start positions
    this->board[this->xy2index(ul)] = WHITE;
    this->board[this->xy2index(ur)] = BLACK;
    this->board[this->xy2index(bl)] = BLACK;
    this->board[this->xy2index(br)] = WHITE;


    //this->board[this->xy2index(temp)] = WHITE;

    this->whoseNext = BLACK;
    this->whitePoints = 2;
    this->blackPoints = 2;
    this->boolGameOver = false;

    this->boardChanged();
    this->scoreChanged(this->getWhitePoints(),this->getBlackPoints());
    //this->calculateBestMove(this->getWhoIsNext());
}

/**
 * Gets the absolut postion by BoardPosition
 *
 * @param position
 * @return int
 */
int Board::xy2index(BoardPosition position) const
{
    return position.y*this->getBoardSize() + position.x;
}

/**
 * Gets the absolut postion by x and y coordinates
 *
 * @param x
 * @param y
 * @return int
 */
int Board::xy2index(int x, int y) const
{
    return y*this->getBoardSize() + x;
}

/**
 * Get's the enemey of a player
 * Need this for valid move and makeMove methods
 *
 *
 * @param color
 * @return CELL_STATE
 */
CELL_STATE Board::getEnemyOf(CELL_STATE color) const
{
    if (color == WHITE)
        return BLACK;
    else if (color == BLACK)
        return WHITE;
    return EMPTY;
}

/**
 * Get all cells between two BoardPostions as a list
 *
 * @param p1
 * @param p2
 * @return QList<BoardPosition>
 */
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

/**
 * Set a cell at a specific postion to a given color (WHITE or BLACK)
 *
 * @param position
 * @param color
 */
void Board::setCell(BoardPosition position, CELL_STATE color)
{
    this->board[this->xy2index(position)] = color;
    this->boardChanged();
}

/**
 * Increments points for a given player
 *
 * @param color
 */
void Board::incrementCount(CELL_STATE color)
{
    if (color == EMPTY)
        return;
    else if (color == BLACK)
        this->blackPoints++;
    else
        this->whitePoints++;
    this->scoreChanged(this->getWhitePoints(),this->getBlackPoints());
}

/**
 * Decrement points for a given player
 *
 * @param color
 */
void Board::decrementCount(CELL_STATE color)
{
    if (color == EMPTY) {
        return;
    }

    else if (color == BLACK) {
        this->blackPoints--;
    }
    else {
        this->whitePoints--;
    }
    this->scoreChanged(this->getWhitePoints(),this->getBlackPoints());
}
