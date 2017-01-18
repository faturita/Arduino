int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(11,INPUT);
    Serial.begin (9600);
}

int sensorValue = 0;

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead (11);
  
  //delay (sensorValue);
  digitalWrite (ledPin, LOW);
  //delay (sensorValue);
  if (sensorValue>30) {
    digitalWrite (ledPin, HIGH); 
    }
  Serial.println (sensorValue, DEC);
  
}
