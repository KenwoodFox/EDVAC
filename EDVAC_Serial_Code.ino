#include <Servo.h>

char imput;
boolean newData = false;

void setup() {
  Serial.begin(57600);
  Serial.println("Robot is ready for commands. Here are the commands:");
  Serial.println("Command 'a': Does nothing.");
  Serial.println("Command 'b': Does nothing.");
  Serial.println("Command 's': Checks the Status of the robot.");

}

void loop() {
  command();
  index();
}

void command() {
  if (Serial.available() > 0) {
    imput = Serial.read();
    newData = true;
  }
}

void index() {
  if (newData == true) {
    Serial.print("Received Command: ");
    Serial.println(imput);
//Command Index here
    if(index == 'a') {

      Serial.println("Starting program 'a'");
      comA();
    }

    if(index == 'b') {

      Serial.println("Starting program 'b'");
      comB();
    }

    if(index == 's') {

      Serial.println("Starting program 'c'");
      rStatus();
    }

//End Index
    newData = false;
    if ((index != 'a') || (index != 'b') || (index != 's')) {
      Serial.println("That is not a command or it has not been added to my index yet.");
    }
  }
}

//command codes

void comA() {
  //Runs when you send command A
  Serial.println("Nothing, but think of the posibilities this technology could be used for.");
}

void comB() {
  //Runs when you send command B
  Serial.println("Nothing");
}

void rStatus() {
  //Runs when you send command s
  //Gets the robot health/status
  Serial.println("Water level: Safe");
  Serial.println("Motor temp: Safe : motorFR, motorFL, motorMR, motorML, motorRR, motorRL, ");
  Serial.println("Hull: No breaches detected: Camera cover is broken");
}
