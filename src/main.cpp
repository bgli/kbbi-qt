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
    This file is written by Sucipto <admin@sucipto.net> at 2016-10-25T00:03:13. 
*/
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbPath = QDir::currentPath() + "/" + DB_NAME;

    if(!QFile::exists(dbPath)) {
        QMessageBox::critical(0, "Database Galat", "Berkas database " + DB_NAME + " tidak ditemukan!");
        return 1;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if(!db.isValid()) {
        QMessageBox::critical(0, "Database Galat", "Driver Database tidak tersedia");
        return 1;
    }

    db.setDatabaseName(DB_NAME);
    if(!db.open()) {
        QMessageBox::critical(0, "Database Galat", "Gagal membuka database");
        return 1;
    } else { // test query
        QSqlQuery testquery;
        if(testquery.exec("SELECT COUNT(_id) AS JUMLAH FROM datakata")){
            if(testquery.next()) {
                if(testquery.value(0).toInt() != 35969) {
                    QMessageBox::critical(0, "Database Galat", "Database tidak valid!");
                    return 1;
                }
            }
        }else{
            QMessageBox::critical(0, "Database Galat", "Database tidak valid!");
            return 1;
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
