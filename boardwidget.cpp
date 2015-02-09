#include "BoardWidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include <QMessageBox>

#include "minimax.h"

BoardWidget::BoardWidget(QSharedPointer<Board> board, QWidget *parent) :
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
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (this->board.isNull())
    {
        painter.fillRect(this->rect(), QColor(245,241,222,255));
        QFont font = painter.font();
        font.setPointSize ( 18 );
        font.setWeight(QFont::Bold);
        painter.setFont(font);
        painter.drawText(this->rect(),tr("Start a new game."), QTextOption(Qt::AlignCenter));
        return;
    }

    int style = this->board->getBoardStyle();

    QColor bgColor;
    QColor boardColor;
    QColor gridColor;
    QColor whiteChipColor;
    QColor blackChipColor;

    gridColor = Qt::black;
    bgColor = QColor(0,0,0,255);

    switch(style) {
    case 0:
        boardColor = QColor(222,184,135,255);
        whiteChipColor = QColor(240,240,240,255);;
        blackChipColor = Qt::black;
        break;
    case 1:
        boardColor = QColor(181,227,172,255);
        whiteChipColor = QColor(20,146,255,255);
        blackChipColor = QColor(255,20,103,255);
        break;
    case 2:
        boardColor = QColor(222,184,135,255);
        whiteChipColor = QColor(240,240,240,255);;
        blackChipColor = QColor(203,8,8,255);
        break;
    }

    const int size = qMin(this->width(),this->height())-1;
    const int cells = this->board->getBoardSize();
    const int cellSize = size / cells;

    if (this->board->getWhoIsNext() == WHITE) {
        switch(style) {
        case 0:
            painter.fillRect(this->rect(),Qt::white);
            break;
        case 1:
            painter.fillRect(this->rect(),QColor(20,146,255,255));
            break;
        case 2:
            painter.fillRect(this->rect(),QColor(0,164,49,255));
            break;
        }
    }
    else {
        switch(style) {
        case 0:
            painter.fillRect(this->rect(),Qt::black);
            break;
        case 1:
            painter.fillRect(this->rect(),QColor(255,20,103,255));
            break;
        case 2:
            painter.fillRect(this->rect(),QColor(199,8,8,255));
            break;
        }
    }

    painter.scale(1,-1.0);
    painter.translate(0,-1*size);

    painter.translate((this->width() - cells*cellSize)/2, -1*(this->height() - cells*cellSize)/2);

    painter.fillRect(0,0,cells*cellSize,cells*cellSize,boardColor);


    painter.setPen(gridColor);
    for (int x = 0; x <= cells; x++)
    {
        painter.drawLine(x*cellSize,0,x*cellSize,cellSize*cells);
    }

    for (int y = 0; y <= cells; y++)
    {
        painter.drawLine(0,y*cellSize,cellSize*cells,y*cellSize);
    }

    for (int x = 0; x < cells; x++)
    {
        for (int y = 0; y < cells; y++)
        {
            const BoardPosition pos = {x,y};
            CELL_STATE cell = this->board->getCell(pos);

            if (cell == WHITE)
            {
                painter.setPen(whiteChipColor);
                painter.setBrush(QBrush(whiteChipColor));
                switch(style) {
                case 0:
                    painter.drawEllipse(QPoint(cellSize*x + cellSize/2,cellSize*y + cellSize/2),cellSize/2-2,cellSize/2-2);
                    break;
                case 1:
                    painter.drawRect(cellSize*x + cellSize/5.5,cellSize*y + cellSize/5.5,cellSize/1.5,cellSize/1.5);
                    break;
                case 2:
                    QImage image;
                    image.load(":/images/green.png");
                    painter.drawImage(cellSize*x + cellSize/5.5,cellSize*y + cellSize/5.5, image.scaled(cellSize/1.5, cellSize/1.5).mirrored());
                    break;
                }
            }
            else if (cell == BLACK)
            {
                painter.setPen(blackChipColor);
                painter.setBrush(QBrush(blackChipColor));
                switch(style) {
                case 0:
                    painter.drawEllipse(QPoint(cellSize*x + cellSize/2,cellSize*y + cellSize/2),cellSize/2-2,cellSize/2-2);
                    break;
                case 1:
                    painter.drawRect(cellSize*x + cellSize/5.5,cellSize*y + cellSize/5.5,cellSize/1.5,cellSize/1.5);
                    break;
                case 2:
                    QImage image;
                    image.load(":/images/red.png");
                    painter.drawImage(cellSize*x + cellSize/5.5,cellSize*y + cellSize/5.5, image.scaled(cellSize/1.5, cellSize/1.5).mirrored());
                    break;
                }
            }
        }
    }


    painter.setPen(Qt::green);
    painter.setBrush(QBrush(whiteChipColor));
    if (this->board->getWhoIsNext() == BLACK) {
        painter.setBrush(blackChipColor);
    }
    for (int x = 0; x < cells; x++)
    {
        for (int y = 0; y < cells; y++)
        {
            BoardPosition pos = {x,y};
            if (!this->board->isValidMove(pos,this->board->getWhoIsNext())) {
                continue;
            }
            painter.drawEllipse(QPoint(cellSize*x + cellSize/2, cellSize*y + cellSize/2),5,5);
        }
    }

    BoardPosition bestMove = this->getBoard()->getBestMove();
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(QPoint(cellSize*bestMove.x + cellSize/2, cellSize*bestMove.y + cellSize/2),5,5);

    if (this->getBoard()->getWhoIsNext() == WHITE && !this->showPossibleWhite) {
        return;
    }
    else if (this->getBoard()->getWhoIsNext() == BLACK && !this->showPossibleBlack) {
        return;
    }
    else if (this->getBoard()->getWhoIsNext() == EMPTY) {
        return;
    }
}

//Get boardPosition
void BoardWidget::mouseReleaseEvent(QMouseEvent * event)
{
    if (this->board.isNull())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Please use the main menu to chose game mode."));
        msgBox.exec();
        return;
    }


    if ((event->pos() - this->lastMousePressPosition).manhattanLength() > 4) {
        return;
    }
    QPoint pos = event->pos();

    const int size = qMin(this->width(),this->height())-1;
    const int cells = this->board->getBoardSize();
    const int cellSize = size / cells;
    QPoint transformedPos = pos;
    transformedPos.setY(transformedPos.y()*-1);
    transformedPos.setY(transformedPos.y() + size);
    transformedPos.setX(transformedPos.x() - (this->width() - cells*cellSize)/2);
    transformedPos.setY(transformedPos.y() + (this->height() - cells*cellSize)/2);


    if (transformedPos.x() < 0 || transformedPos.y() < 0 || transformedPos.x() > cells*cellSize || transformedPos.y() > cells*cellSize)
        return;

    int xCell = transformedPos.x() / cellSize;
    int yCell = transformedPos.y() / cellSize;
    const BoardPosition boardPosition = {xCell,yCell};

    this->cellClicked(boardPosition);
}

void BoardWidget::mousePressEvent(QMouseEvent * event)
{
    this->lastMousePressPosition = event->pos();
}
