#include <Servo.h>
//ServoTimer 

Servo servo1;
Servo servo2; 

void setup() {
 Serial.begin(9600); //  set up Serial library at 9600 bps
 Serial.println("Servo test!");
 servo1.attach(10);
 servo2.attach(9);
}
void loop() {
 Serial.print("tick");
 servo1.write(180);
 servo2.write(0);
 delay(1000);
 Serial.print("tock");
 servo1.write(0);
 servo2.write(180);
 delay(1000);
} 
