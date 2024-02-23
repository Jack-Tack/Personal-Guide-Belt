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
int distance1, distance2, distance3, distance4, distance5, distance6, distance7, distance8;
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
  distance2 = 10;
  distance4 = 10;
  distance6 = 10;
  distance8 = 10;
}
void loop() {
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
  distance3 = duration2 * 0.034 / 2;
  distance5 = duration3 * 0.034 / 2;
  distance7 = duration4 * 0.034 / 2;
  if (abs(distance2 - distance1) > 400) {
    distance2 = distance2;
  }
  // Prints the distance on the Serial Monitor
  else {
    distance2 = distance1;
  }
  if (abs(distance4 - distance3) > 400) {
    distance4 = distance4;
  }
  // Prints the distance on the Serial Monitor
  else {
    distance4 = distance3;
  }
  if (abs(distance6 - distance5) > 400) {
    distance6 = distance6;
  }
  // Prints the distance on the Serial Monitor
  else {
    distance6 = distance5;
  }
  if (abs(distance8 - distance7) > 400) {
    distance8 = distance8;
  }
  // Prints the distance on the Serial Monitor
  else {
    distance8 = distance7;
  }
  Serial.println(millis());
  Serial.print("UltraSonic Distance 1: ");
  Serial.print(distance2);
  Serial.println(" cm");
  Serial.print("UltraSonic Distance 2: ");
  Serial.print(distance4);
  Serial.println(" cm");
  Serial.print("UltraSonic Distance 3: ");
  Serial.print(distance6);
  Serial.println(" cm");
  Serial.print("UltraSonic Distance 4: ");
  Serial.print(distance8);
  Serial.println(" cm");
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
  if (distance4 <= 50) {
    analogWrite(3, 0);
  }
  else if (distance4 > 50 && distance4 <= 100) {
    analogWrite(3, 255);
  }
  else if (distance4 > 100 && distance4 <= 150) {
    analogWrite(3, 204);
  }
  else if (distance4 > 150 && distance4 <= 200) {
    analogWrite(3, 153);
  }
  else if (distance4 > 200 && distance4 <= 250) {
    analogWrite(3, 102);
  }
  else if (distance4 > 250 && distance4 <= 300) {
    analogWrite(3, 51);
  }
  else if (distance4 > 300) {
    analogWrite(3, 0);
  }
  if (distance6 <= 50) {
    analogWrite(12, 0);
  }
  else if (distance6 > 50 && distance6 <= 100) {
    analogWrite(12, 255);
  }
  else if (distance6 > 100 && distance6 <= 150) {
    analogWrite(12, 204);
  }
  else if (distance6 > 150 && distance6 <= 200) {
    analogWrite(12, 153);
  }
  else if (distance6 > 200 && distance6 <= 250) {
    analogWrite(12, 102);
  }
  else if (distance6 > 250 && distance6 <= 300) {
    analogWrite(12, 51);
  }
  else if (distance2 > 300) {
    analogWrite(12, 0);
  }
  if (distance8 <= 50) {
    analogWrite(13, 0);
  }
  else if (distance8 > 50 && distance8 <= 100) {
    analogWrite(13, 255);
  }
  else if (distance8 > 100 && distance8 <= 150) {
    analogWrite(13, 204);
  }
  else if (distance8 > 150 && distance8 <= 200) {
    analogWrite(13, 153);
  }
  else if (distance8 > 200 && distance8 <= 250) {
    analogWrite(13, 102);
  }
  else if (distance8 > 250 && distance8 <= 300) {
    analogWrite(13, 51);
  }
  else if (distance8 > 300) {
    analogWrite(13, 0);
  }
}
