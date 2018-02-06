char imput;
boolean PCData = false;
boolean RoverData = false;
int headLampState = 2;
int pushButton;

void setup() {
  Serial.begin(57600);
  Serial.println("Code Stared sucsesfully");
  Serial1.begin(57600);
  pinMode(pushButton, INPUT);
}

void loop() {
  bypass();
  button();
}

void bypass(){
 if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.print(inByte);

  }
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.print(inByte);
  }
}

void button(){
  int headLampState = digitalRead(pushButton);
  if (headLampState == 1){
    Serial1.print('h');
  }
  delay(1);
}

