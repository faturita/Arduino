#include <AFMotor.h>
#include <Servo.h> 


// create motor objects, 64KHz pwm
//AF_DCMotor laser(1, MOTOR12_64KHZ);
//AF_DCMotor turret(4, MOTOR12_64KHZ);
//AF_DCMotor grip(3, MOTOR12_64KHZ);
AF_DCMotor shoulder(2, MOTOR12_64KHZ);

void setup() {
 Serial.begin(115200); // set up Serial library at 9600 bps
 Serial.println("Motor Unit Neuron");

}

int incomingByte = 0;

char buffer[4];
int state;
int speeds;
int stopcounter=0;
int last;

void loop()
{
 if (Serial.available() > 0) {
   
    char syncbyte = Serial.read();

    if (syncbyte == 'A')
    {   
   
      int readbytes = Serial.readBytes(buffer, 4);
      
      if (readbytes == 4) {
        int action = buffer[0]-48;
        int a = buffer[1]-48;
        int b = buffer[2]-48;
        int c = buffer[3]-48;

        last = atoi(buffer+1);
        state = action;
        speeds = 1;

        Serial.print("Last:");Serial.println(last);
        Serial.println(speeds);
      }
    }

 }

 if (state == 3)
 {
  shoulder.run(FORWARD);
 } else if (state== 4)
 {
  shoulder.run(BACKWARD);
 }

 if (speeds>0)
 {
  shoulder.setSpeed(speeds);
  speeds+=1;
  Serial.print("Speed:");Serial.println(speeds);

  if (speeds>=255) {
    speeds = 255;
    stopcounter++;
    if (stopcounter>last)
    {
      shoulder.setSpeed(0);
      speeds=0;
      stopcounter=0;
    }
  }
 }
 
 delay(10);
}

