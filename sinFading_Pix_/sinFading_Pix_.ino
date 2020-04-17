/*
Exact PixTrailer values!!!
 
 */
float radValue = 0;
double sinValue = 0;
int fadeValue = 0;

int fade1 = 9;    // LED connected to digital pin 9
int fade2 = 10;
int fade3 = 11;

void setup()  { 
  // nothing happens in setup 
  Serial.begin(9600);
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int val = 0 ; val <= 314; val +=16) { 
    if(val == 0){
      delay(40);
    }
    
    radValue = val/100.0;
    sinValue = sin(radValue);
    fadeValue = int(255 * sinValue);
    
    Serial.print("\tval");
    Serial.print(val);
    Serial.print(" rad:");
    Serial.print(radValue);
    Serial.print("\t sin:");
    Serial.print(sinValue);
    Serial.print("\t fade:");
    Serial.println(fadeValue);
    
    analogWrite(fade1, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(43);
    
  } 
}


