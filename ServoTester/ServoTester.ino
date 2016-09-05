/**
 * Adafruit Servo Shield V1 tester.
 * 
 */

#include <AFMotor.h>
#include <Servo.h> 

Servo elbow;

AF_DCMotor shoulder(2, MOTOR12_64KHZ);

int pos = 0;    // variable to store the servo position 

void setup() {
  Serial.begin(115200); // set up Serial library at 9600 bps
  Serial.println("Motor Unit Neuron");

  elbow.attach(9);
  pos=120;
}
int direction=1;
int counter=0;


void loop() {

  elbow.write(pos);

  pos+=direction;
  
  if (pos>=185)
  {
    Serial.print("Reset down:");
    Serial.println(counter++);
    direction=-1;
  }

  if (pos<=48)
  {
    Serial.print("Reset up:");
    Serial.println(counter++);
    direction=1;    
  }

  if (counter < -10)
  {
    shoulder.setSpeed(250);
    shoulder.run(FORWARD);
  }

  if (counter==10000)
  {
    elbow.detach();
  }
 
 
  delay(10);
} 


void lodop() {

  elbow.write(pos);

  pos+=direction;
  
  if (pos>=90)
  {
    Serial.print("Reset down:");
    Serial.println(counter++);
    direction=-1;
  }

  if (pos<=70)
  {
    Serial.print("Reset up:");
    Serial.println(counter++);
    direction=1;    
  }

  if (counter < 1000)
  {
    shoulder.setSpeed(250);
    shoulder.run(FORWARD);
  }

  if (counter==10000)
  {
    elbow.detach();
  }
 
  

  delay(90);
} 


