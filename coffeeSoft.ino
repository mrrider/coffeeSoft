// #include "setup.h"
// // #include "nozzle.h"
// // #include "roll.h"
// // #include "actions.h"

// void setup() {
//   addPins();
// }

// void loop() {
//   // rollNozzle();
//    digitalWrite(servoPin, LOW);
//     delayMicroseconds(1450); // Duration of the pusle in microseconds
//     digitalWrite(servoPin, HIGH);
//     delayMicroseconds(18550);
//   // checkCoordAndHomeIfNeeded();
//   // buttonTrigger();
//   // executeNeededAction();
// }

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
void setup() {
  myservo.attach(9,600,2300);  // (pin, min, max)
}
void loop() {
  myservo.write(0);  // tell servo to go to a particular angle

  delay(1000);

  myservo.write(60);

  delay(1000);

  myservo.write(-60);

  delay(1000);
                   
}
