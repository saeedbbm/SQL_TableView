#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDateTime>
#include <stdlib.h>
#include <typeinfo>
#include <QDir>

#include "dbmodel.h"
#include "mydatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addValuesPrepare();
//    void addValues(QString firstname, QString lastname, int age, float weight);

    void deleteRowPrepare();
//    void deleteRow(int row);

     void copyRow();
     void LastEntryFunc();


private:
    Ui::MainWindow *ui;

//    QSqlTableModel *model;
//    QSqlDatabase database;
//    QSqlQueryModel *querymodel;


    MyDatabase mydatabase;
    dbModel dbmodel;

};
#endif // MAINWINDOW_H
