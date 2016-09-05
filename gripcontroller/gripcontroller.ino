/**
 * Digital control multiple outputs.
 */


int IN3 = 5; 
int IN4 = 4;
int IN2 = 3; 
int IN1 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN2, OUTPUT);    // Input4 conectada al pin 3 
  pinMode (IN1, OUTPUT);    // Input3 conectada al pin 2
}

int state = 0;

void loop() {
  // put your main code here, to run repeatedly:

  switch(state)
  {
    case 0: 
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        break;
    case 1:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        break;
  }

  state = state && 1;

  delay(90);

}
