/**
 * Testeo de motores de DC.
 * 
 */

#define trigPin 13
#define echoPin 12

// DELETEME 

int IN4 = 5;
int IN3 = 4; 
int IN2 = 3; 
int IN1 = 2;

// constants won't change. Used here to set a pin number :
const int ledPin =  13;      // the number of the LED pin


int const QUIET = 0;
int const STILL = 1;
int const MOVE_FORWARD = 2;
int const MOVE_BACKWARDS = 3;
int const RIGHT = 4;
int const LEFT = 5;

int motorstate=STILL;

void setup() {
  Serial.begin (115200);
  Serial.println("Sensorimotor Cortex");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN2, OUTPUT);    // Input4 conectada al pin 3 
  pinMode (IN1, OUTPUT);    // Input3 conectada al pin 2

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);  

  randomSeed(analogRead(0));
}

int counter=0;

void loop() {
   if (Serial.available() > 0) {
      int incomingByte;
      incomingByte = Serial.read();

      if (48<incomingByte && incomingByte<58)
      {
        motorstate = incomingByte-48;
        counter = 0;
      }
   } 

   counter++;
   if (counter>1000)
   {
     counter=0;
     motorstate=STILL;
   }
     
  //if (ledState == HIGH)
  switch (motorstate)
  {
    case MOVE_BACKWARDS: 
      // Move Backward.
      //Serial.println("Moving!");
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW); 
      digitalWrite (IN2, HIGH);
      digitalWrite (IN1, LOW); 
      break;
    case MOVE_FORWARD: 
      // Go ahead and move forward
      //Serial.println("Moving!");
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH); 
      digitalWrite (IN2, LOW);
      digitalWrite (IN1, HIGH); 
      break;
    case LEFT: 
      // Move the right caterpiller
      //Serial.println("Moving!");
      digitalWrite (IN4, HIGH); // LOW
      digitalWrite (IN3, LOW); 
      digitalWrite (IN2, LOW);
      digitalWrite (IN1, HIGH); 
      break;
    case RIGHT: 
      // Move the left Caterpiller
      //Serial.println("Moving!");
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH); 
      digitalWrite (IN2, HIGH);  // LOW
      digitalWrite (IN1, LOW); 
      break;
    default:
      // Stop All Motors
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, LOW); 
      digitalWrite (IN2, LOW);
      digitalWrite (IN1, LOW); 
      break;
  }

  delay(10);

}
