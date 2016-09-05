/******************************************************************************
Magician chassi wheel encoder

OUTB - nothing
OUTA - Digital pin 4 (active on low)
VCC
GND

******************************************************************************/
const int MOTION_PIN = 4; // Pin connected to motion detector
const int LED_PIN = 13; // LED pin - active-high

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
  int proximity = digitalRead(MOTION_PIN);
  if (proximity == LOW) // If the sensor's output goes low, motion is detected
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    Serial.println(".");
  }
}
