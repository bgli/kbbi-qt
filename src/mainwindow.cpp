#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlQuery>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init Database
    QString     mNamaDb = "KBBI.db";
    QFileInfo   mFileDb(mNamaDb);

    qDebug()<< "Lokasi DB : " << mFileDb.absoluteFilePath();

    // Chek File DB
    if(mFileDb.exists()){

        qDebug()<< "File database ditemukan";

    }else{

        qDebug()<< "File database tidak ditemukan";
        // Copy file dari resource jika database belum ada
        this->copyDBfromRes();

    }

    // Connect to DB
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("KBBI.db");

    qDebug()<< "Is connect? " << database.open();

    QSqlQuery testquery;
    if(testquery.exec("SELECT COUNT(*) AS JUMLAH FROM datakata")){
        qDebug()<< "Query OK ";

        while(testquery.next()){
            qDebug()<< "Data : " << testquery.value("JUMLAH").toString();
        }
    }else{
        qDebug()<< "Query Not OK ";
    }
}

void MainWindow::copyDBfromRes(){
    // Nama File output copy
    // Tanpa full absolute path supaya diletakkan satu level
    // di direktori yang sama dengan file aplikasi
    QString fileOut = "KBBI.db";

    // Copy File dari Resource File
    if(QFile::copy(":/data/KBBI.db",fileOut)){

        // Jika berhasil dicopy, set permisson supaya bisa di read
        QFile dbFile(fileOut);
        dbFile.setPermissions(QFile::ReadUser);

        qDebug()<<"Berkas basis data berhasil disalin dari resource";

    }else{

        qDebug()<<"Gagal menyalin berkas dari file resource";

    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
