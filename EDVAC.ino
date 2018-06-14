//#include <dht.h>

//Operation specific variables
//Operation lights

//Operation Example
boolean EXAMPLECOMPLETE = false;

//End Operation specific variables

//Other variables here
int i = 0; //generic integer to run while loops
int state = LOW;
int imputACT = "";
int commandTimeout = 40; //The interger to determine if a command has timed out or not (so as to not get stuck in a loop)
boolean newData = false; //becomes true only as long as there is unindexed information
String imput = ""; //populated with the current command not yet run
//End other variables



void setup() {
  pinmode();
  
  Serial.begin(57600); //start serial port
  delay(10);
  // reserve 200 bytes for the imput
  imput.reserve(200);
  while(Serial.available() == 0)
  {
    delay(10);
    //Do nothing untill imput is applied
  }
  imput = "";
  delay(10);
  boot();

}

void loop() {
//  readFromSerial(); //read a command from serial when available
  if(newData == true)
  {
    index();
  }
  delay(1);
}
