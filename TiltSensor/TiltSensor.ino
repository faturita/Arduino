const int TILT_PIN = 8;

bool checktilted()
{
  int tiltVal = digitalRead(TILT_PIN);
  if (tiltVal == HIGH) {
    Serial.println("Tilted.");
    return true;
  } else {
    Serial.println("Not Tilted.");
    return false;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(TILT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool tilted = checktilted();
}
