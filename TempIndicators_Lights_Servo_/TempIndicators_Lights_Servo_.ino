// Well... This is causing lights and Servo to misbehave

#include <Servo.h>

Servo myServo;

const float baselineTemp = 27.0;

int const tempPin = A0; 
int tempVal;
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
  
  tempVal = analogRead(tempPin);
  
    
    float voltage = (tempVal / 1024.0) * 5.0;
    float temperature = (voltage - .5) * 100;
  
    Serial.print("\n tempVal: ");
    Serial.print(tempVal);
    Serial.print(", Voltage: ");
    Serial.print(voltage);
    Serial.print(", Degrees C: ");
    Serial.print(temperature);
  
  if(temperature < baselineTemp){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }else if(temperature >= baselineTemp + 6){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }else if(temperature >= baselineTemp + 4){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }else if(temperature >= baselineTemp + 2){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  
  if ((tempVal >= 100)&&(tempVal <= 250)){
    angle = map(tempVal, 100, 250, 0, 179);
    Serial.print("\t angle: ");
    Serial.print(angle);
    myServo.write(angle);
  }
  
  delay(15);
  
}
