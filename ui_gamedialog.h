/********************************************************************************
** Form generated from reading UI file 'gamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEDIALOG_H
#define UI_GAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GameDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QCheckBox *player1CheckBox;
    QLabel *label_6;
    QLineEdit *playerName1Edit;
    QLabel *label;
    QCheckBox *player2CheckBox;
    QLineEdit *playerName2Edit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QComboBox *difficultyBox;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *boardSizeSlider;
    QLabel *boardSizeValueLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GameDialog)
    {
        if (GameDialog->objectName().isEmpty())
            GameDialog->setObjectName(QStringLiteral("GameDialog"));
        GameDialog->resize(288, 255);
        verticalLayout_2 = new QVBoxLayout(GameDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(GameDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        player1CheckBox = new QCheckBox(groupBox);
        player1CheckBox->setObjectName(QStringLiteral("player1CheckBox"));
        player1CheckBox->setChecked(true);

        gridLayout->addWidget(player1CheckBox, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        playerName1Edit = new QLineEdit(groupBox);
        playerName1Edit->setObjectName(QStringLiteral("playerName1Edit"));

        gridLayout->addWidget(playerName1Edit, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        player2CheckBox = new QCheckBox(groupBox);
        player2CheckBox->setObjectName(QStringLiteral("player2CheckBox"));

        gridLayout->addWidget(player2CheckBox, 1, 2, 1, 1);

        playerName2Edit = new QLineEdit(groupBox);
        playerName2Edit->setObjectName(QStringLiteral("playerName2Edit"));
        playerName2Edit->setEnabled(false);

        gridLayout->addWidget(playerName2Edit, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(GameDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        difficultyBox = new QComboBox(groupBox_2);
        difficultyBox->setObjectName(QStringLiteral("difficultyBox"));

        gridLayout_2->addWidget(difficultyBox, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        boardSizeSlider = new QSlider(groupBox_2);
        boardSizeSlider->setObjectName(QStringLiteral("boardSizeSlider"));
        boardSizeSlider->setMinimum(6);
        boardSizeSlider->setMaximum(20);
        boardSizeSlider->setValue(8);
        boardSizeSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(boardSizeSlider, 1, 1, 1, 1);

        boardSizeValueLabel = new QLabel(groupBox_2);
        boardSizeValueLabel->setObjectName(QStringLiteral("boardSizeValueLabel"));
        boardSizeValueLabel->setLineWidth(1);
        boardSizeValueLabel->setAlignment(Qt::AlignCenter);
        boardSizeValueLabel->setMargin(0);

        gridLayout_2->addWidget(boardSizeValueLabel, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(GameDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(GameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GameDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(GameDialog);
    } // setupUi

    void retranslateUi(QDialog *GameDialog)
    {
        GameDialog->setWindowTitle(QApplication::translate("GameDialog", "New Game", 0));
        groupBox->setTitle(QApplication::translate("GameDialog", "Player", 0));
        player1CheckBox->setText(QString());
        label_6->setText(QApplication::translate("GameDialog", "Player 2:", 0));
        playerName1Edit->setText(QString());
        label->setText(QApplication::translate("GameDialog", "Player 1:", 0));
        player2CheckBox->setText(QString());
        playerName2Edit->setText(QString());
        groupBox_2->setTitle(QApplication::translate("GameDialog", "Game", 0));
        difficultyBox->clear();
        difficultyBox->insertItems(0, QStringList()
         << QApplication::translate("GameDialog", "Easy", 0)
         << QApplication::translate("GameDialog", "Medium", 0)
         << QApplication::translate("GameDialog", "Hard", 0)
         << QApplication::translate("GameDialog", "Godlike", 0)
        );
        label_2->setText(QApplication::translate("GameDialog", "AI:", 0));
        label_3->setText(QApplication::translate("GameDialog", "Boardsize:", 0));
        boardSizeValueLabel->setText(QApplication::translate("GameDialog", "8", 0));
#ifndef QT_NO_WHATSTHIS
        buttonBox->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class GameDialog: public Ui_GameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEDIALOG_H
