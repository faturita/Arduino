
#include <AFMotor.h>

bool debug = true;

// create motor objects, 64KHz pwm
//AF_DCMotor laser(1, MOTOR12_64KHZ);
//AF_DCMotor turret(4, MOTOR12_64KHZ);
AF_DCMotor elbow(1, MOTOR12_64KHZ);



int state=0;

int speeds = 0;


void setup() {
 Serial.begin(9600); // set up Serial library at 9600 bps
 Serial.println("Testing");
}

int incomingByte = 0;

char buffer[4];

void loop() {
 if (Serial.available() > 0) {
   
    char syncbyte = Serial.read();

    if (syncbyte == 'I')
    {
      Serial.println("MTRN");
    }

    if (syncbyte == 'D')
    {
      debug = (!debug);
    }

    if (syncbyte == 'A')
    {   
      // Format A1000 >> A1220
      // Format A5000
      int readbytes = Serial.readBytes(buffer, 4);
      
      if (readbytes == 4) {
        int action = buffer[0]-48;
        int a = buffer[1]-48;
        int b = buffer[2]-48;
        int c = buffer[3]-48;

        speeds = atoi(buffer+1);
        state = action;

        if (debug) {
          Serial.print("Action:");
          Serial.print(action);
          Serial.print("/");
          Serial.println(speeds);
        }
      }
    }
 }

 if (state == 1) {
   elbow.setSpeed(speeds); 
   elbow.run(FORWARD);
   speeds ++; if (speeds >=255) speeds=255;
   Serial.println(speeds);
 }

 if (state == 3) {
   elbow.setSpeed(speeds); 
   elbow.run(BACKWARD);
   speeds ++; if (speeds >=255) speeds=255;
   Serial.println(speeds);  
 }

 if (state == 4) {
   elbow.setSpeed(speeds); 
   if (speeds >=255) speeds=255;
   Serial.println(speeds);   
 }

 if (state == 5) {
  elbow.run(FORWARD);
  elbow.setSpeed(0);
  delay(50);
  elbow.setSpeed(255);
  delay(150);
  elbow.setSpeed(255);
 }

 if (state == 6) {
  elbow.run(BACKWARD);
  elbow.setSpeed(150);
  delay(10);
  elbow.setSpeed(255);
  delay(150);
  elbow.setSpeed(255);
 } 

 if (state == 2) {
   elbow.run(RELEASE);
 }

 delay(0);

} 
