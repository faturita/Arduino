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
  //tilt.servo.attach(10);
  pan.servo.attach(9);
  
  //tilt.pos = 90;
  //pan.pos = 200;
  //tilt.tgtPos = 180;
  //pan.tgtPos = 220;
  //tilt.minPos=90;
  //tilt.maxPos=180;
}

void loop() {
  //tilt.update();
  //pan.update();
  pan.servo.write(120);

  delay(1);
}


