/**
 * The S goes pulled down with 10k ohms resistence connected to ground.
 * The S goes to A0, analog output (pulled down from the resistor).
 * 
 * The (-) goes to 5V
 * 
 * The middle is not being used.
 * 
 * Callibration:
 * 
 * Above light: 700
 * Dark room: 500
 * Lightern above: 1000
 * Finger on top: 260
 */


int photoresistorPin = 0; // analog input
int ledPin = 13; // pin number for LED
double analogValue;
double minLightValue = 700.0; // min analog value to turn on LED

void setup() {
  // sets up pin input/output
  pinMode(ledPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // reads analog input
  analogValue = analogRead(photoresistorPin);
  // if input is less than minLightValue turn on LED
  if (analogValue < minLightValue) {
    digitalWrite(ledPin, HIGH);
  } else {
     digitalWrite(ledPin, LOW); 
  }
  Serial.println(analogValue);
  
  // reads photoresistor every half second
  delay(500);
}

