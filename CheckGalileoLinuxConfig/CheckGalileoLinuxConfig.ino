// Rojo es Rx en la punta  y se conecta al pin 3 (TxD) del IDC 10
// Blanco es Tx en el medio y se conecta al pin 2 (RxD) del IDC 10
// Amarillo es GND atras y se conecta al pin 5 (ground)

/**
 * La conversion de IDC-10 a DB9 estandar es la siguiente
 * 
 * 1 2 3 4 5        1 3 5 7 9
 *  6 7 8 9 .       2 4 6 8 10
 *  
 * El pin 10 es el unico que queda libre en el conector de IDC y sirve a la vez
 * para identificar rapidamente como es el pinout (tiene que quedar abajo a la derecha viendo el 
 * conector de adelante).
 * 
 * El conector de RS232 es
 * 1 - DCD
 * 2 - RxD
 * 3 - TxD
 * 4 - DTR
 * 5 - GND
 * 6 - DSR
 * 7 - RTS
 * 8 - CTS
 * 9 - RI
 * 
 */


void setup() {
 system("telnetd -l /bin/sh"); //telnet
 }
 
void loop() {
 system("ifconfig  > /dev/ttyGS0");
 delay(5000);
 }
