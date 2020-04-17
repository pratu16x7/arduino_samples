/*
 The 17 increment is perfect for Pix!!!
 
 */


int ledPin1 = 9;    // LED connected to digital pin 9
int ledPin2 = 11;
int ledPin3 = 10;

int fadeValue2 = 0;
int fadeValue3 = 0;

void setup()  { 
  // nothing happens in setup 
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=17) { 
    // sets the value (range from 0 to 255):
    
    fadeValue2 = (fadeValue + 85) % 255;
    fadeValue3 = (fadeValue + 170) % 255;
    
    analogWrite(ledPin1, fadeValue); 
    analogWrite(ledPin2, fadeValue2);
    analogWrite(ledPin3, fadeValue3);   
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=17) { 
    // sets the value (range from 0 to 255):
    fadeValue2 = (fadeValue - 85);
    if(fadeValue2 < 0){
      fadeValue2 += 255;
    }
    fadeValue3 = (fadeValue - 170);
    if(fadeValue3 < 0){
      fadeValue3 += 255;
    }
    
    analogWrite(ledPin1, fadeValue); 
    analogWrite(ledPin2, fadeValue2);
    analogWrite(ledPin3, fadeValue3);          
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
}


