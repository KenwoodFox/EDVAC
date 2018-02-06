//#include <VarSpeedServo.h>
//#include <Servo.h>

char imput;
boolean newData = false;

int del = 5; //Serial delay command

void setup() {
  Serial.begin(57600);
  Serial.println("You've been save");
  delay(del);
  help();
}

void loop() {
  command(); //Takes a command and stores it // please update for multi char!!
  index(); //Index data in the store to a command// 
}

void command() {
  if (Serial.available() > 0) {
    imput = Serial.read();
    newData = true;
  }
}

void index() {
  if (newData == true) {
    Serial.println('*');
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

//End Index
    newData = false;
    if ((imput == 'a') || (imput == 'h') || (imput == 's')) {
      delay(2);
    }else{
      Serial.println("That is not a command or it has not been added to my index yet.");
    }
  }
}

//command codes

void comA() {
  //Runs when you send command A
  Serial.println("Robot has done nothing.");
  Serial.println("-----------------------------------------------------------------------");
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
  Serial.println("Seems good to me pal");
  Serial.println("-----------------------------------------------------------------------");
  //Serial.write(27);   //Print "esc"
  //Serial.print("[2J");
}
