#include "mydatabase.h"

MyDatabase::MyDatabase(QObject *parent) : QObject(parent)
{
// Constructor
}

void MyDatabase::loadDb(QString path, QString connName)
{
    // Loads Database
    database = QSqlDatabase::addDatabase("QSQLITE",connName);
    database.setDatabaseName(QDir::currentPath() + path);

    if (database.open())
    {
        qDebug() << connName << "DB loading is Successful";
    }
    else
    {
//        QMessageBox::information(this,"Failed","Connection Failed");
        qDebug() << connName << "DB loading Failled";
    }

    // Create Table in Database
    createTable(connName);
}

void MyDatabase::createTable(QString connName)
{
    // Query String for creating table if does not exist
    QString query = " CREATE TABLE IF NOT EXISTS AutoDbTable ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL,"
                        "FirstName VARCHAR(20),"
                        "LastName VARCHAR(20),"
                        "Age integer,"
                        "Weight float);";

    // runs the query
    QSqlQuery qry(QSqlDatabase::database(connName));
    if (!qry.exec(query))
    {
        qDebug() << "Table Creation Failled";
    }
}

QVariant MyDatabase::EntryFunc(int column, QString connName)
{
    // Query String for  selecting the last Entry to the table
    QString query = "SELECT * FROM AutoDbTable ORDER BY ID DESC LIMIT 1";

    // Runs the query
    QSqlQuery qry(QSqlDatabase::database(connName));
    qry.exec(query);
    qry.first();

    // Returns the result of the query
    return qry.value(column);

}

