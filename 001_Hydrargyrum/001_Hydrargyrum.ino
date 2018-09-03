//TheLostDigit
//Hydrargyrum Switch Code
//On and Off tilt state sensed without accelerometer or difficult programming

int HYD_PIN = 5; //The pin for the signal of the Hydrargyrum Switch

int tilt; //Tilt of the sensor reading can be stored here

//Setup the Arduino
void setup() 
{
  Serial.begin(9600); //Start the serial connection to the computer
  pinMode(HYD_PIN, INPUT); //Make the pin you used an input on the Arduino
  
}

//This code will run infinitely
void loop() 
{
  tilt = digitalRead(HYD_PIN); //Read the signal from your sensor

  delay(100); //Add in 100mS of delay to slow the readings to 10 times per second
  if(tilt == HIGH)
  {
    Serial.println("Circuit Open: It's Tilted!"); //Print out the results
  }
  else
  {
    Serial.println("Circuit Closed: It's Flat!"); //Print out the results
  }

}
