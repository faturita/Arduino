/**
 * The connection for the keys sound sensor
 * 
 * + - VCC
 * A0 - A0
 * G - GND
 */


int sensorPin = A2; // select the input pin for the analog signal
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
 
void setup () 
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (sensorPin);
  
  //delay (sensorValue);
  digitalWrite (ledPin, LOW);
  //delay (sensorValue);
  if (sensorValue>40) {
    digitalWrite (ledPin, HIGH); }
    Serial.println (sensorValue, DEC);
  
  
}
