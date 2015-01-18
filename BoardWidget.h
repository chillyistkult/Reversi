#include <QWidget>
#include "board.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QSharedPointer<Board> board,
                                QWidget *parent = 0);

    BoardWidget(QWidget * parent = 0);

    QSize sizeHint() const;

    void setBoard(QSharedPointer<Board> board);
    QSharedPointer<Board> getBoard() const;

protected:
    void paintEvent(QPaintEvent *);

    void mouseReleaseEvent(QMouseEvent *);

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
