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

#define encoder0PinA  2
#define encoder0PinB  4

#define encoder1PinA  3
#define encoder1PinB  5

volatile long encoder0Pos = 0;
long newposition;
long oldposition = 0;
unsigned long newtime;
unsigned long oldtime = 0;
long vel;

volatile long encoder1Pos = 0;
long newposition1;
long oldposition1 = 0;
unsigned long newtime1;
unsigned long oldtime1 = 0;
long vel1;

void setup()
{
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder, RISING);  // encoDER ON PIN 2
  
  pinMode(encoder1PinA, INPUT);
  digitalWrite(encoder1PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder1PinB, INPUT);
  digitalWrite(encoder1PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(1, doEncoder1, RISING);  // encoDER ON PIN 2
   
  
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
}

void loop0()
{
  newposition = encoder0Pos;
  newtime = millis();
  int sign=1;
  if ((newposition - oldposition) < 0)
    sign = -1;
  vel = sign * (newposition - oldposition) * 1000 / (newtime - oldtime);
  Serial.print ("speed = ");
  Serial.println (vel);
  oldposition = newposition;
  oldtime = newtime;
}


void loop1()
{
  newposition1 = encoder1Pos;
  newtime1 = millis();
  int sign=1;
  if ((newposition1 - oldposition1) < 0)
    sign = -1;
  vel1 = sign * (newposition1 - oldposition1) * 1000 / (newtime1 - oldtime1);
  Serial.print ("speed = ");
  Serial.println (vel1);
  oldposition1 = newposition1;
  oldtime1 = newtime1;
}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos--;
  } else {
    encoder0Pos++;
  }
}

void doEncoder1()
{
  if (digitalRead(encoder1PinA) == digitalRead(encoder1PinB)) {
    encoder1Pos--;
  } else {
    encoder1Pos++;
  }
}

void loop()
{
  loop1();
  loop0();
  delay(250);
}

