#include "settings.h"
#include "ui_settings.h"
#include <QSettings>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    Settings::readSettings();
}

Settings::~Settings()
{
    Settings::writeSettings();
    delete ui;
}

void Settings::writeSettings()
{

    QSettings settings("test.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    settings.setValue("layout", this->ui->boardLayoutBox->currentText());
    settings.setValue("language", this->ui->languageBox->currentText());
    settings.endGroup();
}

void Settings::readSettings()
{
    QSettings settings("test.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    this->ui->boardLayoutBox->setCurrentText(settings.value("layout").toString());
    this->ui->languageBox->setCurrentText(settings.value("language").toString());
    settings.endGroup();
}
