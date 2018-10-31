#pragma once

// Defines pins numbers
// Nozzle motor pins
const int enableMoveMotorPin = 3;
const int stepMoveMotorPin = 7;
const int dirMoveMotorPin = 8; 

//Servo motor pins
const int servoPin = 9;

// Buttons pins
const int firstCupButtonPin = 2;
const int secondCupButtonPin = 4;
const int thirdCupButtonPin = 6;
const int fourthCupButtonPin = 12;
const int fifthCupButtonPin = 10;

// Metal detector pins
const int metalPin = 1;

const int stepDelay  = 1100;

// coordinates for cups
const int firstCupCoordinate = 600;
const int secondCupCoordinate = 1200;
const int thirdCupCoordinate = 1800;
const int fourthCupCoordinate = 2400;
const int fifthCupCoordinate = 3000;
const int maxCoordinate = 3600;