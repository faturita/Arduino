/**
 * Basic Arduino Servo controller
 * 
 * Pin 0 Analog output to control servo.
 * 
 * The other two cables goes to VCC and GND.
 */


#include <Servo.h>

Servo servo1; 

int v;

void setup() {

  pinMode(0,OUTPUT);
  servo1.attach(14); //analog pin 0
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  Serial.begin(19200);
  Serial.println("Ready");

  v=0;
  
}


void loop() {

  if (v>=190)
    {
    Serial.println("Reset");
    v=0;
    servo1.write(v);
    delay(1000);
    }
    else
    {
    v++;
    servo1.write(v);
    }
  
  delay(10);
    
} 

