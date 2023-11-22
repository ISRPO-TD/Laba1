#ifndef LIFSTATE_H
#define LIFSTATE_H


class LiftState
{
public:
    LiftState(int currentFloor, int isMoving, int isOpen){
        _currentFloor = currentFloor;
        _isMoving = isMoving;
        _isOpen = isOpen;
    }

    int currentFloor() const;
    bool isMoving() const;
    bool isOpen() const;

private:
    int _currentFloor;
    bool _isMoving;
    bool _isOpen;
};

#endif // LIFSTATE_H
