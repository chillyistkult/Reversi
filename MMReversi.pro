#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T01:06:44
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMReversi
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    boardwidget.cpp \
    game.cpp \
    board.cpp \
    minimax.cpp \
    gamedialog.cpp

HEADERS  += mainwindow.h \
    boardwidget.h \
    boardwidget.h \
    game.h \
    board.h \
    minimax.h \
    gamedialog.h

FORMS    += mainwindow.ui \
    gamedialog.ui

RESOURCES += \
    resources.qrc
