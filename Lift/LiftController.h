#ifndef LIFTCONTROLLER_H
#define LIFTCONTROLLER_H

#include <elevator.h>
#include <QObject>
#include <LiftState.h>

class LiftController : public QObject
{
    Q_OBJECT

public:
    LiftController(int maxFloor, int minFloor = 0) {
    _maxFloor = maxFloor;
    _minFloor = minFloor;
}
    ~LiftController();
    int getFloorsNumber();
    int getMinFloor();
    int getMaxFloor();
    void setElevator(Elevator* elevator);


    void moveTo(int floor);
    void openDoors();
    void closeDoors();
    LiftState getLiftState() const;
    bool isOpen() const;
    bool isMoving() const;
signals:
    void liftStateChanged(LiftState newState);
private slots:
    void on_liftStateChanged(LiftState newState);
private:
    int _maxFloor;
    int _minFloor;
    Elevator* _elevator;
};
#endif // LIFTCONTROLLER_H
