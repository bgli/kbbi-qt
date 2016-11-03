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
    tentang.cpp

HEADERS  += mainwindow.h \
    tentang.h

FORMS    += mainwindow.ui \
    tentang.ui

RESOURCES += \
    resource.qrc
