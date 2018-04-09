//#include <VarSpeedServo.h>
#include <Servo.h>
#include <dht.h>

char imput;
boolean newData = false;
Servo roll;


dht DHT;
#define DHT11_PIN 7 //Change this to the pin you want to use for the sensor

int del = 5; //Serial delay command
int notify = 100; //The number of un-notified checks between error prints

void setup() {
  Serial.begin(57600);
  Serial.println("You've been save");
  delay(del);
  help();
  roll.attach(9);
}

void loop() {
  command(); //Takes a command and stores it // please update for multi char!!
  index(); //Index data in the store to a command
  check(); //Check automatic functions of the robot
}

void command() {
  if (Serial.available() > 0) {
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
    if(imput == 'm') {
      Serial.println("Exc program 'Turn'");
      rMove();
    }

//End Index
    newData = false;
    if ((imput == 'a') || (imput == 'h') || (imput == 's') || (imput == 'm')) {
      delay(2);
    }else{
      Serial.println("That is not a command or it has not been added to my index yet.");
    }
  }
}

void check(){
  notify--;
  int temp = digitalRead(2);
  if(temp >= 0/*replace me with a value!*/){
    if(notify >1){
      int chk = DHT.read11(DHT11_PIN);
      Serial.print(/*replace me with a color!*/ "Warning! Tempature is low: ");
      Serial.println(DHT.temperature);
    }
  }


  
  int val = digitalRead(1);
  if(val != 0){
    if(notify >1){
      Serial.println("The formost limit switch has been depressed, check the orentation of the robot");
      notify == 100;
    }
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
  roll.write(serv * 20);
  //code to run a contiuious roll servo for 10 rotations

  val = digitalRead(1); //pin for limit switch
  if(val = 0){
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
  Serial.println("-JPS");
  Serial.println("-----------------------------------------------------------------------");
}

void rStatus() {
  //Runs when you send command s
  //Gets the robot health/status
  notify = 0;
  check();
}
