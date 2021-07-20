#include "dbmodel.h"

dbModel::dbModel(QObject *parent) : QObject(parent)
{
// Constructor
}

void dbModel::loadModel(QString connName)
{
    // Define model
    model = new QSqlTableModel(0,QSqlDatabase::database(connName));

    // set model to table
    model->setTable("AutoDbTable");

    // Activate model
    model->select();
}

void dbModel::deleteRow(int row)
{
    // Delete the given row
    model->removeRow(row);

    // Activate changes
    model->submitAll();
    model->select();
}

void dbModel::addValues(QString firstname, QString lastname, int age, float weight)
{
    // Add row at the end
    int row = model->rowCount();
    model->insertRows(row,1);

    // add data to the row
    model->setData(model->index(row, 1), firstname);
    model->setData(model->index(row, 2), lastname);
    model->setData(model->index(row, 3), age);
    model->setData(model->index(row, 4), weight);

    // Activate changes
    model->submitAll();
    model->select();

    // Sort
    model->sort(4, Qt::AscendingOrder);
}


