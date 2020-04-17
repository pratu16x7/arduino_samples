#include <Servo.h>  

#define  servomaxx   180   // max degree servo horizontal (x) can turn
#define  servomaxy   180   // max degree servo vertical (y) can turn
#define  screenmaxx   640   // max screen horizontal (x)resolution
#define  screenmaxy   480    // max screen vertical (y) resolution
#define  servocenterx   90  // center po#define  of x servo
#define  servocentery   90  // center po#define  of y servo
#define  servopinx   9   // digital pin for servo x
#define  servopiny   10  // digital servo for pin y
#define  baudrate 57600  // com port speed. Must match your C++ setting
#define distancex 1.5  // x servo rotation steps
#define distancey 1.5  // y servo rotation steps

#define  redpin     2   // digital pin for redLed
#define  greenpin   3   // digital pin for greenLed

int shortx = 0;
int shorty = 0;
int valx = 0;       // store x data from serial port
int valy = 0;       // store y data from serial port
int posx = 0;
int posy = 0;
int incx = 30;  // significant increments of horizontal (x) camera movement
int incy = 30;  // significant increments of vertical (y) camera movement

Servo servox;
Servo servoy;

void setup() {

  Serial.begin(baudrate);        // connect to the serial port
  Serial.println("Starting Cam-servo Face tracker");

  pinMode(servopinx,OUTPUT);    // declare the LED's pin as output
  pinMode(servopiny,OUTPUT);    // declare the LED's pin as output
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  digitalWrite(redpin, HIGH);
  digitalWrite(greenpin, LOW);

  servoy.attach(servopiny); 
  servox.attach(servopinx); 

  // center servos

  servox.write(servocenterx); 
  delay(200);
  servoy.write(servocentery); 
  delay(200);
}

void loop () {
  while(Serial.available() <=0)
  {
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
  } // wait for incoming serial data
  
  
  if (Serial.available() >= 4)  // wait for 4 bytes. 
  { 
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, HIGH);
  
    shortx = Serial.read();
    shorty = Serial.read();
    
    valx = shortx * 3;
    valy = shorty * 3;
    Serial.print("\n valx:");
    Serial.print(valx);
    Serial.print("\t valy:");
    Serial.print(valy);

    // read last servos positions
    posx = servox.read(); 
    posy = servoy.read();

    //Find out if the X component of the face is to the left of the middle of the screen.
    if(valx < (screenmaxx/2 - incx)){
      if( posx >= 10 )
        posx -= distancex; //Update the pan position variable to move the servo to the left.
    }
    //Find out if the X component of the face is to the right of the middle of the screen.
    else if(valx > (screenmaxx/2 + incx)){
      if(posx <= 170)
        posx += distancex; //Update the pan position variable to move the servo to the right.
    }
    
    //
    //Find out if the Y component of the face is below the middle of the screen.
    if(valy < (screenmaxy/2 - incy)){
      if(posy >= 10) 
        posy += distancey; //If it is below the middle of the screen, update the tilt position variable to lower the tilt servo.
    }
    //Find out if the Y component of the face is above the middle of the screen.
    else if(valy > (screenmaxy/2 + incy)){
      if(posy <= 170)
        posy -= distancey; //Update the tilt position variable to raise the tilt servo.
    }

    // Servos will rotate accordingly 
    servox.write(posx);
    servoy.write(posy);
    
    delay(20);

  }else{
    delay(100);
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
  
  }  
}

