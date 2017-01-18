/******************************************************************************
PIR_Motion_Detector_Example.ino
Example sketch for SparkFun's PIR Motion Detector
  (https://www.sparkfun.com/products/13285)
Jim Lindblom @ SparkFun Electronics
May 2, 2016

The PIR motion sensor has a three-pin JST connector terminating it. Connect
the wire colors like this:
- Black: D2 - signal output (pulled up internally)
- White: GND
- Red: 5V

Connect an LED to pin 13 (if your Arduino doesn't already have an LED there).

Whenever the PIR sensor detects movement, it'll write the alarm pin LOW.

Development environment specifics:
Arduino 1.6.7
******************************************************************************/
const int MOTION_PIN = 2; // Pin connected to motion detector
const int LED_PIN = 13; // LED pin - active-high


int sensorPin = A0; // select the input pin for the analog signal
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor

 
void setup() 
{
  Serial.begin(9600);
  // The PIR sensor's output signal is an open-collector, 
  // so a pull-up resistor is required:
  pinMode(MOTION_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}


void loop() 
{
  sensorValue = analogRead (sensorPin);
  
  int proximity = digitalRead(MOTION_PIN);
  if (proximity == LOW || sensorValue>30) // If the sensor's output goes low, motion is detected
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    //Serial.println(".");
  }
}
