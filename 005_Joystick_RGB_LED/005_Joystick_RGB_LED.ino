//TLD - TheLostDigit
//Joystick with RGB LED Control
//Simple way to use a joystick to control an RGB LED

int R_PIN = 9; //Pin for the red portion of the LED
int G_PIN = 10; //Pin for the red portion of the LED
int B_PIN = 11; //Pin for the red portion of the LED
int JX_PIN = 0; //Pin for the Joystick X Direction (Analog)
int JY_PIN = 1; //Pin for the Joystick Y Direction (Analog)
int JSW_PIN = 2; //Pin for the Joystick Switch


int joyX; //Variable to store the Joystick X reading
int joyY; //Variable to store the Joystick Y reading
int joySW; //Variable to store the Joystick Switch Reading

//Setup the Arduino
void setup() 
{
  pinMode(R_PIN, OUTPUT); //Make the pin you used an output on the Arduino
  pinMode(G_PIN, OUTPUT); //Make the pin you used an output on the Arduino
  pinMode(B_PIN, OUTPUT); //Make the pin you used an output on the Arduino
  pinMode(JSW_PIN, INPUT); //Make the pin you used an input on the Arduino
}

//This function will update the RGB LED when called
void setRGB(int rLed, int gLed, int bLed)
{
  analogWrite(R_PIN, rLed);
  analogWrite(G_PIN, gLed);
  analogWrite(B_PIN, bLed);
}

//This code will run infinitely
void loop() 
{

  delay(100); //Delay 100mS to slow to 10 readings per second
  joyX = analogRead(JX_PIN); //Read the X position
  joyY = analogRead(JY_PIN); //Read the Y position
  joySW = digitalRead(JSW_PIN); //Read the Switch, if it is pressed output will be 1, if not, 0

  setRGB(joyX, joyY, 255*joySW);  
  
}

