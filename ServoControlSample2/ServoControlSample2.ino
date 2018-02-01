#include <Servo.h>

class ControlledServo {
public:
  Servo servo;
  int pos;
  int tgtPos;
  int direction = 1;
  int minPos=0;
  int maxPos=180;

  void loop() {
      // Update desired position.
      if (pos<tgtPos)
        direction = 1;
      else
        direction =-1;  
  }

  void update() {

    loop();
    if (tgtPos != pos)
    {
      //Serial.print(pos);Serial.print("--");
      //Serial.println(desiredpos);
      servo.write(pos);
    
      pos+=direction;
      
      if (pos>=minPos)
      {
        //Serial.print("Reset down:");
        //Serial.println(counter++);
        direction=-1;
      }
    
      if (pos<=maxPos)
      {
        //Serial.print("Reset up:");
        //Serial.println(counter++);
        direction=1;    
      }
    }

  } 
};

ControlledServo tilt;
ControlledServo pan;

void setup() {
  tilt.servo.attach(9);
  pan.servo.attach(10);

  tilt.pos=100;
  tilt.tgtPos=100;
  
  pan.pos=100;
  pan.tgtPos=100;
}

int i=90;

int direction=1;

void loop() {
  //tilt.update();
  //pan.update();

  if (i==180)
    direction=-1;

  if (i==90)
    direction=1;

  i+=(direction);

  tilt.tgtPos = i-90;
  pan.tgtPos=i;
  pan.update();
  tilt.update();


  
  delay(10);
}


