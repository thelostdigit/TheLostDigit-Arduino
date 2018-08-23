//TheLostDigit
//Shock Sensor
//Simple way to use a shock sensor

int SHK_PIN = 3; //Pin for the shock sensor

int shk; //Variable to store the shk reading

//Setup the Arduino
void setup() 
{
  Serial.begin(9600); //Start the serial connection to the computer
  pinMode(SHK_PIN, INPUT); //Make the pin you used an input on the Arduino
}

//This code will run infinitely
void loop() 
{

  delay(1); //Delay 1mS to slow to 1000 readings per second
  if(digitalRead(SHK_PIN) == HIGH) //Read the shock sensor
  {
    Serial.println("Shock Detected"); //Print out that we have been shaken
    Serial.println("Resetting...");
    delay(500); //Wait half a second before reading again
  }
  
}

