#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:

    struct Settings {
        int style;
        int language;
    };

    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
    Settings settings() const;
    int getLanguage();
    int getStyle();

private:
    void writeSettings();
    void readSettings();
    void applySettings();
    Settings currentSettings;
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
