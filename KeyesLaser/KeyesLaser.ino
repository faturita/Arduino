/**
 * 
 * Keyes Laser
 * 
 * Pin - = GND
 * Pin (middle pin) = not connected
 * Pin S = +5V (through pin 13)
 * 
 * The middle pin can be used to check how much amount of voltage is being consumed
 */


void setup ()
{
   pinMode (13, OUTPUT); // define the digital output interface 13 feet
}

void loop () {
   digitalWrite (13, HIGH); // open the laser head
   delay (1000); // delay one second
   digitalWrite (13, LOW); // turn off the laser head
   delay (1000); // delay one second
}
