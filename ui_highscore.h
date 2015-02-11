/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORE_H
#define UI_HIGHSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Highscore
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Highscore)
    {
        if (Highscore->objectName().isEmpty())
            Highscore->setObjectName(QStringLiteral("Highscore"));
        Highscore->resize(400, 300);
        verticalLayout = new QVBoxLayout(Highscore);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(Highscore);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        buttonBox = new QDialogButtonBox(Highscore);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Highscore);
        QObject::connect(buttonBox, SIGNAL(accepted()), Highscore, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Highscore, SLOT(reject()));

        QMetaObject::connectSlotsByName(Highscore);
    } // setupUi

    void retranslateUi(QDialog *Highscore)
    {
        Highscore->setWindowTitle(QApplication::translate("Highscore", "Highscore", 0));
    } // retranslateUi

};

namespace Ui {
    class Highscore: public Ui_Highscore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
