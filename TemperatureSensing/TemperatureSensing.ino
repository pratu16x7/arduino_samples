const int sensorPin = A0;
const float baselineTemp = 25.0;

void setup(){
  Serial.begin(9600); //open serial port
  
  for(int pinNo = 2; pinNo< 5; pinNo++){
    pinMode(pinNo,OUTPUT);
    digitalWrite(pinNo,LOW);
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
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
  delay(1);
  
}
