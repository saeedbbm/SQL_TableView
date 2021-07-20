#ifndef DBMODEL_H
#define DBMODEL_H

#include <QObject>
#include <QMessageBox>
#include <QDir>

#include <QSql>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>


class dbModel : public QObject
{
    Q_OBJECT
public:
    explicit dbModel(QObject *parent = nullptr);

    void loadModel(QString connName);
    void deleteRow(int row);
    void addValues(QString firstname, QString lastname, int age, float weight);



    QSqlTableModel *model;
    QSqlDatabase database;
    QSqlQueryModel *querymodel;

signals:

};

#endif // DBMODEL_H
