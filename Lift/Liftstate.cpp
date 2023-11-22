#include "LiftState.h"

int LiftState::currentFloor() const{
    return _currentFloor;
}

bool LiftState::isMoving() const{
    return  _isMoving;
}

bool LiftState::isOpen() const{
    return _isOpen;
}
