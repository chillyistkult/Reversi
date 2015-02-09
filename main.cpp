#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>
#include <QSettings>


//Application entry point
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    switch (settings.value("language").toInt()) {
    case 0:
        if(translator.load("reversi_de", ":/languages")) {
             a.installTranslator(&translator);
        }
        break;
    default:
        break;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
