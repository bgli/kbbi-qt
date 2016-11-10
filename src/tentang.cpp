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
#include "tentang.h"
#include "ui_tentang.h"
#include <QDebug>
#include <QDesktopServices>

tentang::tentang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tentang)
{
    ui->setupUi(this);

    connect(ui->listWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(onContributorItemClicked(QModelIndex)));
}

void tentang::onContributorItemClicked(QModelIndex index){
    int contribIndex = index.row();

    switch (contribIndex) {
    case 0:
        this->openGithub("antosamalona");
        break;
    case 1:
        this->openGithub("azispratama92");
        break;
    case 2:
        this->openGithub("as3mbus");
        break;
    case 3:
        this->openGithub("saa7go");
        break;
    case 4:
        this->openGithub("hahn");
        break;
    case 5:
        this->openGithub("alunux");
        break;
    case 6:
        this->openGithub("rafeyu");
        break;
    case 7:
        this->openGithub("raniaamina");
        break;
    case 8:
        this->openGithub("showcheap");
        break;
    default:
        qDebug()<<"Default";
        break;
    }
}

void tentang::openGithub(QString username){
    QDesktopServices::openUrl(QUrl("https://github.com/"+username));
}

tentang::~tentang()
{
    delete ui;
}
