#pragma once
#include "Servo.h"

class Roll {
    public:   
        Roll(Servo& servo);
        int currentMicroseconds = 1200;
        void moveServoSlowly(int newMicroseconds);
        Servo servo;
};