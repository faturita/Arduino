
#include <AFMotor.h>

AF_DCMotor motor(3, MOTOR12_64KHZ);



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  motor.setSpeed(200);
  motor.run(FORWARD);

}
