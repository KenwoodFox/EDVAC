//#include <Servo.h>

char imput;
boolean newData = false;

void setup() {
  Serial.begin(57600);
  Serial.println("Robot is ready for commands. Here are the commands:");
  help();

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

    if(index == 'h') {

      Serial.println("Starting program help");
      help();
    }

    if(index == 's') {

      Serial.println("Starting program status");
      rStatus();
    }

//End Index
    newData = false;
    if ((index != 'a') || (index != 'h') || (index != 's')) {
      Serial.println("That is not a command or it has not been added to my index yet.");
    }
  }
}

//command codes

void comA() {
  //Runs when you send command A
  Serial.println("Robot has done nothing.");
}

void help() {
  //Runs when you send command B
  Serial.println("Command 'a': Does nothing.");
  Serial.println("Command 'h': Shows this list of commands.");
  Serial.println("Command 's': Checks the Status of the robot.");
  Serial.println("Coded by Joe in colaboration with");
}

void rStatus() {
  //Runs when you send command s
  //Gets the robot health/status
  Serial.println("Seems good to me pal");
}
