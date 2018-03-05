#include <NMEAGPS.h>
#include <SoftwareSerial.h> 

int gpsInput = 13;
int gpsOutput = 12;
int gpsData = 0;

SoftwareSerial serial(gpsInput, gpsOutput);

void setup() {
  Serial.begin(9600);
  serial.begin(9600);
  // RX beim GPS
  pinMode(gpsOutput, OUTPUT);
  // TX beim GPS
  pinMode(gpsInput, INPUT);
}

void loop() {
  /*
  while (gps.available(serial)) {
    fix = gps.read();

    if (fix.valid.status) {
      Serial.println("Status");
      Serial.println(fix.valid.status);
    } else Serial.println("Invalid status");
    
    if (fix.valid.time) {
      Serial.println("Time");
      Serial.println(fix.valid.time);
    } else Serial.println("Invalid Time");
    
    if (fix.valid.location) {
      Serial.println("Location");
      Serial.println(fix.valid.location);
    } else Serial.println("Invalid location");
  }*/
 
  if (serial.available())
    Serial.println(serial.read());
  else
    Serial.println("Serial not available!");
}
