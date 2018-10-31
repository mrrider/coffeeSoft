#include "actions.h"
#include "Arduino.h"
#include "globals.h"
#include "spiral.h"

Actions::Actions(Servo& servo){
    roll = new Roll(servo);
    nozzle = new Nozzle();
}

Roll* Actions::getRoll(){
    return roll;
}

Nozzle* Actions::getNozzle(){
    return nozzle;
}


void Actions::buttonTrigger(){
    if (digitalRead(firstCupButtonPin)==LOW){
      currentActions[0] = nozzleGoFirstCup;
    }
    if (digitalRead(secondCupButtonPin)==LOW){
      currentActions[0] = nozzleGoSecondCup;
    }
    if (digitalRead(thirdCupButtonPin)==LOW){
      currentActions[0] = nozzleGoThirdCup;
    }
    if (digitalRead(fourthCupButtonPin)==LOW){
      currentActions[0] = nozzleGoFourth;
    }
    if (digitalRead(fifthCupButtonPin)==LOW){
      currentActions[0] = nozzleGoFifthCup;
    }
}

void Actions::executeNeededAction() {
  enum Action current = currentActions[0];

  if (current != none) {
    digitalWrite(enableMoveMotorPin, LOW);
  }

  bool actionCompleted = false;
  
  switch (current) {
    case nozzleGoHome:
      actionCompleted = nozzle->nozzleGoHomeFunc();
      break;
    case nozzleGoMax:
      actionCompleted = nozzle->nozzleGoMaxFunc();
      break;
    case nozzleGoFirstCup:
      actionCompleted = nozzle->nozzleGoFirstCupFunc();
      break;
    case nozzleGoSecondCup:
      actionCompleted = nozzle->nozzleGoSecondCupFunc();
      break;    
    case nozzleGoThirdCup:
      actionCompleted = nozzle->nozzleGoThirdCupFunc();
      break;
    case nozzleGoFourth:
      actionCompleted = nozzle->nozzleGoFourthCupFunc();
      break;
    case nozzleGoFifthCup:
      actionCompleted = nozzle->nozzleGoFifthCupFunc();
      break;
    default:
      break;
  }

  if (actionCompleted) {
    currentActions[0] = none;

    int zeroY = 900;
    int distanceY = 600;
    int distanceX = 550;

    if (current == nozzleGoSecondCup) {
      for (int i = 0; i < (sizeof(spiral)/sizeof(*spiral)); i++) {
        float x = spiral[i][0] * distanceX + 600;
        float y = spiral[i][1] * distanceY + 900;
        nozzle->moveNozzleToCoordinate(x);
        // delay(50);
        roll->moveServoSlowly(y);
        // delay(10);
      }
    }

    digitalWrite(enableMoveMotorPin, HIGH);
  }


}
