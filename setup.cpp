#include "setup.h"
#include "Arduino.h"
#include "globals.h"

Servo Setup::setupServo() {
    servo.attach(servoPin,600,2300);
    servo.writeMicroseconds(1200);
    return servo;
}

void Setup::addPins() {
    //init all pins
    pinMode(stepMoveMotorPin,OUTPUT);
    pinMode(dirMoveMotorPin,OUTPUT);
    pinMode(enableMoveMotorPin,OUTPUT);

    pinMode(servoPin,OUTPUT);

    pinMode(firstCupButtonPin, INPUT);
    pinMode(secondCupButtonPin, INPUT);
    pinMode(thirdCupButtonPin, INPUT);
    pinMode(fourthCupButtonPin, INPUT);
    pinMode(fifthCupButtonPin, INPUT);

    pinMode(metalPin, INPUT);
    
    digitalWrite(firstCupButtonPin, HIGH);
    digitalWrite(secondCupButtonPin, HIGH);
    digitalWrite(thirdCupButtonPin, HIGH);
    digitalWrite(fourthCupButtonPin, HIGH);
    digitalWrite(fifthCupButtonPin, HIGH);
}