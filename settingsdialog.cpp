#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QSettings>
#include <QAbstractButton>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    SettingsDialog::readSettings();
}

SettingsDialog::~SettingsDialog()
{
    SettingsDialog::writeSettings();
    delete ui;
}

SettingsDialog::Settings SettingsDialog::settings() const
{
    return currentSettings;
}

void SettingsDialog::writeSettings()
{

    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    settings.setValue("layout", this->ui->boardLayoutBox->currentIndex());
    settings.setValue("language", this->ui->languageBox->currentIndex());
    settings.endGroup();
}

void SettingsDialog::readSettings()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    currentSettings.style = settings.value("layout").toInt();
    currentSettings.language = settings.value("language").toInt();
    this->applySettings();
    settings.endGroup();
}

void SettingsDialog::applySettings()
{
    this->ui->boardLayoutBox->setCurrentIndex(currentSettings.style);
    this->ui->languageBox->setCurrentIndex(currentSettings.language);
}

int SettingsDialog::getLanguage()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    return settings.value("language").toInt();
}

int SettingsDialog::getStyle()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    return settings.value("layout").toInt();
}

void SettingsDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    this->close();
}

void SettingsDialog::on_languageBox_currentIndexChanged(int index)
{
    currentSettings.language = index;

    // remove the old translator
    switch (index) {
    case 0:
        if(translator.load("reversi_de", ":/languages")) {
             QCoreApplication::instance()->installTranslator(&translator);
        }
        break;
    case 1:
            QCoreApplication::instance()->removeTranslator(&translator);
        break;
    default:
        break;
    }
}

void SettingsDialog::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}
