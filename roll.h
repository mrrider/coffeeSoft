int rollTimes = 0;
int nozzleStepDelay = 1100;

void rollNozzleUp(){
    digitalWrite(dirRollMotorPin,LOW); 
    digitalWrite(stepRollMotorPin, HIGH);
    delayMicroseconds(nozzleStepDelay);
    digitalWrite(stepRollMotorPin, LOW);
    delayMicroseconds(nozzleStepDelay);
}

void rollNozzle(){
    digitalWrite(enableRollMotorPin, LOW);
    rollNozzleUp();
}