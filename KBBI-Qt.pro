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


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/tentang.cpp \
    src/puebi.cpp

HEADERS  += src/mainwindow.h \
    src/tentang.h \
    src/puebi.h

FORMS    += src/mainwindow.ui \
    src/tentang.ui \
    src/puebi.ui

RESOURCES += \
    src/resource.qrc

# hanya dicoba di output 32bit
win32 {
    RC_FILE += src/kbbi-qt.rc
    DB_FILE = KBBI.db
    PWD_SOURCE = $${PWD}
    PWD_SOURCE ~= s,/,\\,g
    PWD_DEST = $${OUT_PWD}
    PWD_DEST ~= s,/,\\,g

    CONFIG(release, debug|release) {
        QMAKE_POST_LINK += $$quote(${COPY} $${PWD_SOURCE}\\src\\data\\$${DB_FILE} $${PWD_DEST}\\release\\)
#        QMAKE_CLEAN += $$quote(release\\$${DB_FILE})
    }

    CONFIG(debug, debug|release) {
        QMAKE_POST_LINK += $$quote(${COPY} $${PWD_SOURCE}\\src\\data\\$${DB_FILE} $${PWD_DEST}\\debug\\)
#        QMAKE_CLEAN += $$quote(debug\\$${DB_FILE})
    }

}

unix {
	INSTALLBASE = /usr
	target.path = $$INSTALLBASE/bin
	dbtarget.path = $$INSTALLBASE/share/$$TARGET/data
	dbtarget.files += src/data/KBBI.db src/data/*.html
	htmlresources.path = $$INSTALLBASE/share/$$TARGET/data/uB5I0d8t
        htmlresources.files += src/data/uB5I0d8t/*
	icons.path = $$INSTALLBASE/share/pixmaps
	icons.files = src/KBBI-qt.png
        docs.path = $$INSTALLBASE/share/doc/$$TARGET/
        docs.files += AUTHORS LICENSE README.md
        manuals.path = $$INSTALLBASE/share/doc/$$TARGET/manual/
        manuals.files += doc/dokumentasi.md
        manuals_img.path = $$INSTALLBASE/share/doc/$$TARGET/manual/gbr
        manuals_img.files += doc/gbr/*
	desktop.path = $$INSTALLBASE/share/applications/
	desktop.files = KBBI-Qt.desktop
	INSTALLS += target  dbtarget icons docs manuals manuals_img desktop htmlresources
}
