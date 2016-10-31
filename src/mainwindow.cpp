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

    // Setup Signal and Slot cari
    connect(ui->btnCari,SIGNAL(clicked(bool)),this,SLOT(slotCariKata()));
    connect(ui->lineCari,SIGNAL(returnPressed()),this,SLOT(slotCariKata()));

    // Signal Slot pilih kata
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(pilihKata(QModelIndex)));
//    connect(ui->listView,SIGNAL(activated(QModelIndex)),this,SLOT(pilihKata(QModelIndex)));



    // Init Database
    QString     mNamaDb = "KBBI.db";
    QFileInfo   mFileDb(mNamaDb);

    // qDebug()<< "Lokasi DB : " << mFileDb.absoluteFilePath();

    // Chek File DB
    if(mFileDb.exists()){

        // qDebug()<< "File database ditemukan";

    }else{

        // qDebug()<< "File database tidak ditemukan";
        // Copy file dari resource jika database belum ada
        this->copyDBfromRes();

    }

    // Connect to DB
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("KBBI.db");
    database.open();

    // qDebug()<< "Is connect? " << database.open();

    QSqlQuery testquery;
    if(testquery.exec("SELECT COUNT(*) AS JUMLAH FROM datakata")){
        // qDebug()<< "Query OK ";

        while(testquery.next()){
            // qDebug()<< "Data : " << testquery.value("JUMLAH").toString();
        }
    }else{
        // qDebug()<< "Query Not OK ";
    }

    // Setup Query Model
    kamusModel = new QSqlQueryModel;
    kamusModel->setHeaderData(0,Qt::Horizontal,tr("Kata Kunci"));
    kamusModel->setHeaderData(1,Qt::Horizontal,tr("Arti Kata"));

    this->searchQuery("");

    ui->statusBar->showMessage("Memulai...",1000);

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

        // qDebug()<<"Berkas basis data berhasil disalin dari resource";
        ui->statusBar->showMessage("Berkas basis data berhasil disalin dari resource",5000);

    }else{

        // qDebug()<<"Gagal menyalin berkas dari file resource";
        ui->statusBar->showMessage("Gagal menyalin berkas dari file resource",5000);

    }
}

void MainWindow::searchQuery(QString keyword)
{
    // Bersihkan bekas pencarian
    kamusModel->clear();
    ui->detailResult->clear();
    ui->statusBar->showMessage("");

    // Dahulukan hasil dengan kata depan paling cocok
    QString queryCari = "SELECT katakunci,artikata FROM datakata WHERE katakunci like '"+keyword+"%'";

    // Jika Checkbox tercentang
    if(ui->chekCariDetail->checkState() == Qt::Checked){

        queryCari += " UNION ALL ";

        queryCari += "SELECT katakunci,artikata FROM datakata WHERE artikata like '%"+keyword+"%'";

    }


    if(keyword.isEmpty()){
        queryCari += " LIMIT 0,100";
    }

    // qDebug()<<queryCari;

    kamusModel->setQuery(queryCari);

//    QString resultCount = QString::number(kamusModel->rowCount());

    // ui->statusBar->showMessage("Menampilkan "+resultCount+" data");
    if(ui->listView->model()) {
        if(disconnect(ui->listView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(pilihKata(QModelIndex))))
        {
            qDebug() << "Disconnect successfull!";
        } else {
            qDebug() << "Unable to disconnect";
        }
    }
    ui->listView->setModel(kamusModel);
    connect(ui->listView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(pilihKata(QModelIndex)));

    // Set focus kembali ke lineEdit
    ui->lineCari->setFocus();

    if(kamusModel->rowCount() > 0){
        QModelIndex firstRow = kamusModel->index(0,0);
        ui->listView->setCurrentIndex(firstRow);
        emit ui->listView->activated(firstRow);
//        ui->listView->selectionModel()->select(firstRow, QItemSelectionModel::Select);
    }else{
        ui->statusBar->showMessage("Tidak ada data yang cocok dengan kata kunci \""+keyword+"\"");
    }
}

void MainWindow::slotCariKata()
{
    QString keyword = ui->lineCari->text();
    this->searchQuery(keyword);
}

void MainWindow::pilihKata(QModelIndex index)
{

    QString resultText = kamusModel->data(index.sibling(index.row(),1)).toString();

    QTextDocument doc;
    doc.setHtml(resultText);

    ui->detailResult->setText(doc.toPlainText());

}

MainWindow::~MainWindow()
{
    delete ui;
}


