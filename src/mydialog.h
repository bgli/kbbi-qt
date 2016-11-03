/*  KBBI Qt is a GUI based C++/Qt Framework program for The Big Indonesian Language Dictionary. 
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
    This file is written by Sucipto <admin@sucipto.net> at 2016-10-25T00:03:13. */
#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
