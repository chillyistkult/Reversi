#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T01:06:44
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMReversi
TEMPLATE = app


SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/boardwidget.cpp \
    src/game.cpp \
    src/board.cpp \
    src/minimax.cpp \
    src/gamedialog.cpp \
    src/settings.cpp

HEADERS  += src/mainwindow.h \
    src/boardwidget.h \
    src/boardwidget.h \
    src/game.h \
    src/board.h \
    src/minimax.h \
    src/gamedialog.h \
    src/settings.h

FORMS    += src/mainwindow.ui \
    src/gamedialog.ui \
    src/settings.ui

RESOURCES += \
    resources.qrc
