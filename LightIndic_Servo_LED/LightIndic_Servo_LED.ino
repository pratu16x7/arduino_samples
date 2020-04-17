#include <Servo.h>

Servo myServo;

int const lightPin = A0; // Replace light with pot and use!
int lightVal;
int angle;

void setup(){
  myServo.attach(9);
  Serial.begin(9600);
  
  for(int pinNo = 2; pinNo< 5; pinNo++){
    pinMode(pinNo,OUTPUT);
    digitalWrite(pinNo,LOW);
  }
}

void loop(){
  
  lightVal = analogRead(lightPin);
  angle = map(lightVal, 0, 1023, 0, 179);
  Serial.print("\n lightVal: ");
  Serial.print(lightVal);
  Serial.print("\t angle: ");
  Serial.print(angle);
  
  myServo.write(angle);
  
  if(lightVal < 200){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }else if(lightVal >= 600){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }else if(lightVal >= 400){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }else if(lightVal >= 200){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  
  delay(15);
  
}
