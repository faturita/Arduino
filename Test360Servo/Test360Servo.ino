#include <Servo.h>

Servo servo1; Servo servo2; 

int pos = 0;    // variable to store the servo position


void setup() {

  //pinMode(1,OUTPUT);
  servo1.attach(9); //analog pin 0
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  //servo2.attach(15); //analog pin 1
  Serial.begin(9600);
  Serial.println("Ready");

}

int n = 1500;

void loop() {
//  servo1.write(0);

  servo1.writeMicroseconds(n);

  n += 10;

  if (n>=2000) n =2000;
  delay(15);
  /**
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }**/
  

}
