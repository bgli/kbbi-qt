#include "tentang.h"
#include "ui_tentang.h"

tentang::tentang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tentang)
{
    ui->setupUi(this);
}

tentang::~tentang()
{
    delete ui;
}
