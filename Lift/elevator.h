#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <QObject>
#include <QTimer>
#include "LiftState.h"

class Elevator : public QObject
{
Q_OBJECT

public:
    Elevator(QObject* parent = nullptr, int currentFloor = 0) : QObject(parent) {
        _isMoving = false;
        _isOpen = false;
        _currentFloor = currentFloor;
        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &Elevator::moveToNextFloor);
    }
    void startMove(int floor);
    void openDoors();
    void closeDoors();

    bool isMoving() const;
    bool isOpen() const;

    LiftState getState() const;
signals:
    void liftStateChanged(LiftState newState);
private slots:
    void moveToNextFloor();
private:
    void targetReached();

    const int ONE_FLOOR_TIME = 1000;
    int _currentFloor;
    int _targetFloor;
    bool _isMoving;
    bool _isOpen;
    QTimer* timer;
};

#endif // ELEVATOR_H
