#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Highscore;
}

class Highscore : public QDialog
{
    Q_OBJECT

public:
    explicit Highscore(QWidget *parent = 0);
    ~Highscore();

private:
    void load();
    Ui::Highscore *ui;

    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // HIGHSCORE_H
