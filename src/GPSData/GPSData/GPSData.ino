int gpsInput = 13;
int gpsOutput = 12;
int gpsData = 0;

void setup() {
  Serial.begin(9600);
  // RX beim GPS
  pinMode(gpsOutput, OUTPUT);
  // TX beim GPS
  pinMode(gpsInput, INPUT);
}

void loop() {
  Serial.println(digitalRead(gpsInput));
}
