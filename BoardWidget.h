#include <QWidget>
#include "board.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QSharedPointer<Board> board,
                                QWidget *parent = 0);

    BoardWidget(QWidget * parent = 0);

    //virtual from QWidget
    QSize sizeHint() const;

    void setBoard(QSharedPointer<Board> board);
    QSharedPointer<Board> getBoard() const;

protected:
    //virtual from QWidget
    void paintEvent(QPaintEvent *);

    //virtual from QWidget
    void mouseReleaseEvent(QMouseEvent *);

    //virtual from QWidget
    void mousePressEvent(QMouseEvent *);


signals:
    void cellClicked(const BoardPosition cell);

public slots:

private:
    QSharedPointer<Board> board;
    QPoint lastMousePressPos;

    bool showPossibleWhite;
    bool showPossibleBlack;

};
