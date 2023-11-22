#include "elevator.h"
#include <QDebug>
#include <math.h>

void Elevator::startMove(int floor){
    if(!_isMoving){
        if(_isOpen)
            closeDoors();
        _targetFloor = floor;
        _isMoving = true;

        timer->start(ONE_FLOOR_TIME);
        qDebug() << "Лифт запущен";
    }
}

void Elevator::closeDoors(){
    _isOpen = false;
    emit liftStateChanged(getState());
}

void Elevator::openDoors(){
    if(!_isMoving){
        _isOpen = true;
        emit liftStateChanged(getState());
    }
}

void Elevator::targetReached(){
    qDebug() << "Лифт на месте";
    _isMoving = false;
    openDoors();
    emit liftStateChanged(getState());
}

LiftState Elevator::getState() const{
    return LiftState(_currentFloor, _isMoving, _isOpen);
}

bool Elevator::isMoving() const{
    return _isMoving;
}

bool Elevator::isOpen() const{
    return _isOpen;
}

void Elevator::moveToNextFloor(){
    if (_targetFloor != _currentFloor){
        if(_targetFloor < _currentFloor){
            _currentFloor--;
        }
        else{
            _currentFloor++;
        }
        qDebug() << "Лифт достиг этажа" + QString::number(_currentFloor);
        emit liftStateChanged(getState());
    }
    else{
        timer->stop();
        targetReached();
    }
}
