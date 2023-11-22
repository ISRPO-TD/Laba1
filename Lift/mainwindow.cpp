#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRadioButton"
#include "QGroupBox"
#include "LiftController.h"
#include <QDebug>
#include <QRegularExpression>
#include "floordialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FloorDialog fd;
    int result = fd.exec();
    if(result == QDialog::Accepted){
        loadButtons(fd.getFloorNumber());
    }
    else{
        QApplication::instance()->exit(0);QCoreApplication::exit(0);
    }
    _controller = new LiftController(fd.getFloorNumber());
    _controller->setElevator(new Elevator(_controller));
    connect(_controller, SIGNAL(liftStateChanged(LiftState)), this, SLOT(on_liftStateChanged(LiftState)));
    on_liftStateChanged(_controller->getLiftState());
}

MainWindow::~MainWindow()
{
    delete _controller;
    delete ui;
}

void MainWindow::loadButtons(int floors){
    int buttonHeight = QRadioButton(QString("Этаж"), ui->groupBox).height()
            ;
    for(int i = 1; i <= floors; i++){
        QRadioButton* rb = new QRadioButton(QString("Этаж %1").arg(i), ui->groupBox);
        rb->setObjectName(QString("rb%1").arg(i));
        connect(rb, SIGNAL(clicked()), this, SLOT(on_rbFloorClicked()));
        if(i % 2 == 0){
            ui->vlButtonsRight_2->addWidget(rb);
        }
        else{
            ui->vlButtonsLeft->addWidget(rb);
        }
    }

    if(floors % 2 != 0){
        QWidget *fillerWidget = new QWidget(ui->groupBox);
        fillerWidget->setFixedSize(0, buttonHeight);
        ui->vlButtonsRight_2->addWidget(fillerWidget);
    }
}

void MainWindow::on_liftStateChanged(LiftState newState){
    currentFloor(newState.currentFloor());
    elevatorMoving(newState.isMoving());
    elevatorOpen(newState.isOpen());
}

void MainWindow::currentFloor(int floor){
    ui->lCurrentFloor->setText("Текущий этаж: " + QString::number(floor));
}

void MainWindow::elevatorMoving(bool isMoving){
    if(isMoving){
        ui->lMoving->setStyleSheet("color: red;");
        ui->lMoving->setText("Лифт в движении");
    } else{
        ui->lMoving->setStyleSheet("color: green;");
        ui->lMoving->setText("Лифт стоит");
    }
}

void MainWindow::elevatorOpen(bool isOpen){
    if(isOpen){
        ui->lDoorsOpen->setStyleSheet("color: green;");
        ui->lDoorsOpen->setText("Двери открыты");
    } else{
        ui->lDoorsOpen->setStyleSheet("color: red;");
        ui->lDoorsOpen->setText("Двери закрыты");
    }
}

void MainWindow::on_btnGo_clicked()
{
    qDebug() << "Передан сигнал к движению контроллеру";
    _controller->moveTo(_selectedFloor);
}

void MainWindow::on_btnOpenDoors_clicked()
{
    _controller->openDoors();
}

void MainWindow::on_btnCloseDoors_clicked()
{
    _controller->closeDoors();
}

void MainWindow::on_rbFloorClicked(){
    QRadioButton* senderRB = qobject_cast<QRadioButton*>(sender());
    if(senderRB){
        QString rbName = senderRB->objectName();
        QRegularExpression regExp("[a-zA-Z]");
        rbName.remove(regExp);

        _selectedFloor = rbName.toInt();
    }
}
