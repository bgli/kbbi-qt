#ifndef TENTANG_H
#define TENTANG_H

#include <QDialog>

namespace Ui {
class tentang;
}

class tentang : public QDialog
{
    Q_OBJECT

public:
    explicit tentang(QWidget *parent = 0);
    ~tentang();

private:
    Ui::tentang *ui;
};

#endif // tentang_H
