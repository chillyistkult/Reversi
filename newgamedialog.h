#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {

struct Settings
{
    int difficulty = 1;
    int boardSize = 8;
    QString style = "default";
};

class newGameDialog;
}

class newGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newGameDialog(QWidget *parent = 0);
    ~newGameDialog();

    int getBoardSize();

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_boardSizeSlider_valueChanged(int value);

private:
    Ui::newGameDialog *ui;
    Ui::Settings settings;
};

#endif // NEWGAMEDIALOG_H
