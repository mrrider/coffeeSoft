// Defines pins numbers
const int enableMoveMotorPin = 3;
const int stepMoveMotorPin = 7;
const int dirMoveMotorPin = 8; 

const int enableRollMotorPin = 5;
const int stepRollMotorPin = 10;
const int dirRollMotorPin = 11; 
// const int stepSizeRollMotorPin = 9; 

const int servoPin = 9;

const int secondCupButtonPin = 4;
const int thirdCupButtonPin = 6;
const int fourthCupButtonPin = 12;

const int metalPin = 1;

void addPins() {
  // pinMode(stepMoveMotorPin,OUTPUT);
  // pinMode(dirMoveMotorPin,OUTPUT);
  // pinMode(enableMoveMotorPin,OUTPUT);
  // pinMode(stepSizeRollMotorPin,OUTPUT);

  pinMode(servoPin,OUTPUT);

  // pinMode(stepRollMotorPin,OUTPUT);
  // pinMode(dirRollMotorPin,OUTPUT);
  // pinMode(enableRollMotorPin,OUTPUT);

  // pinMode(secondCupButtonPin, INPUT);
  // pinMode(thirdCupButtonPin, INPUT);
  // pinMode(fourthCupButtonPin, INPUT);

  // pinMode(metalPin, INPUT);
  
  // // digitalWrite(stepSizeRollMotorPin, HIGH);

  // digitalWrite(secondCupButtonPin, HIGH);
  // digitalWrite(thirdCupButtonPin, HIGH);
  // digitalWrite(fourthCupButtonPin, HIGH);
}
