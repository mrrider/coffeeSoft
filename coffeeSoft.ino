#include "Arduino.h"
#include "setup.h"
#include "actions.h"

Actions* actions;
Setup* stp = new Setup();
Servo servo;

void setup() {
  stp->addPins();
  servo = stp->setupServo();
  actions = new Actions(servo);
}

void loop() {
  actions->getNozzle()->checkCoordAndHomeIfNeeded();
  actions->buttonTrigger();
  actions->executeNeededAction();
}
