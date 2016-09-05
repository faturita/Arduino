/* 
 Stepper Motor Control - one revolution
 Este programa impulsa un motor paso a paso unipolar o bipolar. 
 El motor está conectado a los pines digitales 8 - 11 de la Arduino. 
 El motor debe girar una vuelta en una dirección, a continuación, 
 una revolución en la otra dirección. 
 
 Created 11 Mar. 2007
 by Tom Igoe
 
 Modificado
 16/05/14
 por Andres Cruz
 ELECTRONILAB.CO
 */

#include <Stepper.h>

const int stepsPerRevolution = 100;  // cambie este valor por el numero de pasos de su motor

// inicializa la libreria 'stepper' en los pines 8 a 11
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // establece la velocidad en 60rpm
  myStepper.setSpeed(60);
  // inicializa el puerto serial
  //Serial.begin(1200);
}

void loop() {
  // gira una vuelta en una direccion
   Serial.println("clockwise");
  myStepper.step(-1);
  delay(500);
  
   // gira otra vuelta en la otra direccion
  //Serial.println("counterclockwise");
  //myStepper.step(-1);
  //delay(500); 
}
