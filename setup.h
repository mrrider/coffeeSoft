#pragma once
#include "Servo.h"

class Setup {
public:   
    void addPins();
    Servo setupServo();

    Servo servo;
};