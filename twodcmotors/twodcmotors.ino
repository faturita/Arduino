/* 
 Ejemplo de control de motor DC usando modulo L298
 http://electronilab.co/tienda/driver-dual-para-motores-full-bridge-l298n/
 
 El programa activa el motor en un sentido por 4 segundos, 
 para el motor por 500 ms, activa el motor en sentido inverso por 4 segundos 
 y se detiene por 5 segundos. Luego repite la acción indefinidamente.
 
 Creado 16/05/14
 por Andres Cruz
 ELECTRONILAB.CO
 */

// constants won't change. Used here to set a pin number :
const int ledPin =  13;      // the number of the LED pin

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 800;           // interval at which to blink (milliseconds)

int IN4 = 5;
int IN3 = 4; 
int IN2 = 3; 
int IN1 = 2;

void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN2, OUTPUT);    // Input4 conectada al pin 3 
  pinMode (IN1, OUTPUT);    // Input3 conectada al pin 2

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);  
}

void blinkme()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}


int motorstate=0;

void loop()
{
  blinkme();

  if (ledState == HIGH)
  switch (motorstate)
  {
    case 0: 
      // Motor gira en un sentido
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW); 
      digitalWrite (IN2, HIGH);
      digitalWrite (IN1, LOW); 
      motorstate++;
      break;
    default:
      // Motor no gira
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, LOW); 
      digitalWrite (IN2, LOW);
      digitalWrite (IN1, LOW); 
    motorstate=0;break;
  }

  delay(10);
}
