/**
 * Control de un motor paso a paso utilizando el LD298 conectado a los 
 * pines de Arduino
 * 
 * Cada uno de los cables del motor se debe conectar a cada una de las salidas
 * del LD298, que además tiene que ser alimentado por afuera.
 * 
 * 
 */



int inA1 = 8; // input 1 of the stepper
int inA2 = 9; // input 2 of the stepper
int inB1 = 10; // input 3 of the stepper
int inB2 = 11; // input 4 of the stepper

int stepDelay = 100; // Delay between steps in milliseconds

void setup() {                
  pinMode(inA1, OUTPUT);     
  pinMode(inA2, OUTPUT);     
  pinMode(inB1, OUTPUT);     
  pinMode(inB2, OUTPUT);     
}

void step1() {
  digitalWrite(inA1, LOW);   
  digitalWrite(inA2, HIGH);   
  digitalWrite(inB1, HIGH);   
  digitalWrite(inB2, LOW);   
  delay(stepDelay);
  
}
void step2() {
  digitalWrite(inA1, LOW);   
  digitalWrite(inA2, HIGH);   
  digitalWrite(inB1, LOW);   
  digitalWrite(inB2, HIGH);   
  delay(stepDelay);
}
void step3() {
  digitalWrite(inA1, HIGH);   
  digitalWrite(inA2, LOW);   
  digitalWrite(inB1, LOW);   
  digitalWrite(inB2, HIGH);   
  delay(stepDelay);
}
void step4() {
  digitalWrite(inA1, HIGH);   
  digitalWrite(inA2, LOW);   
  digitalWrite(inB1, HIGH);   
  digitalWrite(inB2, LOW);   
  delay(stepDelay);
}
void stopMotor() {
  digitalWrite(inA1, LOW);   
  digitalWrite(inA2, LOW);   
  digitalWrite(inB1, LOW);   
  digitalWrite(inB2, LOW);   
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i=0; i<=27; i++){ 
    step1(); 
    step2();
    step3();
    step4();
  }
  stopMotor();
  delay(10);
  
  for (int i=0; i<=27; i++){
    step3();
    step2();
    step1();
    step4(); 
  }
  
  stopMotor();
  delay(10);
}
