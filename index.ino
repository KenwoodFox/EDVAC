void index()
{
  delay(10);
  newData = false; //Set the data in the index char to be overwrittin
  delay(100);
  Serial.print("Received Command: ");
  Serial.println(imput);

  //commands
  if (imput == "example")
  {
    Serial.println("exc operation example");
    operation_example();
    
    if (EXAMPLECOMPLETE == true)
    {
      Serial.println("Operation complete");
    }
    else
    {
      Serial.println("Operation not completed!");
    }
    EXAMPLECOMPLETE = false;
  }

  if (imput == "light")
  {
    Serial.println("Entering Light Operation Menu");
    operation_light();
    
    if (EXAMPLECOMPLETE == true)
    {
      Serial.println("Operation complete");
    }
    else
    {
      Serial.println("Operation not completed!");
    }
    EXAMPLECOMPLETE = false;
  }

  //End Index
    if ((imput == "light") || (imput == "example"))
    { //Secondary index to display the error message below
      delay(2);
    }
    else
    {
      //imput = "";
      Serial.println("That is not a command or it has not been added to my index yet.");
    }
    imput = "";
}
