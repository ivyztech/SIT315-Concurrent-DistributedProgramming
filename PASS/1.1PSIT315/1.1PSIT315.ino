// Defining pins
const int irSensorPin = 2;
const int greenLEDPin = 8;
const int blueLEDPin = 7;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  
  digitalWrite(blueLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  // If the sensor detects an object
  if (sensorValue == LOW) {
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(blueLEDPin, LOW);
    Serial.println("OBJECT DETECTED");
  } //If sensor does not detect an object
  else {
    digitalWrite(blueLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
    Serial.println("NO OBJECT");
  }

  delay(500);
}
