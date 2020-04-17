/*
Exact PixTrailer values!!!

ok ... so ... 20 changes in each led
 
 */
float radValue1 = 0;
double sinValue1 = 0;
int fadeValue1 = 0;

float radValue2 = 0;
double sinValue2 = 0;
int fadeValue2 = 0;

float radValue3 = 0;
double sinValue3 = 0;
int fadeValue3 = 0;

int fade1 = 11;    // LED connected to digital pin 9
int fade2 = 10;
int fade3 = 9;

void setup()  { 
  // nothing happens in setup 
  Serial.begin(9600);
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int val = 0 ; val <= 628; val +=16) { 
    
  
    radValue1 = val/100.0;
    sinValue1 = 0.5 + (0.5 * cos(radValue1));
    fadeValue1 = int(255 * sinValue1);
    analogWrite(fade1, fadeValue1); 
    
    radValue2 = ((val+224)%628)/100.0;
    sinValue2 = 0.5 + (0.5 * cos(radValue2));
    fadeValue2 = int(255 * sinValue2);
    analogWrite(fade2, fadeValue2); 
    
    radValue3 = ((val+448)%628)/100.0;
    sinValue3 = 0.5 + (0.5 * cos(radValue3));
    fadeValue3 = int(255 * sinValue3);
    analogWrite(fade3, fadeValue3); 
    
    // wait for 43 milliseconds to see the dimming effect    
    delay(25);
    
  } 
}


