/**
   Basic Program to decode the driving signal of a DC Motor
   Particularly,
    DC Motor http://store.makeblock.com/optical-encoder-motor-25-6v-185rpm/

    Motor pins
     M+ M- GND VCC A B

     M+, M- Motor Power bidirectional
     GND, VCC .  Encoder power, 5V

     A - Digital Pin 2
     B - Digital Pin 4

     If you switch the motor direction
     you need to change the sign of the encoder counter on the
     Decoder function that is being callled at each interrupt.
*/


#define encoder0PinA  3
#define encoder0PinB  5

volatile long encoder0Pos = 0;
long newposition;
long oldposition = 0;
unsigned long newtime;
unsigned long oldtime = 0;
long vel;

void setup()
{
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder, RISING);  // encoDER ON PIN 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
}

void loop()
{
  newposition = encoder0Pos;
  newtime = millis();
  vel = (newposition - oldposition) * 1000 / (newtime - oldtime);
  Serial.print ("speed = ");
  Serial.println (vel);
  oldposition = newposition;
  oldtime = newtime;
  delay(250);
}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}
