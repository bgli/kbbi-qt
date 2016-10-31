#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotCariKata();
    void pilihKata(QModelIndex index);

    void on_actionTentang_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQueryModel *kamusModel;

    // Action
    void copyDBfromRes();
    void searchQuery(QString keyword);

};

#endif // MAINWINDOW_H
