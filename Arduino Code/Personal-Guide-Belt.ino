// WiFi
#include "thingProperties.h"
// defines pins numbers
const int trigPin1 = 6;
const int echoPin1 = 7;
const int trigPin2 = 8;
const int echoPin2 = 9;
const int trigPin3 = 4;
const int echoPin3 = 5;
const int trigPin4 = 10;
const int echoPin4 = 11;
// defines variables
long duration1, duration2, duration3, duration4;
const int MAX_DISTANCE = 400;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin4, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin4, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200); // Starts the serial communication
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}

void loop() {
  ArduinoCloud.update();
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(25);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(25);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(25);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(25);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
  distance2 = duration2 * 0.034 / 2;
  distance3 = duration3 * 0.034 / 2;
  distance4 = duration4 * 0.034 / 2;
  if (distance1 > MAX_DISTANCE) {
    distance1 = MAX_DISTANCE;
  }
  if (distance2 > MAX_DISTANCE) {
    distance2 = MAX_DISTANCE;
  }
  if (distance3 > MAX_DISTANCE) {
    distance3 = MAX_DISTANCE;
  }
  if (distance4 > MAX_DISTANCE) {
    distance4 = MAX_DISTANCE;
  }
  Serial.println(millis());
  Serial.print("UltraSonic Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("UltraSonic Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  Serial.print("UltraSonic Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
  Serial.print("UltraSonic Distance 4: ");
  Serial.print(distance4);
  Serial.println(" cm");
  if (distance1 <= 50) {
    analogWrite(2, 0);
  }
  else if (distance1 > 50 && distance1 <= 100) {
    analogWrite(2, 255);
  }
  else if (distance1 > 100 && distance1 <= 150) {
    analogWrite(2, 204);
  }
  else if (distance1 > 150 && distance1 <= 200) {
    analogWrite(2, 153);
  }
  else if (distance1 > 200 && distance1 <= 250) {
    analogWrite(2, 102);
  }
  else if (distance1 > 250 && distance1 <= 300) {
    analogWrite(2, 51);
  }
  else if (distance1 > 300) {
    analogWrite(2, 0);
  }
  if (distance2 <= 50) {
    analogWrite(3, 0);
  }
  else if (distance2 > 50 && distance2 <= 100) {
    analogWrite(3, 255);
  }
  else if (distance2 > 100 && distance2 <= 150) {
    analogWrite(3, 204);
  }
  else if (distance2 > 150 && distance2 <= 200) {
    analogWrite(3, 153);
  }
  else if (distance2 > 200 && distance2 <= 250) {
    analogWrite(3, 102);
  }
  else if (distance2 > 250 && distance2 <= 300) {
    analogWrite(3, 51);
  }
  else if (distance2 > 300) {
    analogWrite(3, 0);
  }
  if (distance3 <= 50) {
    analogWrite(12, 0);
  }
  else if (distance3 > 50 && distance3 <= 100) {
    analogWrite(12, 255);
  }
  else if (distance3 > 100 && distance3 <= 150) {
    analogWrite(12, 204);
  }
  else if (distance3 > 150 && distance3 <= 200) {
    analogWrite(12, 153);
  }
  else if (distance3 > 200 && distance3 <= 250) {
    analogWrite(12, 102);
  }
  else if (distance3 > 250 && distance3 <= 300) {
    analogWrite(12, 51);
  }
  else if (distance3 > 300) {
    analogWrite(12, 0);
  }
  if (distance4 <= 50) {
    analogWrite(13, 0);
  }
  else if (distance4 > 50 && distance4 <= 100) {
    analogWrite(13, 255);
  }
  else if (distance4 > 100 && distance4 <= 150) {
    analogWrite(13, 204);
  }
  else if (distance4 > 150 && distance4 <= 200) {
    analogWrite(13, 153);
  }
  else if (distance4 > 200 && distance4 <= 250) {
    analogWrite(13, 102);
  }
  else if (distance4 > 250 && distance4 <= 300) {
    analogWrite(13, 51);
  }
  else if (distance4 > 300) {
    analogWrite(13, 0);
  }
}
