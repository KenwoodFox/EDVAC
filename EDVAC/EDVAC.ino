//#include <dht.h>

//Operation specific variables
//Operation lift
boolean LIFTCOMPLETE = false; //Signify that the operation is complete
int LIFTLIMIT = false; //the state of the pin that signals when the lift is at one of its two states
int LIFTTIMEOUT = 0; //the time the motor will run before the system stops trying to lift
int LIFTREAD = 500; //every so many ms read the state of the limit
//Operation vent
boolean VENTCOMPLETE = false; //Signify that the operation is complete 
//Operation water
boolean WATERCOMPLETE = false; //Signify that the operation is complete
//End Operation specific variables

//Other variables here
int i = 0; //generic integer to run while loops
boolean newData = false; //becomes true only as long as there is unindexed information
String imput = ""; //populated with the current command not yet run
//End other variables



void setup() {
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
}
