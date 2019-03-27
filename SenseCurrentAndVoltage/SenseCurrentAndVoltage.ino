/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.


  Current divider

  A0 ----- R2 -------- GND
                  |
                  R1
                  |
                  SIGNAL

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

int mVperAmp = 100; // use 185 for 5A, 100 for 20A (I have 2 of that) Module and 66 for 30A Module
double ACSoffset = 0;

float r1=28600;//32000.0;
//float r1=90900.0;  // this is the first resistance 
float r2=10100.0;  // this is the second resistance to A0

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float input_voltage = sensorValue * (5.0 / 1023.0);
  float voltage = input_voltage / (r2/(r1+r2)); // 10:1 relation to measure 50V
  //float voltage = input_voltage;


  double Voltage = (sensorValue / 1023.0) * 5000; // Gets you mV
  double Amps = ((Voltage - ACSoffset) / mVperAmp);

  
  // print out the value you read:
  Serial.print(voltage,4);
  Serial.print("-");
  Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
}
