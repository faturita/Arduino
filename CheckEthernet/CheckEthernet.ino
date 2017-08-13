void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:
  system("sudo ifconfig >> /dev/ttyGS0");

  delay(200);
}
