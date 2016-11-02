#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
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
    kamusModel = new QSqlQueryModel(this);
    kamusModel->setHeaderData(0,Qt::Horizontal,tr("Kata Kunci"));
    kamusModel->setHeaderData(1,Qt::Horizontal,tr("Arti Kata"));
    ui->listView->setModel(kamusModel);
    connect(ui->listView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(pilihKata(QModelIndex)));

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

    // Set focus kembali ke lineEdit
    ui->lineCari->setFocus();

    if(kamusModel->rowCount() > 0){
        QModelIndex firstRow = kamusModel->index(0,0);
        ui->listView->setCurrentIndex(firstRow);
    }else{
        ui->statusBar->showMessage("Tidak ada data yang cocok dengan kata kunci \""+keyword+"\"");
    }
}

void MainWindow::modifyHtmlTag(QString &text)
{
    text.replace(0, QString("<b>").length(), "<b style='color:red;background-color:yellow'>");
    text.replace("<b>", "<b style='color:red'>");
    text.replace("<i>n</i>", "<i style='color:blue'>n</i>");
    text.replace("<i>v</i>", "<i style='color:blue'>v</i>");
    text.replace("<i>", "<i style='color:green'>");
    text.replace("<br>", "<br/>");

    const QString awalan("--<b");
    const QString akhiran(";");
    const QString tag_start("<div style='margin-left:20px;margin-top:0px;margin-bottom:10px;margin-right:0px;'>");
    const QString tag_end("</div>");

    int current_index;

    // cek ada list atau tidak (--<b>text)
    current_index = text.indexOf(awalan);

    // list tidak ditemukan
    if(current_index == -1)
        return;
    else {  // list ditemukan
        for(;;) {
//            previous_index = current_index;
            text.insert(current_index, tag_start);
            current_index = text.indexOf(akhiran, current_index + tag_start.length());
            text.insert(current_index+akhiran.length(), tag_end);

            current_index = text.indexOf(awalan,current_index + akhiran.length() + tag_end.length());
            if(current_index == -1)
                break;
        }
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

    QString modifiedText = doc.toPlainText();
    modifyHtmlTag(modifiedText);

    ui->detailResult->setText(modifiedText);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionTentang_triggered()
{
    MyDialog mDialog;
    mDialog.setModal(true);
    mDialog.exec();
}
