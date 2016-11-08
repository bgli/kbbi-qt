#ifndef PUEBI_H
#define PUEBI_H

#include <QDialog>

namespace Ui {
class PUEBI;
}

class PUEBI : public QDialog
{
    Q_OBJECT

public:
    explicit PUEBI(QWidget *parent = 0);
    ~PUEBI();

private:
    Ui::PUEBI *ui;
};

#endif // PUEBI_H
