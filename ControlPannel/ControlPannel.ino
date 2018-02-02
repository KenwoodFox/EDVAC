int potX = 0;
int potY = 1;
int x = 0;
int y = 0;

void setup() {
  Serial.begin(57600);
  Serial.println("Code Stared sucsesfully");
}

void loop() {
  //Read Values
  x = analogRead(potX);
  y = analogRead(potY);
  Serial.print(x);
  Serial.print(" ");
  Serial.println(y);
  delay(10);
}
