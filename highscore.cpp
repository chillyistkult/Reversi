#include "highscore.h"
#include "ui_highscore.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

/**
 * Constructor
 *
 * @param parent
 */
Highscore::Highscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Highscore)
{
    ui->setupUi(this);
    this->load();
}

/**
 * Destructor
 * Removes all database connections
 */
Highscore::~Highscore()
{
    QStringList list = QSqlDatabase::connectionNames();
    for(int i = 0; i < list.count(); ++i) {
        QSqlDatabase::removeDatabase(list[i]);
    }
    delete ui;
}

/**
 * Loads the highscore from database
 *
 */
void Highscore::load()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "Highscore");
    db.setDatabaseName("./highscore.db");
    if (db.open()) {
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query(db);
        query.exec("SELECT * FROM score ORDER BY ABS(score1-score2) DESC");
        model->setQuery(query);
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Player 1"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Player 2"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr(""));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr(""));
        this->ui->tableView->setModel(model);
        this->ui->tableView->hideColumn(0);
    }
    db.close();
}
