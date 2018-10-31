#include "roll.h"
#include "Arduino.h"
#include "globals.h"

Roll::Roll(Servo& servo){
    this->servo = servo;
}

void Roll::moveServoSlowly(int newMicroseconds) {
    int addition = 50;
    if (newMicroseconds > currentMicroseconds) {
        for (int i = currentMicroseconds; i <= newMicroseconds; i++) {
            servo.writeMicroseconds(i);
            currentMicroseconds = i;
            delay(2);
        }
    } else {
        for (int i = currentMicroseconds; i >= newMicroseconds; i--) {
            servo.writeMicroseconds(i);
            currentMicroseconds = i;
            delay(2);
        }
    }
}

