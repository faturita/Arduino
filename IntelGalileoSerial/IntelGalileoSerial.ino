//These commands have be coded for communinating with ESP8266 via Intel Galileo
//whole article and required pin configuration between Galileo and ESP8266
//is available on yildirimsemih.wordpress.com
//Rx of ESP8266 to Galileo's pin1:Tx
//    Rx,Tx should be 5v ----- 1 kOhm ----|--- 2 kOhm ---- GND
//                                        |---- Tx, Rx    
//Tx of ESP8266 to Galileo's pin0:Rx
//VCC of ESP8266MOD to Galileo's 3.3V voltage output
//GND to GND
// Reset should go from VCC ---- 10 KOhm ---- Reset ---- Button --- GND

// https://room-15.github.io/blog/2015/03/26/esp8266-at-command-reference/
// https://yildirimsemih.wordpress.com/2015/04/04/communicating-with-esp8266-via-intel-galileo/
// https://yildirimsemih.wordpress.com/2015/05/01/3-5mm-jack-girisi-uzerinden-linux-terminaline-baglanma-intel-galileo-gen1/

// http://securityrobot-actuarial-vespers.mybluemix.net/


String a = "";
char c;
char k;

unsigned long previousMillis = 0;

bool datasent = false;


void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);

  Serial.println("Starting...");

  previousMillis = millis();

  randomSeed(analogRead(0));
}


/**
 * AT+GMR  -> Version
 * AT+RST  -> Reset
 * 
 * AT+CWMODE=2
 * AT+CWSAP="ESP","password",1,4
 * AT+CIPSTA="192.168.101.108"
 * AT+CIPAP="192.168.1.1"
 * 
 * AT+CIFSR   Info de la interfaz
 * AT+CIPAP?   IP
 * 
 * AT+CWLIF   Quienes estan conectados
 * 
 * 
 * AT+CWDHCP=0,1   Habilitar DHCP
 * 
 * 
 * 
 * 
 * AT+CIPSTART="UDP","192.168.1.3",10000
 * AT+CIPSEND=1
 * Permite mandar 1 bytes
 * 
 * Si en ese momento se reciben bytes desde el otro lado
 * de la conexion
 * 
 * se recibe
 * +IPD,1:o
 * 
 * AT+CIPCLOSE

 * 
 */

void loop() {

  if (Serial1.available()) { // if ESP8266 is available on Serial1

    while (Serial1.available()) { // while it is available
      c = Serial1.read(); //listen to Serial1(ESP8266) character by character and assign to c
      a += c; // assign c to string a
    }
    Serial.print(a);; //print the responding of ESP8266
    a = ""; // empty the string a
  }


/**
  if ((!datasent) && ((millis()-previousMillis) > 1000*1000))
  {
    sendupdate();
    datasent=true;
  }
**/

  if (Serial.available()) { //if USB client is available on Serial Port Monitor(Serial)
    delay(2000); // delay is required to whole reading of your command
    // which will be send to ESP8266
    String yourcommand = ""; //create empty string for storing your command
    while (Serial.available()) { // while Serial is available
      k = Serial.read(); //listen to Serial Port Monitor on IDE(Serial)
      // character by character and assign to k
      yourcommand += k; // assign each char k to yourcommand
    }
    Serial1.println(yourcommand); // send the read character to ESP8266
  }
  
}


void setupnet()
{
  Serial1.println("");
}

void sendupdate()
{
  Serial1.println("AT+CIPSTART=\"TCP\",\"securityrobot-actuarial-vespers.mybluemix.net\",80");
  delay(1000);

  char tmp[256];
  char msg[1024];
  char cmd[256];
  int id=0;

  id=random(100);

  memset(msg,0,1024);
  
  strcat(msg,"POST /api/visitors HTTP/1.1\r\n");
  strcat(msg,"Host: securityrobot-actuarial-vespers.mybluemix.net\r\n");
  strcat(msg,"Content-Type: application/json\r\n");
  strcat(msg,"Cache-Control: no-cache\r\n");
  strcat(msg,"\r\n");
  sprintf(tmp,"{\"name\":\"User%d\"}\r\n",id);
  strcat(msg,tmp);


  sprintf(cmd,"AT+CIPSEND=%d\r\n",strlen(msg));
  Serial1.print(cmd);
  delay(5000);

  Serial1.print(msg);
  
  delay(5000);

  Serial1.println("AT+CIPCLOSE");

  Serial.println("Done");
}

