int switchState = 0;

void setup(){
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,INPUT);
}

void loop(){
  switchState = digitalRead(2);
  
  if (switchState == LOW) {
    //button not pressed
    digitalWrite(3, HIGH); //green one
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);
    
    for (int i = 1; i < 4; i++){
      
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    delay(250);
    }
    
    digitalWrite(4, LOW);
    for(int j = 1; j < 4; j++){
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(5, LOW);
      delay(100);
    }
    
    for(int k = 1; k < 3; k++){
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(4, LOW);
      delay(100);
    }
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    delay(250);
    
  }
}
