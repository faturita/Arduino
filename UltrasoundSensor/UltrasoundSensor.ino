#define trigPin 13
#define echoPin 12

bool debug = true;


void setup() {
  Serial.begin (9600);
  Serial.println("Sensorimotor Cortex");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 12) {  

    if (debug)
    {
      Serial.print("OBSTACLE !");Serial.println(distance);
    }
  }
}
