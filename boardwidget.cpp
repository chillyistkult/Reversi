#include "BoardWidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include "Minimax.h"

BoardWidget::BoardWidget(QSharedPointer<Board> board,
                                       QWidget *parent) :
    QWidget(parent), showPossibleWhite(false), showPossibleBlack(false)
{
    this->setBoard(board);
}

BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent), showPossibleWhite(false), showPossibleBlack(false)
{

}

QSize BoardWidget::sizeHint() const
{
    return QSize(800,800);
}

void BoardWidget::setBoard(QSharedPointer<Board> board)
{
    this->board = board;
    Board * raw = board.data();
    connect(raw,
            SIGNAL(moveMade(CELL_STATE,CELL_STATE)),
            this,
            SLOT(update()));

    this->update();
}

QSharedPointer<Board> BoardWidget::getBoard() const
{
    return this->board;
}

void BoardWidget::paintEvent(QPaintEvent *)
{

}

void BoardWidget::mousePressEvent(QMouseEvent * event)
{
    this->lastMousePressPos = event->pos();
}
