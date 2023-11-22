#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LiftState.h"
#include <LiftController.h>

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
    void on_liftStateChanged(LiftState newState);
    void on_btnGo_clicked();
    void on_btnOpenDoors_clicked();
    void on_btnCloseDoors_clicked();

    void on_rbFloorClicked();
private:
    Ui::MainWindow *ui;
    void loadButtons(int floors);
    void elevatorMoving(bool moving);
    void elevatorOpen(bool open);
    void currentFloor(int floor);

    int _selectedFloor = 1;
    LiftController* _controller;
};

#endif // MAINWINDOW_H
