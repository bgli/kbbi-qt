#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init Database
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("KBBI.db");

    qDebug()<< "Is connect? " << database.open();

    QSqlQuery testquery;
    if(testquery.exec("SELECT COUNT(*) FROM test")){
        qDebug()<< "Query OK ";
    }else{
        qDebug()<< "Query Not OK ";
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
