#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T00:03:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KBBI-Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mydialog.cpp

HEADERS  += mainwindow.h \
    mydialog.h

FORMS    += mainwindow.ui \
    mydialog.ui

RESOURCES += \
    resource.qrc
