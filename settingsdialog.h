#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QAbstractButton>
#include <QTranslator>

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

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_languageBox_currentIndexChanged(int index);

protected:
    void changeEvent(QEvent *e);

private:
    void writeSettings();
    void readSettings();
    void applySettings();
    Settings currentSettings;
    QTranslator translator;
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
