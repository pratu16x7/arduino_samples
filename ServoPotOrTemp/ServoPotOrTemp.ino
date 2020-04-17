#include <Servo.h>

Servo myServo;

int const lightPin = A0; // Replace light with pot and use!
int lightVal;
int angle;

void setup(){
  myServo.attach(9);
  Serial.begin(9600);
}

void loop(){
  
  lightVal = analogRead(lightPin);
  angle = map(lightVal, 0, 1023, 0, 179);
  Serial.print("\n lightVal: ");
  Serial.print(lightVal);
  Serial.print("\t angle: ");
  Serial.print(angle);
  
  myServo.write(angle);
  delay(15);
  
}
