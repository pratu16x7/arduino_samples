
#define  baudrate 9600

char whichLED = 'g';
int incomingByte = 0;

void setup() {

  Serial.begin(baudrate);        // connect to the serial port
  Serial.println("Starting Cam-servo Face tracker");

}

void loop() {
   //while(Serial.available() <=0); // wait for incoming serial data

   if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte*5, DEC);
    }

}
