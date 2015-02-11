#include "highscore.h"
#include "ui_highscore.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Highscore::Highscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Highscore)
{
    ui->setupUi(this);
    this->load();
}

Highscore::~Highscore()
{
    delete ui;
}

void Highscore::load()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./highscore.db");
    db.open();

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.exec("SELECT * FROM score");
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Player 1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Player 2"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Score"));
    this->ui->tableView->setModel(model);
    this->ui->tableView->hideColumn(0);
}
