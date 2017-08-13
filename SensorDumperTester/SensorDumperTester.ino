struct sensortype
{
  double onYaw;
  double onPitch;
  double onRoll;
  float T;
  float P;
  double light;
  int yaw;
  int pitch;
  int roll;
  int geoYaw;
  int geoPitch;
  int geoRoll;
  int sound;

} sensor;

#define debug 0

bool serialOpen = 1;

bool txSensor = false;

void dump(char *msg)
{
  if (serialOpen)
  {
    Serial.println(msg);
  }
}

int sampleCounter=0;

void checksensors()
{
  sensor.yaw = 1+sampleCounter;
  sensor.roll = sampleCounter*20;
  sensor.pitch = sampleCounter*34;
}

void transmitsensor() {
  int len = sizeof(sensor);
  char aux[len];  //38
  memcpy(&aux,&sensor,len);

  Serial.write('S');
  Serial.write((uint8_t *)&aux,len);
  Serial.write('E');

  if (debug) {
    Serial.println('S');
    Serial.print("Rot Yaw:");Serial.println(sensor.onYaw);
    Serial.print("Rot Pitch:");Serial.println(sensor.onPitch);
    Serial.print("Rot Roll:");Serial.println(sensor.onRoll);
    Serial.print("Yaw:");Serial.println(sensor.yaw);
    Serial.print("Pitch:");Serial.println(sensor.pitch);
    Serial.print("Roll:");Serial.println(sensor.roll);
    Serial.print("Geo Yaw:");Serial.println(sensor.geoYaw);
    Serial.print("Geo Pitch:");Serial.println(sensor.geoPitch);
    Serial.print("Geo Roll:");Serial.println(sensor.geoRoll);
    Serial.print("Temperature:");Serial.println(sensor.T);
    Serial.print("Pressure:");Serial.println(sensor.P);
    Serial.println(']');
    Serial.print("Length:");Serial.println(len);
  }
  

  //Aguarda 5 segundos e reinicia o processo
  //delay(5000);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  dump("Senser Dumper Tester...");

  sensor.onYaw=0;
  sensor.onPitch=0;
  sensor.onRoll=0;
  sensor.T=0;
  sensor.P=0;
  sensor.light=0;
  sensor.yaw=0;
  sensor.pitch=0;
  sensor.roll=0;
  sensor.geoYaw=0;
  sensor.geoPitch=0;
  sensor.geoRoll=0;
  sensor.sound=0;
}

void loop() {
  if (txSensor)
  {
    checksensors();
    transmitsensor();
    sampleCounter++;
    if (sampleCounter > 100)
    {
      txSensor = false;
      sampleCounter = 0;
    }
  }

  bool doaction = false;
  int incomingByte;
  
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    doaction = true;
  }

  if (doaction) 
  {
    switch (incomingByte) {
      case 'I':
        dump("MTRN");
        break;
      case 'S':
        txSensor = true;
        break;
      case 'X':
        txSensor = false;
        break;
      default: break;
    }
  }
}
