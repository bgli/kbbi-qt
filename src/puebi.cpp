#include "puebi.h"
#include "ui_puebi.h"

PUEBI::PUEBI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PUEBI)
{
    ui->setupUi(this);
}

PUEBI::~PUEBI()
{
    delete ui;
}
