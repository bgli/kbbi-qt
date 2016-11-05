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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotCariKata();
    void pilihKata(QModelIndex index);

    void on_actionTentang_triggered();

    void on_checkAutoCari_clicked();

    void on_lineCari_textEdited(const QString &text);

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQueryModel *kamusModel;
    bool autoCari;

    // Action
    void copyDBfromRes();
    void searchQuery(QString keyword);
    void modifyHtmlTag(QString & text);

};

#endif // MAINWINDOW_H
