/*
Measuring Current Using ACS712
http://henrysbench.capnfatz.com/henrys-bench/arduino-current-measurements/the-acs712-current-sensor-with-an-arduino/

In order to have this sensor to work you first need to measure the current that you are receiving !  Otherwise its value is meaningless


*/
const int analogIn = A0;
int mVperAmp = 100; // use 185 for 5A, 100 for 20A (I have 2 of that) Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 0; 
double Voltage = 0;
double Amps = 0;

void setup(){ 
 Serial.begin(9600);
}

void loop(){
 
 RawValue = analogRead(analogIn);
 Voltage = (RawValue / 1023.0) * 5000; // Gets you mV
 Amps = ((Voltage - ACSoffset) / mVperAmp);
 
 
 Serial.print("Raw Value = " ); // shows pre-scaled value 
 Serial.print(RawValue); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
 delay(2500); 
}
