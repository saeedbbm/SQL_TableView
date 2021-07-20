#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QDir>

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

class MyDatabase : public QObject
{
    Q_OBJECT
public:
    explicit MyDatabase(QObject *parent = nullptr);

    void loadDb(QString path, QString connName);
    void createTable(QString connName);
    QVariant EntryFunc(int column, QString connName);

    QSqlDatabase database;
    QSqlQueryModel *querymodel;

signals:

};

#endif // MYDATABASE_H
