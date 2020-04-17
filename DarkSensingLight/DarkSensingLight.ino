//Dark-sensing light

const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;


const int greenSensorPin = A2;
const int blueSensorPin = A1;
const int redSensorPin = A0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop(){
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  
  Serial.print("\nRaw sensor values\t Red:");
  Serial.print(redSensorValue);
  Serial.print("\t Green:");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue:");
  Serial.print(blueSensorValue);

  if(redSensorValue >= 400){
    redValue = 0;
  }
  else if(redSensorValue >= 250){
    redValue = 1;
  }
  else{
    redValue = 254 - redSensorValue;
  }
  
  
  
  if(greenSensorValue >= 400){
    greenValue = 0;
  }
  else if(greenSensorValue >= 250){
    greenValue = 1;
  }
  else{
    greenValue = 254 - greenSensorValue;
  }
  
  
  
  if(blueSensorValue >= 400){
    blueValue = 0;
  }
  else if(blueSensorValue >= 250){
    blueValue = 1;
  }
  else{
    blueValue = 254 - blueSensorValue;
  }
  
 
  Serial.print("\nMapped sensor values\t Red:");
  Serial.print(redValue);
  Serial.print("\t Green:");
  Serial.print(greenValue);
  Serial.print("\t Blue:");
  Serial.print(blueValue);
  
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);

}
