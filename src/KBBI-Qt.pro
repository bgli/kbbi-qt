# KBBI Qt is KBBI Qt is a GUI based C++/Qt Framework program for The Big Indonesian Language Dictionary.
# Copyright (C) 2016 KBBI Qt Team <https://github.com/bgli/kbbi-qt>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# This file is a part of KBBI Qt source code. 
# This file is written by Sucipto <admin@sucipto.net> and Rania el-Amina <reaamina@gmail.com>.
# 
#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T00:03:13
#
#-------------------------------------------------

QT       += core gui sql network webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KBBI-Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tentang.cpp \
    puebi.cpp

HEADERS  += mainwindow.h \
    tentang.h \
    puebi.h

FORMS    += mainwindow.ui \
    tentang.ui \
    puebi.ui

RESOURCES += \
    resource.qrc

# hanya dicoba di output 32bit
win32 {
    # belum dicoba
    equals(QT_MAJOR_VERSION, 4) {
        RC_FILE += kbbi-qt.rc
    }

    # sudah dicoba
    equals(QT_MAJOR_VERSION, 5) {
        RC_ICONS = kbbi-qt.ico
    }
}
