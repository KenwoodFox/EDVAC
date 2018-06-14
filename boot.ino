void boot()
{
  Serial.println("The PLC has restarted, if you did not trigger this restart, a power surge may have caused it to reboot.");
  delay(2000);
  Serial.println("Starting potatOS by Joe, Version PRE ALPHA");
  delay(10);
  Serial.print("Loading ");
  while(i < 20)
  {
    Serial.print("=");
    delay(300);
    i++;
  }
  delay(10);
  Serial.println(" Finished loading.");
  delay(1500);
  Serial.println("Controler online");
}

