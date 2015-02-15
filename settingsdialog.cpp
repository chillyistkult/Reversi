#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QSettings>
#include <QAbstractButton>
#include <QDebug>

/**
 * Constructor
 * Loads all settings from ini
 *
 * @param parent
 */
SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    SettingsDialog::readSettings();
}

/**
 * Destructor
 * Saves all settings to ini
 *
 */
SettingsDialog::~SettingsDialog()
{
    SettingsDialog::writeSettings();
    delete ui;
}

/**
 * Get the actual settings
 *
 * @return SettingsDialog::Settings
 */
SettingsDialog::Settings SettingsDialog::settings() const
{
    return currentSettings;
}

/**
 * Write settings to ini file
 *
 */
void SettingsDialog::writeSettings()
{

    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    settings.setValue("layout", this->ui->boardLayoutBox->currentIndex());
    settings.setValue("language", this->ui->languageBox->currentIndex());
    settings.endGroup();
}

/**
 * Read settings from ini file
 *
 */
void SettingsDialog::readSettings()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    currentSettings.style = settings.value("layout").toInt();
    currentSettings.language = settings.value("language").toInt();
    this->applySettings();
    settings.endGroup();
}

/**
 * Apply settings to ui elements
 *
 */
void SettingsDialog::applySettings()
{
    this->ui->boardLayoutBox->setCurrentIndex(currentSettings.style);
    this->ui->languageBox->setCurrentIndex(currentSettings.language);
}

/**
 * Get the actual language from ini
 *
 * @return int
 */
int SettingsDialog::getLanguage()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    return settings.value("language").toInt();
}

/**
 * Get the actual style from ini
 *
 * @return int
 */
int SettingsDialog::getStyle()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    return settings.value("layout").toInt();
}

/**
 * Dialog close event
 *
 * @param button
 */
void SettingsDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    this->close();
}

/**
 * Language changed event (dropdown box)
 *
 * @param index
 */
void SettingsDialog::on_languageBox_currentIndexChanged(int index)
{
    currentSettings.language = index;
    switch (index) {
    case 0:
        if(translator.load("reversi_de", ":/languages")) {
            QCoreApplication::instance()->installTranslator(&translator);
        }
        break;
    case 1:
            QCoreApplication::instance()->removeTranslator(&translator);
        break;
    }

}

/**
 * Change event (need for runtime translation but doesn't work atm)
 *
 * @param event
 */
void SettingsDialog::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        //ui->retranslateUi(this);
    }
}
