/*
    KBBI Qt is a GUI based C++/Qt Framework program for The Big Indonesian Language Dictionary. 
    
    Copyright (C) 2016 KBBI Qt Team <https://github.com/bgli/kbbi-qt>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    This file is a part of KBBI Qt source code. 
    This file is written by Sucipto <admin@sucipto.net>, 
    Christian Kurniawan <saa7.go@gmail.com>, and 
    Rania el-Amina <reaamina@gmail.com>. 
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tentang.h"
#include <QDebug>
#include <QSqlQuery>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btnCari->hide();

    connect(ui->actionTentang, SIGNAL(triggered()), this, SLOT(onActionTentangTriggered()));

    // Setup Signal and Slot cari
    connect(ui->btnCari,SIGNAL(clicked(bool)),this,SLOT(slotCariKata()));
    connect(ui->lineCari,SIGNAL(returnPressed()),this,SLOT(slotCariKata()));

    // Signal Slot pilih kata
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(pilihKata(QModelIndex)));

    // Init Database
    QString     mNamaDb = "KBBI.db";
    QFileInfo   mFileDb(mNamaDb);

    // Chek File DB
    if(!mFileDb.exists()){

        // Copy file dari resource jika database belum ada
        this->copyDBfromRes();

    }

    // Connect to DB
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("KBBI.db");
    database.open();


    // Setup Query Model
    kamusModel = new QSqlQueryModel(this);
    ui->listView->setModel(kamusModel);

    connect(ui->listView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(pilihKata(QModelIndex)));

    this->doSearch("");

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

void MainWindow::doSearch(const QString& keyword)
{
    if (keyword.size() <= 0)
        return;

    // Bersihkan bekas pencarian
    kamusModel->clear();
    ui->detailResult->clear();
    ui->statusBar->showMessage("");

    // Dahulukan hasil dengan kata depan paling cocok
    QString queryCari = "SELECT katakunci,artikata FROM datakata WHERE katakunci like '"+keyword+"%'\n";

    // Jika Checkbox tercentang
    if(ui->chekCariDetail->checkState() == Qt::Checked){

        queryCari += " UNION ALL \n";

        queryCari += "SELECT katakunci,artikata FROM datakata WHERE artikata like '%"+keyword+"%'\n";

    }

    queryCari += "  ORDER BY katakunci ASC\n";

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
    const QString &akhiran2 = awalan;
    const QString tag_start("<div style='margin-left:20px;margin-top:0px;margin-bottom:10px;margin-right:0px;'>");
    const QString tag_end("</div>");

    int current_index, end_index;

    // cek ada list atau tidak (--<b>text)
    current_index = text.indexOf(awalan);

    // list tidak ditemukan
    if(current_index == -1)
        return;
    else {  // list ditemukan
        for(;;) {
            text.insert(current_index, tag_start);
            end_index = text.indexOf(akhiran2, current_index + tag_start.length() + awalan.length());

            // tidak ditemukan list berikutnya
            if(end_index == -1) {
                // cari titik koma jika list tidak ditemukan
                end_index = text.indexOf(akhiran, current_index + tag_start.length());

                // tidak ditemukan titik koma (;), paksa akhiran menggunakan </div>
                if(end_index == -1) {
                    text.insert(text.length(), tag_end);
                    break;
                } else {
                    text.insert(end_index + akhiran.length(), tag_end);
                    break;
                }
            } else {
                text.insert(end_index, tag_end);

                current_index = text.indexOf(awalan,end_index + tag_end.length());
                if(current_index == -1)
                    break;
            }
        }
    }
}

void MainWindow::slotCariKata()
{
    QString keyword = ui->lineCari->text();
    this->doSearch(keyword);
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


void MainWindow::onActionTentangTriggered()
{
    tentang tentang(this);
    tentang.exec();
}

void MainWindow::onCheckAutoCariToggled(bool checked)
{
    if (checked)
        connect(ui->lineCari, SIGNAL(textChanged(QString)), this, SLOT(doSearch(QString)));
    else
        disconnect(ui->lineCari, SIGNAL(textChanged(QString)), this, SLOT(doSearch(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
