#include <SoftwareSerial.h>
// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
SoftwareSerial mySerial(11, 10); // RX, TX
// defines variables
long duration;
uint8_t dat[800] = { 0 };
unsigned long avg, sum, count;
int distance, distance2;
int i, l, m;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  mySerial.begin(9600); // Starts the serial communication for lidar sensors
  distance = 10;
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (abs(distance2 - distance) > 600) {
    distance2 = distance2;
  }
  // Prints the distance on the Serial Monitor
  else {
    distance2 = distance;
  }
  Serial.print("UltraSonic Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");
  if (mySerial.available() >= 800) {
    for (m = 0; m < 800; m++) {
      dat[m] = mySerial.read();
    }
  }
  for (i = 0; i < 400; i++) {
    //these are the conditions for the start of a batch
    if (dat[i] == 0x57 && dat[i + 1] == 0x01 && dat[i + 2] == 0xff && dat[i + 3] == 0) {
      count = 0;
      avg = 0;
      sum = 0;
      for (l = 0; l < 64; l++) {
        if (dat[i + 13 + (6 * l)] + dat[i + 14 + (6 * l)] * 255 == 0) {
          continue;
        }
        else {
          count++;
          sum += ((dat[i + 11 + (6 * l)] * 255 + dat[i + 10 + (6 * l)]) * 255 + dat[i + 9 + (6 * l)]);
        }
      }
      avg = sum / count;
      Serial.print("LIDAR Distance: ");
      Serial.print(avg);
      Serial.println(" mm");
    }
  }
  if (distance2 <= 50) {
    analogWrite(2, 0);
  }
  else if (distance2 > 50 && distance2 <= 100) {
    analogWrite(2, 255);
  }
  else if (distance2 > 100 && distance2 <= 150) {
    analogWrite(2, 204);
  }
  else if (distance2 > 150 && distance2 <= 200) {
    analogWrite(2, 153);
  }
  else if (distance2 > 200 && distance2 <= 250) {
    analogWrite(2, 102);
  }
  else if (distance2 > 250 && distance2 <= 300) {
    analogWrite(2, 51);
  }
  else if (distance2 > 300) {
    analogWrite(2, 0);
  }
  if (avg <= 500) {
    analogWrite(3, 0);
  }
  else if (avg > 500 && avg <= 1000) {
    analogWrite(3, 255);
  }
  else if (avg > 1000 && avg <= 1500) {
    analogWrite(3, 204);
  }
  else if (avg > 1500 && avg <= 2000) {
    analogWrite(3, 153);
  }
  else if (avg > 2000 && avg <= 2500) {
    analogWrite(3, 102);
  }
  else if (avg > 2500 && avg <= 3000) {
    analogWrite(3, 51);
  }
  else if (avg > 3000) {
    analogWrite(3, 0);
  }
}
