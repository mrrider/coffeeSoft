#pragma once

class Nozzle {
public:  
    Nozzle();
    int nozzleCoordinate;

    bool isHome();
    void moveNozzle(bool direction);
    void setupServo();
    void moveServoSlowly(int newMicroseconds);
    void moveNozzleHome();
    void moveNozzleRight();
    void moveNozzleLeft();
    void checkCoordAndHomeIfNeeded();
    void moveNozzleToCup(int coordinateToMove);
    bool nozzleGoHomeFunc();
    bool nozzleGoMaxFunc();
    bool nozzleGoFirstCupFunc();
    bool nozzleGoSecondCupFunc();
    bool nozzleGoThirdCupFunc();
    bool nozzleGoFourthCupFunc();
    bool nozzleGoFifthCupFunc();
    void moveNozzleToCoordinate(int coordinateToMove);
};