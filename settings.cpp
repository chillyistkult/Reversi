#include "Settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::setDifficulty(int level)
{
   // this->options.difficulty = this->ui->difficultyBox->findData(level);
}

void Settings::on_difficultyBox_currentIndexChanged(int arg1)
{
    this->difficultyBoxChanged(arg1);
    this->options.difficulty = arg1;
    this->optionsChanged(this->options);
}

