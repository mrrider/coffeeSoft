int nozzleCoordinate = -1;
const int stepDelay  = 1100;

const int firstCupCoordinate = 600;
const int secondCupCoordinate = 1200;
const int thirdCupCoordinate = 1800;
const int fourthCupCoordinate = 2400;
const int fifthCupCoordinate = 3000;
const int maxCoordinate = 3600;

boolean isHome(){
  return analogRead(metalPin) < 100;
}

void moveNozzle(boolean direction){
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

void moveNozzleHome() {
  digitalWrite(enableMoveMotorPin, LOW);
  digitalWrite(dirMoveMotorPin,LOW);
  digitalWrite(stepMoveMotorPin, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(stepMoveMotorPin, LOW);
  delayMicroseconds(stepDelay);
}

void moveNozzleRight() {
  moveNozzle(false);
}

void moveNozzleLeft() {
  moveNozzle(true);
}

void checkCoordAndHomeIfNeeded() {
  if (nozzleCoordinate == -1 && !isHome()) {
    moveNozzleHome();
  } else if (isHome()) {
    nozzleCoordinate = 0;
    digitalWrite(enableMoveMotorPin, HIGH);
  }
}

void moveNozzleToCup(int coordinateToMove){
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
boolean nozzleGoHomeFunc() {
  moveNozzleLeft();
  return nozzleCoordinate == 0;
}

boolean nozzleGoMaxFunc() {
  moveNozzleRight();
  return nozzleCoordinate == maxCoordinate;
}

boolean nozzleGoFirstCupFunc(){
  return true;
}

boolean nozzleGoSecondCupFunc(){
  moveNozzleToCup(secondCupCoordinate);
  return nozzleCoordinate == secondCupCoordinate;
}

boolean nozzleGoThirdCupFunc(){
  moveNozzleToCup(thirdCupCoordinate);
  return nozzleCoordinate == thirdCupCoordinate;
}

boolean nozzleGoFourthCupFunc(){
  moveNozzleToCup(fourthCupCoordinate);
  return nozzleCoordinate == fourthCupCoordinate;
}

boolean nozzleGoFifthCupFunc(){
  return true;
}
