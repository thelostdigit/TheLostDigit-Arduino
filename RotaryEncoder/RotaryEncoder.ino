//TheLostDigit
//Rotary Encoder
//Simple way to use a rotary decoder as a volume knob

int CLK_PIN = 3; //Pin for the clk out of the sensor
int DT_PIN = 4; //Pin for the dt out of the sensor
int SW_PIN = 5; //Pin for the sw out of the sensor - Reads low when the button pressed


int clk; //Variable to store the clk reading
int dt; //Variable to store the dt reading
int sw; //Variablet to store the switch reading
int volume; //Variable to store the volume

//Setup the Arduino
void setup() 
{
  Serial.begin(9600); //Start the serial connection to the computer
  pinMode(CLK_PIN, INPUT); //Make the pin you used an input on the Arduino
  pinMode(DT_PIN, INPUT); //Make the pin you used an input on the Arduino
  pinMode(SW_PIN, INPUT); //Make the pin you used an input on the Arduino
  volume = 0; //Initialize the voluem to 0
}

//This code will run infinitely
void loop() 
{
  int clk_temp = digitalRead(CLK_PIN); //Read the signal from your sensor
  int dt_temp = digitalRead(DT_PIN); //Read the signal from your sensor
  int sw_temp = digitalRead(SW_PIN); //Read the signal from your sensor

  //Debounce the readings, if they are true they will be stored
  delay(6);
  if(clk_temp == digitalRead(CLK_PIN)) //Compare the new reading
  {
    clk = clk_temp; //Store the reading
  }
  if(dt_temp == digitalRead(DT_PIN)) //Compare the new reading
  {
    dt = dt_temp; //Store the reading
  }
  if(sw_temp == digitalRead(SW_PIN)) //Compare the new reading
  {
    sw = sw_temp; //Store the reading
  }

  if(clk == HIGH && dt == LOW && volume < 50)
  {
    volume++;
    Serial.print("Volume: "); //Print out the results
    Serial.println(volume); //Print the raw analog output
  }
  else if(clk == LOW && dt == HIGH && volume > 0)
  {
    volume--;
    Serial.print("Volume: "); //Print out the results
    Serial.println(volume); //Print the raw analog output
  }
  /*else if(sw == LOW) //Uncomment of you want to use mute, issues with my encoder prevented me from using it
  {
    Serial.print("Volume: "); //Print out the results
    Serial.println("Mute"); //Print the raw analog output  
  }*/
  
}

