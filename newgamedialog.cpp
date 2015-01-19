#include "newgamedialog.h"
#include "ui_newgamedialog.h"
#include<QDebug>

newGameDialog::newGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newGameDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Play!"));
}

newGameDialog::~newGameDialog()
{
    delete ui;
}

int newGameDialog::getBoardSize() {
    return settings.boardSize;
}

void newGameDialog::on_buttonBox_accepted()
{
    qDebug() << "Auf gehts!";

}

void newGameDialog::on_buttonBox_rejected()
{

}

void newGameDialog::on_boardSizeSlider_valueChanged(int value)
{
    this->ui->boardSizeValueLabel->setText(QString::number(this->ui->boardSizeSlider->value()));
    settings.boardSize = this->ui->boardSizeSlider->value();
}
