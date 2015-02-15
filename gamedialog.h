#ifndef GameDialog_H
#define GameDialog_H

#include <QDialog>
#include <QPushButton>
#include <board.h>

namespace Ui {



struct Settings
{
    int difficulty = 1;
    int boardSize = 8;
};

class GameDialog;
}

class GameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameDialog(QWidget *parent = 0);
    ~GameDialog();

    int getDifficulty();
    int getBoardSize();
    CELL_STATE getToken();
    QString getPlayerName1();
    QString getPlayerName2();
    void enablePlayer2Input();

private slots:

    void on_buttonBox_accepted();

    void on_boardSizeSlider_valueChanged(int value);

    void on_difficultyBox_currentIndexChanged(int index);

    void on_player1CheckBox_clicked(bool checked);

    void on_player2CheckBox_clicked(bool checked);


private:
    Ui::GameDialog *ui;
    Ui::Settings settings;
    QString playerName1;
    QString playerName2;
};

#endif // GameDialog_H
