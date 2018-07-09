#include <SoftwareSerial.h> 

int sensorValue = 0;

int RED_LED = 9;
int GREEN_LED = 10;
int BLUE_LED = 11;

int gpsRX = 4;
int gpsTX = 5;
int gpsData = 0;

int btRX = 2;
int btTX = 3;

SoftwareSerial gpsSerial(gpsRX, gpsTX);
SoftwareSerial btSerial(btRX, btTX);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gpsSerial.begin(9600);
  btSerial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);

  if(sensorValue <= 341){ // LOW
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
  if(sensorValue >= 341 && sensorValue <= 682){ //MEDIUM
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }

  if(sensorValue >= 682){ // HIGH
    digitalWrite(RED_LED, LOW );
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);    
  }
  if(gpsSerial.available()){
      while (gpsSerial.available() > 0){
    // get the byte data from the GPS
    byte gpsData = gpsSerial.read();
    btSerial.write(gpsData);
    Serial.write(gpsData);
  }
  } else {
    Serial.println("Couldn't recieve any data");
    btSerial.println("Couldn't recieve GPS Data");
  }

  
    if (btSerial.available())
  {
    Serial.write(btSerial.read());
  }


  
}
