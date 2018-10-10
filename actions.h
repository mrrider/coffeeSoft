enum Action { 
  none = 0,
  nozzleGoHome = 1,
  nozzleGoMax = 2,
  nozzleGoFirstCup = 3,
  nozzleGoSecondCup = 4,
  nozzleGoThirdCup = 5,
  nozzleGoFourth = 6,
  nozzleGoFifth = 7
};

enum Action currentActions[1];

void buttonTrigger(){
    if (digitalRead(secondCupButtonPin)==LOW){
    currentActions[0] = nozzleGoSecondCup;
    }
    if (digitalRead(thirdCupButtonPin)==LOW){
      currentActions[0] = nozzleGoThirdCup;
    }
    if (digitalRead(fourthCupButtonPin)==LOW){
      currentActions[0] = nozzleGoFourth;
    }
}

void executeNeededAction() {
  enum Action current = currentActions[0];

  if (current != none) {
    digitalWrite(enableMoveMotorPin, LOW);
  }

  bool actionCompleted = false;
  
  switch (current) {
    case nozzleGoHome:
      actionCompleted = nozzleGoHomeFunc();
      break;
    case nozzleGoMax:
      actionCompleted = nozzleGoMaxFunc();
      break;
    case nozzleGoFirstCup:
      actionCompleted = nozzleGoFirstCupFunc();
      break;
    case nozzleGoSecondCup:
      actionCompleted = nozzleGoSecondCupFunc();
      break;    
    case nozzleGoThirdCup:
      actionCompleted = nozzleGoThirdCupFunc();
      break;
    case nozzleGoFourth:
      actionCompleted = nozzleGoFourthCupFunc();
      break;
    case nozzleGoFifth:
      actionCompleted = nozzleGoFifthCupFunc();
      break;
    default:
      break;
  }

  if (actionCompleted) {
    currentActions[0] = none;
    digitalWrite(enableMoveMotorPin, HIGH);
  }
}
