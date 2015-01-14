#include "board.h"



Board::Board(int size) :
{
    this->initializeBoard();
}

int Board::getWhiteCount() const
{
    return null;
}

int Board::getBlackPoints() const
{
    return null;
}

int Board::getwhiteCornerPoints() const
{
   return null;
}

int Board::getblackCornerPoints() const
{
   return null;
}

int Board::getwhiteEdgePoints() const
{
   return null;
}

int Board::getblackEdgePoints() const
{
   return null;
}

int Board::getScore() const
{
    return null;
}

QList<BoardPosition> Board::getValidMoves(CELL_STATE player) const
{
    return null;
}

bool Board::isValidMove(BoardPosition position,CELL_STATE player, QList<BoardPosition> * flips) const
{
    return null;
}

bool Board::makeMove(BoardPosition position, CELL_STATE player)
{
      return null;
}

int Board::getBoardSize() const
{
       return null;
}

bool Board::isCellOccupied(BoardPosition position) const
{
       return null;
}

CELL_STATE Board::getCell(BoardPosition position) const
{
      return null;
}

CELL_STATE Board::getWhoIsNext() const
{
      return null;
}

bool Board::isGameOver() const
{
       return null;
}

CELL_STATE Board::getWinningColor() const
{
   return null;

}

BoardPosition Board::getBestMove() const
{
    return this->bestMove;
}

void Board::calculateBestMove(CELL_STATE player,int levels)
{
   return null;
}

//private
void Board::initializeBoard()
{
      return null;
}

//private
int Board::xy2index(BoardPosition position) const
{
      return null;
}

//private
int Board::xy2index(int x, int y) const
{
      return null;
}


//private
CELL_STATE Board::getEnemyOf(CELL_STATE color) const
{
      return null;
}

//private
QList<BoardPosition> Board::getCellsBetween(BoardPosition p1, BoardPosition p2) const
{
      return null;
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
      return null;
}

//private
void Board::decrementCount(CELL_STATE color)
{
      return null;
}


