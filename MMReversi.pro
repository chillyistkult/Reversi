#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T01:06:44
#
#-------------------------------------------------

QT       += core gui multimedia widgets sql testlib

greaterThan(QT_MAJOR_VERSION, 4):

TARGET = MMReversi
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    boardwidget.cpp \
    game.cpp \
    board.cpp \
    gamedialog.cpp \
    settingsdialog.cpp \
    minimax.cpp \
    highscore.cpp \
    test/test1.cpp \
    test/test2.cpp \
    test/gametest.cpp

TRANSLATIONS = reversi_de.ts

HEADERS  += mainwindow.h \
    boardwidget.h \
    game.h \
    board.h \
    gamedialog.h \
    settingsdialog.h \
    minimax.h \
    highscore.h \
    AutoTest.h \
    test/test1.h \
    test/test2.h \
    test/gametest.h

FORMS    += mainwindow.ui \
    gamedialog.ui \
    settingsdialog.ui \
    highscore.ui

RESOURCES += \
    resources.qrc
