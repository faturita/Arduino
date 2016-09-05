/**
 * Si bien se chequea el barómetro, también se chequea la librería customizada
 * creada para eso.
 * 
 */

#include "Arduino.h"
#include "Wire.h"
#include <Barometer.h>

Barometer barometer(1);

void setup() {
  Serial.begin(9600);

  Serial.println("Ready to capture!");


}

void loop() {
  // put your main code here, to run repeatedly:

  //barometer.toserial();

}
