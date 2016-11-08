#include "puebi.h"
#include "ui_puebi.h"
#include "QtWebKit/QWebView"

PUEBI::PUEBI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PUEBI)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl("file:///usr/share/KBBI-Qt/data/puebi.html"));
}

PUEBI::~PUEBI()
{
    delete ui;
}
