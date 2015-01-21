#include <QMainWindow>

#include "board.h"
#include "game.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void countChange(int white, int black);

    void gameOver(CELL_STATE);

    void on_actionPlayer_vs_Player_triggered();

    void on_actionPlayer_vs_Computer_triggered();

    void on_actionSettings_triggered();

    void on_exit_triggered();

private:
    void setGame(QSharedPointer<Game> game);
    Ui::MainWindow *ui;
    QSharedPointer<Game> game;
};
