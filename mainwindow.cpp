#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Database is loaded from mydatabase CLASS
    // Model is loaded from dbModel CLASS
    mydatabase.loadDb("/database_101.sqlite", "AutoConnName");
    dbmodel.loadModel("AutoConnName");

    // Table needs a model.
    ui->tableView->setModel(dbmodel.model);
    // Model sorted
    dbmodel.model->sort(4, Qt::AscendingOrder);

    // Values are first prepared here, then passed to model to make the change
    connect(ui->btnAdd,&QPushButton::clicked,this,&MainWindow::addValuesPrepare);
    connect(ui->btnDelete,&QPushButton::clicked,this,&MainWindow::deleteRowPrepare);
    connect(ui->btnCopy,&QPushButton::clicked,this,&MainWindow::copyRow);
    connect(ui->btnLast,&QPushButton::clicked,this,&MainWindow::LastEntryFunc);
}

MainWindow::~MainWindow()
{
    delete ui;
    dbmodel.database.close();
}

void MainWindow::addValuesPrepare()
{
    // Reads the values and change their format to appropriate type
    QString firstname = ui->txtFirstname->text();
    QString lastname = ui->txtLastname->text();
    int age = ui->txtAge->text().toInt();
    float weight = ui->txtWeight->text().toFloat();

    // Passes values to the model to be added to the database
    dbmodel.addValues(firstname, lastname, age, weight);

    // Clears the lineEdit boxes
    ui->txtFirstname->clear();
    ui->txtLastname->clear();
    ui->txtAge->clear();
    ui->txtWeight->clear();
}

void MainWindow::deleteRowPrepare()
{
    // Reads the selected row number
    int row = ui->tableView->currentIndex().row();
    // Passes the row number to the model to be deleted
    if (row < 0) {return;} else {dbmodel.deleteRow(row);}
}

void MainWindow::copyRow()
{
    // Reads the selected row number
    int row = ui->tableView->currentIndex().row();
    // Assign values to LineEdits from database
    ui->txtFirstname->setText(dbmodel.model->index(row,1).data().toString());
    ui->txtLastname->setText(dbmodel.model->index(row,2).data().toString());
    ui->txtAge->setText(dbmodel.model->index(row,3).data().toString());
    ui->txtWeight->setText(QString::number(dbmodel.model->index(row,4).data().toFloat(), 'f', 2));
}

void MainWindow::LastEntryFunc()
{
    // Query one value at a time and convert it to appropriate format
   ui->txtFirstname->setText(mydatabase.EntryFunc(1,"AutoConnName").toString());
   ui->txtLastname->setText(mydatabase.EntryFunc(2,"AutoConnName").toString());
   ui->txtAge->setText(mydatabase.EntryFunc(3,"AutoConnName").toString());
   ui->txtWeight->setText(QString::number(mydatabase.EntryFunc(4,"AutoConnName").toFloat(), 'f', 2));
}

