#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "beverage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rbBeverage_clicked();

    void on_btnDeposit_clicked();

    void on_btnBuy_clicked();

private:
    Ui::MainWindow *ui;
    Beverage* currBeverage = nullptr;
    double DepositedCash = 0;

    void setConnections();
    double updateBeverage();
    void updateNumbers();
};

#endif // MAINWINDOW_H
