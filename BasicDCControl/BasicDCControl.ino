/**
 * Basic DC output control.
 * 
 * Just output Pin 8 digital to high for 500 ticks and then
 * put it back to low.
 * 
 * If you connect a LED or something into pin 8, you should see
 * it blinking.
 * 
 */



void setup() {
  // put your setup code here, to run once:
    pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<500;i++)
  {
    digitalWrite(8,HIGH);
  }
  
  delay(500);

  
  digitalWrite(8,LOW);

  delay(500);
}
