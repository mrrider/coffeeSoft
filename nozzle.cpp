#include "nozzle.h"
#include "Arduino.h"
#include "globals.h"

Nozzle::Nozzle() {
    nozzleCoordinate = -1;
}

bool Nozzle::isHome(){
  return analogRead(metalPin) < 100;
}

void Nozzle::moveNozzle(bool direction){
  // Right - false
  // Left - true
  if (nozzleCoordinate == -1){
    return;
  }else if (direction && isHome()){
    nozzleCoordinate = 0;
    return;
  }
  
  if (direction) {
    digitalWrite(dirMoveMotorPin,LOW); //Enables the motor to move in a particular direction
    nozzleCoordinate -= 1;
  }
  else{
    digitalWrite(dirMoveMotorPin,HIGH);
    nozzleCoordinate += 1;
  }
   
  digitalWrite(stepMoveMotorPin, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(stepMoveMotorPin, LOW);
  delayMicroseconds(stepDelay);
}

void Nozzle::moveNozzleHome() {
  digitalWrite(enableMoveMotorPin, LOW);
  digitalWrite(dirMoveMotorPin,LOW);
  digitalWrite(stepMoveMotorPin, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(stepMoveMotorPin, LOW);
  delayMicroseconds(stepDelay);
}

void Nozzle::moveNozzleRight() {
  moveNozzle(false);
}

void Nozzle::moveNozzleLeft() {
  moveNozzle(true);
}

void Nozzle::checkCoordAndHomeIfNeeded() {
  if (nozzleCoordinate == -1 && !isHome()) {
    moveNozzleHome();
  } else if (isHome()) {
    nozzleCoordinate = 0;
    digitalWrite(enableMoveMotorPin, HIGH);
  }
}

void Nozzle::moveNozzleToCup(int coordinateToMove){
  //Check direction to move
  if(coordinateToMove != nozzleCoordinate){
    if(coordinateToMove > nozzleCoordinate){
      //move to right
      moveNozzleRight();
    }else{
      //move to left
      moveNozzleLeft();
    }
  }
}

// Returns true if the action is finished
bool Nozzle::nozzleGoHomeFunc() {
  moveNozzleLeft();
  return nozzleCoordinate == 0;
}

bool Nozzle::nozzleGoMaxFunc() {
  moveNozzleRight();
  return nozzleCoordinate == maxCoordinate;
}

bool Nozzle::nozzleGoFirstCupFunc(){
  moveNozzleToCup(firstCupCoordinate);
  return nozzleCoordinate == firstCupCoordinate;
}

bool Nozzle::nozzleGoSecondCupFunc(){
  moveNozzleToCup(secondCupCoordinate);
  return nozzleCoordinate == secondCupCoordinate;
}

bool Nozzle::nozzleGoThirdCupFunc(){
  moveNozzleToCup(thirdCupCoordinate);
  return nozzleCoordinate == thirdCupCoordinate;
}

bool Nozzle::nozzleGoFourthCupFunc(){
  moveNozzleToCup(fourthCupCoordinate);
  return nozzleCoordinate == fourthCupCoordinate;
}

bool Nozzle::nozzleGoFifthCupFunc(){
  moveNozzleToCup(fifthCupCoordinate);
  return nozzleCoordinate == fifthCupCoordinate;
}

void Nozzle::moveNozzleToCoordinate(int coordinateToMove){
  //Check direction to move
  while(coordinateToMove != nozzleCoordinate){
    if(coordinateToMove > nozzleCoordinate){
      //move to right
      moveNozzleRight();
    }else{
      //move to left
      moveNozzleLeft();
    }
  }
}