/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BoardWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exit;
    QAction *settings;
    QAction *actionShow;
    QAction *actionPlayer_vs_Computer;
    QAction *actionPlayer_vs_Player;
    QAction *actionSettings;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    BoardWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *soundBox;
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNewGame;
    QMenu *menuHelp;
    QMenu *menuHighscore;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 600);
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        settings = new QAction(MainWindow);
        settings->setObjectName(QStringLiteral("settings"));
        actionShow = new QAction(MainWindow);
        actionShow->setObjectName(QStringLiteral("actionShow"));
        actionShow->setEnabled(false);
        actionPlayer_vs_Computer = new QAction(MainWindow);
        actionPlayer_vs_Computer->setObjectName(QStringLiteral("actionPlayer_vs_Computer"));
        actionPlayer_vs_Player = new QAction(MainWindow);
        actionPlayer_vs_Player->setObjectName(QStringLiteral("actionPlayer_vs_Player"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new BoardWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        soundBox = new QCheckBox(centralWidget);
        soundBox->setObjectName(QStringLiteral("soundBox"));

        horizontalLayout->addWidget(soundBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(false);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        menuBar->setFont(font);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNewGame = new QMenu(menuFile);
        menuNewGame->setObjectName(QStringLiteral("menuNewGame"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        menuNewGame->setFont(font1);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setEnabled(false);
        menuHelp->setAutoFillBackground(false);
        menuHighscore = new QMenu(menuBar);
        menuHighscore->setObjectName(QStringLiteral("menuHighscore"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHighscore->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuNewGame->menuAction());
        menuFile->addAction(actionSettings);
        menuFile->addAction(exit);
        menuNewGame->addAction(actionPlayer_vs_Computer);
        menuNewGame->addAction(actionPlayer_vs_Player);
        menuHighscore->addAction(actionShow);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Reversi", 0));
        exit->setText(QApplication::translate("MainWindow", "Exit", 0));
        settings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionShow->setText(QApplication::translate("MainWindow", "Show", 0));
        actionPlayer_vs_Computer->setText(QApplication::translate("MainWindow", "Player vs. Computer", 0));
        actionPlayer_vs_Player->setText(QApplication::translate("MainWindow", "Player vs. Player", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        soundBox->setText(QApplication::translate("MainWindow", "Sound", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Share highscore", 0));
#ifndef QT_NO_WHATSTHIS
        statusBar->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        menuFile->setTitle(QApplication::translate("MainWindow", "Game", 0));
        menuNewGame->setTitle(QApplication::translate("MainWindow", "New", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuHighscore->setTitle(QApplication::translate("MainWindow", "Highscore", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
