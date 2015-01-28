/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QComboBox *boardLayoutBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *languageBox;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(204, 99);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        boardLayoutBox = new QComboBox(Settings);
        boardLayoutBox->setObjectName(QStringLiteral("boardLayoutBox"));

        gridLayout->addWidget(boardLayoutBox, 0, 1, 1, 1);

        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Settings);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        languageBox = new QComboBox(Settings);
        languageBox->setObjectName(QStringLiteral("languageBox"));

        gridLayout->addWidget(languageBox, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", 0));
        boardLayoutBox->clear();
        boardLayoutBox->insertItems(0, QStringList()
         << QApplication::translate("Settings", "Default", 0)
         << QApplication::translate("Settings", "Woody", 0)
         << QApplication::translate("Settings", "Super Mario", 0)
        );
        label->setText(QApplication::translate("Settings", "Board layout:", 0));
        label_2->setText(QApplication::translate("Settings", "Language:", 0));
        languageBox->clear();
        languageBox->insertItems(0, QStringList()
         << QApplication::translate("Settings", "German", 0)
         << QApplication::translate("Settings", "English", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
