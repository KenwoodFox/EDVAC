void operation_light()
{
  Serial.println("To Toggle Light States, imput a number between 0 and 10...");
    while(newData = false && commandTimeout >= 0)
    {
      //do nothing
      delay(5);
      commandTimeout--;
    }

    if(commandTimeout >= 0)
    {
      Serial.println("Command Timed out");
    }
    else
    {
      imputActual();
      if(imputACT == 1 || 2 || 3 || 4 || 5)
      {
        state = digitalRead(imputACT + 48);
        if(state == LOW)
        {
          digitalWrite(imputACT + 48, HIGH);
          state = HIGH;
        }
        else
        {
          digitalWrite(imputACT + 48, LOW);
          state = LOW;
        }
      }
      else
      {
        Serial.println("Outside my range of lights");
      }
    }
      
    Serial.print("Changed state of ");
    Serial.print(imputACT);
    Serial.print(" to ");
    Serial.println(state);
    delay(10);
    imput = "";
    state = LOW;
    Serial.println("Menu Closing");
}
