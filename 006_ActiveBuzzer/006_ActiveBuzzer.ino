//TLD - TheLostDigit
//Active Buzzer
//Simple way to use an active buzzer

int B_PIN = 9; //Pin for the red portion of the LED

//Setup the Arduino
void setup() 
{
  pinMode(B_PIN, OUTPUT); //Make the pin you used an output on the Arduino
}

//Function to play a tone for time mS at tone with a range of 0-255
void playTone(int time, int tone)
{
  //Loop the tone for time mS
  for(int i = 0; i < time; i++)
  {
    //Write the tone to the buzzer pin
    analogWrite(B_PIN, tone);
    delay(1);
  }
  analogWrite(B_PIN, LOW);
}

//This code will run infinitely
void loop() 
{
  playTone(100, 100);
  delay(100);
  playTone(30, 60);
  delay(100);
  playTone(60, 165);
  delay(100);

  playTone(200, 200);
  delay(100);
  playTone(80, 250);
  delay(100);
  playTone(350, 220);
  delay(100);

  playTone(100, 100);
  delay(100);
  playTone(30, 60);
  delay(100);
  playTone(60, 165);
  delay(100);
}

