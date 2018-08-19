//TheLostDigit
//Magnetic Spring Sensor Code
//Simple way to sense magnetic field

int ANALOG_MAG_PIN = A0; //The analog pin for the analog output of the sensor
int DIGITAL_MAG_PIN = 5; //The digital pin for the digital output of the sensor

int mag_D;
int mag_A;

//Setup the Arduino
void setup() 
{
  Serial.begin(9600); //Start the serial connection to the computer
  pinMode(ANALOG_MAG_PIN, INPUT); //Make the pin you used an input on the Arduino
  pinMode(DIGITAL_MAG_PIN, INPUT); //Make the pin you used an input on the Arduino
  
}

//This code will run infinitely
void loop() 
{
  mag_D = digitalRead(DIGITAL_MAG_PIN); //Read the signal from your sensor
  mag_A = analogRead(ANALOG_MAG_PIN); //Read the signal from your sensor

  delay(100); //Add in 100mS of delay to slow the readings to 10 times per second
  if(mag_D == HIGH)
  {
    Serial.print("A magnet is near: "); //Print out the results
    Serial.println(mag_A); //Print the raw analog output
  }
  else
  {
    Serial.print("No magnet detected: "); //Print out the results
    Serial.println(mag_A); //Print the raw analog output
  }
  
}

