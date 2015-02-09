#include "highscore.h"
#include "ui_highscore.h"

Highscore::Highscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Highscore)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("highscore.sqlite");
    db.open();

    model = new QSqlQueryModel();
    model->setQuery("select * from scores", db);
    QSqlTableModel *model = new QSqlTableModel(parent, db);
    model->setTable("A");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, tr("Column 1"));
    model->setHeaderData(1, Qt::Horizontal, tr("Column 2"));

    // Attach it to the view
    ui->tableView->setModel(model);
}

Highscore::~Highscore()
{
    delete ui;
}
