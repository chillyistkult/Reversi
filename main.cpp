#include "mainwindow.h"
#include "AutoTest.h"

#include <QApplication>
#include <QTranslator>
#include <QSettings>


#if 0
// This is (hopefully) all I need to run the tests
TEST_MAIN
#else
//Application entry point
/**
 * Holy main method
 * Initialize tests and translator
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{

    int failures = AutoTest::run(argc, argv);
    if (failures == 0)
    {
        qDebug() << "ALL TESTS PASSED";
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
    else
    {
        qDebug() << failures << " TESTS FAILED!";
    }
    return failures;
}
#endif
