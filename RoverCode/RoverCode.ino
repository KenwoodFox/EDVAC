//#include <VarSpeedServo.h>
#include <Servo.h>
#include <dht.h>

char imput; //This char will be populated with the current command
boolean newData = false; //This will denote to the index function when to spend time checking the serial registry
Servo servo; //Add the roll servo
dht DHT; //IDK what this does
#define DHT11_PIN 7 //Change this to the pin you want to use for the sensor

int del = 5; //Serial delay command
int notify = 500; //The number of un-notified checks between error prints

void setup() {
  Serial.begin(57600); //The only baud rate to work on the radios
  Serial.println("You've been save"); //Travis is a good boy
  delay(4000); //Wait for the radios to link
  help(); //Display the help page
  servo.attach(12); //Attach the roll servo to pin
}

void loop() {
  command(); //Takes a command and stores it // please update for multi char!!
  index(); //Index data in the store to a command
  //check(); //Check automatic functions of the robot
}

void command() {
  if (Serial.available() > 0) { //If a new command comes in, convert it into the imput variable and index it before overwriting it
    imput = Serial.read();
    newData = true;
  }
}

void index() {
  if (newData == true) {
    Serial.println('*'); //replace me with a color code!
    delay(100);
    Serial.print("Received Command: ");
    Serial.println(imput);
    Serial.println("-----------------------------------------------------------------------");
//Command Index here
    if(imput == 'a') {
      Serial.println("Exc program 'a'");
      comA();
    }

    if(imput == 'h') {
      Serial.println("Opening Help");
      help();
    }

    if(imput == 's') {
      Serial.println("Opening Status");
      rStatus();
    }
    if(imput == 'r') {
      Serial.println("Exc program 'Turn'");
      rMove();
    }

//End Index
    newData = false; //Set the data in the index char to be overwrittin
    if ((imput == 'a') || (imput == 'h') || (imput == 's') || (imput == 'r')) { //Secondary index to display the error message below
      delay(2);
    }else{
      Serial.println("That is not a command or it has not been added to my index yet.");
    }
  }
}

void check(){
  /* This command works by taking inventory of all the automated checks
   * When not called by a command, this function will wait a numbr of
   * cycles before activating and printing its warnings, or lacktherepf
   */
  notify--;
  while(notify <= 0 ){
    int temp = digitalRead(2);
    if(temp >= 0/*replace me with a value!*/){
      int chk = DHT.read11(DHT11_PIN);
      Serial.print(/*replace me with a color!*/ "Warning! Tempature is low: ");
      Serial.println(DHT.temperature);
    }

    int val = digitalRead(1);
    if(val != 0){
    Serial.println("The formost limit switch has been depressed, check the orentation of the robot");
    }
    notify == 100;
  }
}

//command codes

void comA() {
  //Runs when you send command A
  Serial.println("Robot has done nothing.");
  Serial.println("-----------------------------------------------------------------------");
}

void rMove(){
  int val = 0;
  int serv = 0;

  Serial.println("Imput Degree (0-9)");
  while(Serial.available() <= 0){
    delay (10);
  }
  serv = Serial.read();
  Serial.print("Received value: ");
  Serial.println(serv);
  servo.write(serv);
  //code to run a contiuious roll servo for 10 rotations

  val = digitalRead(1); //pin for limit switch
  if(val = 1){
    Serial.println("The operation has been completed with no errors");
  }else{
    Serial.print("The Robot has encountered an error: ");
    Serial.println("The formost limit switch has been depressed, check the orentation of the robot");
  }
}

void help() {
  //Runs when you send command H
  Serial.println("Command 'a': Does nothing.");
  delay(del);
  Serial.println("Command 'h': Shows this list of commands.");
  delay(del);
  Serial.println("Command 's': Checks the Status of the robot.");
  delay(del);
  Serial.println("Command 'r': Rotates the assembly, you will be prompted for a degree of motion");
  delay(del);
  Serial.println("-JPS");
  Serial.println("-----------------------------------------------------------------------");
}

void rStatus() {
  //Runs when you send command s
  //Gets the robot health/status
  notify = 0;
  check();
}
