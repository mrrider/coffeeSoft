#pragma once
#include "nozzle.h"
#include "roll.h"

class Actions {
public:   
    Actions(Servo& servo);

    enum Action { 
        none = 0,
        nozzleGoHome = 1,
        nozzleGoMax = 2,
        nozzleGoFirstCup = 3,
        nozzleGoSecondCup = 4,
        nozzleGoThirdCup = 5,
        nozzleGoFourth = 6,
        nozzleGoFifthCup = 7
    };

    enum Action currentActions[1];

    Roll* getRoll();
    Nozzle* getNozzle();

    void buttonTrigger();
    void executeNeededAction();

private:
    Roll* roll;
    Nozzle* nozzle;
};