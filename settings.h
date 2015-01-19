#ifndef Settings_H
#define Settings_H

#include <QWidget>

namespace Ui {
    class Settings;
}

struct Options
{
    int difficulty;
};

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    void setDifficulty(int level);
    int getDifficulty();

signals:
    void difficultyBoxChanged(int level);
    void optionsChanged(Options options);

private slots:
    void on_difficultyBox_currentIndexChanged(int arg1);

private:
    Ui::Settings *ui;
    Options options;
};

#endif // Settings_H
