#include <Servo.h>

Servo myServo;

char receivedChar;
boolean newData = false;

void setup() {
 Serial.begin(57600);
 Serial.println("<Arduino is ready>");

 myServo.attach(9);
}

void loop() {
 recvOneChar();
 showNewData();
}

void recvOneChar() {
 if (Serial.available() > 0) {
 receivedChar = Serial.read();
 newData = true;
 }
}

void showNewData() {
 if (newData == true) {
 Serial.print("Runing command: ");
 Serial.println(receivedChar);
 if(receivedChar == 'a') {
  myServo.write(0);
  Serial.println("Moving myServo to 0");
 }
 if(receivedChar == 'b') {
  myServo.write(180);
  Serial.println("Moving myServo to 180");
 }
 newData = false;
 }
}

