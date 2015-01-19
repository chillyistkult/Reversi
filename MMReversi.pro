#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T01:06:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMReversi
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    boardwidget.cpp \
    game.cpp \
    board.cpp \
    settings.cpp \
    minimax.cpp

HEADERS  += mainwindow.h \
    boardwidget.h \
    boardwidget.h \
    game.h \
    board.h \
    settings.h \
    minimax.h

FORMS    += mainwindow.ui \
    settings.ui
