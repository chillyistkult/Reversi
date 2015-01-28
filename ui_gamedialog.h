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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *playerName1Edit;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QLabel *label_6;
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
        GameDialog->resize(268, 282);
        verticalLayout_2 = new QVBoxLayout(GameDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(GameDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        playerName1Edit = new QLineEdit(groupBox);
        playerName1Edit->setObjectName(QStringLiteral("playerName1Edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, playerName1Edit);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        playerName2Edit = new QLineEdit(groupBox);
        playerName2Edit->setObjectName(QStringLiteral("playerName2Edit"));
        playerName2Edit->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, playerName2Edit);


        verticalLayout_4->addLayout(formLayout);


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
        QObject::connect(buttonBox, SIGNAL(rejected()), GameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GameDialog);
    } // setupUi

    void retranslateUi(QDialog *GameDialog)
    {
        GameDialog->setWindowTitle(QApplication::translate("GameDialog", "New Game", 0));
        groupBox->setTitle(QApplication::translate("GameDialog", "Player", 0));
        label->setText(QApplication::translate("GameDialog", "Player 1:", 0));
        playerName1Edit->setText(QApplication::translate("GameDialog", "White", 0));
        label_4->setText(QApplication::translate("GameDialog", "Token:      ", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("GameDialog", "White", 0)
         << QApplication::translate("GameDialog", "Black", 0)
        );
        label_5->setText(QApplication::translate("GameDialog", "<html><head/><body><p><span style=\" font-size:6pt; font-style:italic;\">Note: Black starts.</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("GameDialog", "Player 2:", 0));
        playerName2Edit->setText(QApplication::translate("GameDialog", "Black", 0));
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
