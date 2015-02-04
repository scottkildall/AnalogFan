/*
  Simple Motor to Analog Test
  by Scott Kildall
  
 */


int lightPin = 0;  //define a pin for Photo resistor
int analogIn;

// Analog intputs, from testing in seial monitor
int lightReading = 90;
int darkReading = 320;
int threshholdReading = 120;

int minMotor = 40;
int maxMotor = 255;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);  //Begin serial communcation
}

void loop()
{
    
   analogIn = (analogRead(lightPin));
   
   
   // trim min, max from input
   //Serial.println(analogIn);
   analogIn = max(analogIn, lightReading);
   analogIn = min(analogIn, darkReading);
   
   
   if( analogIn > threshholdReading ) {
     int motorVal = map(analogIn, lightReading, darkReading, minMotor, maxMotor);
     //Serial.println(motorVal);
     analogWrite(11,motorVal);   // turn the LED on (HIGH is the voltage level)                                             //you have  to divide the value. for example, 
   }                                           //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
  else {
     analogWrite(11,0); 
  }
  
}

