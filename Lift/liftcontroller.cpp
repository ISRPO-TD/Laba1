#include "LiftController.h"
#include "LiftState.h"
#include <QDebug>

LiftController::~LiftController(){
    if (_elevator != nullptr)
    {
        delete _elevator;
    }
}

int LiftController::getMaxFloor()
{
    return _maxFloor;
}
int LiftController::getMinFloor()
{
    return _minFloor;
}

void LiftController::setElevator(Elevator* elevator)
{
    _elevator = elevator;
    connect(_elevator, SIGNAL(liftStateChanged(LiftState)), this, SLOT(on_liftStateChanged(LiftState)));
}

void LiftController::moveTo(int floor)
{
    qDebug() << "Передан сигнал к движению лифту";
    _elevator->startMove(floor);
}

void LiftController::openDoors(){
    _elevator->openDoors();
}

void LiftController::closeDoors(){
    _elevator->closeDoors();
}

LiftState LiftController::getLiftState() const{
    return _elevator->getState();
}

bool LiftController::isMoving() const{
    return _elevator->isMoving();
}

bool LiftController::isOpen() const{
    return _elevator->isOpen();
}

void LiftController::on_liftStateChanged(LiftState newState)
{
    emit liftStateChanged(newState);
}
