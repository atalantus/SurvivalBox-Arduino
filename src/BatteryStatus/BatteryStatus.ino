int sensorValue = 0;

int RED_LED = 9;
int GREEN_LED = 10;
int BLUE_LED = 11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(11, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  if(sensorValue != 0){
    Serial.println(sensorValue);
  }

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
}
