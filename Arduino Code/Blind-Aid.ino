#include <SoftwareSerial.h>

int i, k, l, m;
uint8_t dat[458] = { 0 };
unsigned long v, t, avg, sum, count;
SoftwareSerial mySerial(11, 10); // RX, TX

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop()
{
  //figure out where the start of the first contiguous batch of data is
  for (k = 7; k < 9; k++) {
    //if the sensor is providing data
    if (mySerial.available() >= 458) {
      for (m = 0; m < 458; m++) {
      dat[m] = mySerial.read();
    }
    for (i = 0; i < 229; i++) {
      //these are the conditions for the start of a batch
      if (dat[i] == 0x57 && dat[i + 1] == 0x01 && dat[i + 2] == 0xFF && dat[i + 3] == 0) {
        //print out time
        t = ((dat[i + 7] * 255 + dat[i + 6]) * 255 + dat[i + 5]) * 255 + dat[i + 4];
        Serial.print("Time = ");
        Serial.print(t);
        //find avg distance out of 64 data points
        for (l = 0; l < 64; l++) {
          //if signal strength is 0, move onto next data point
          if (dat[i + 13 + (6 * l)] + dat[i + 14 + (6 * l)] * 255 == 0) {
            continue;
          }
          //if signal strength is not 0 add to sum
          else {
            count++;
            sum += ((dat[i + 11 + (6 * l)] * 255 + dat[i + 10 + (6 * l)]) * 255 + dat[i + 9 + (6 * l)]);
          }
        }
        avg = sum / count;
        Serial.print(" Average Distance = ");
        Serial.println(avg);
        if (avg <= 500) {
          v = 0;
        }
        else if (avg > 500 && avg <= 2000) {
          v = 5;
        }
        else if (avg > 1500 && avg <= 3000) {
          v = 4;
        }
        else if (avg > 3000 && avg <= 4500) {
          v = 3;
        }
        else if (avg > 4500 && avg <= 6000) {
          v = 2;
        }
        else if (avg > 6000 && avg <= 7500) {
          v = 1;
        }
        else {
          v = 0;
        }
        //decide which motor to give voltage to based on sensor number
        switch (k) {
          case 7:
            switch (v) {
              case 0:
                analogWrite(k, 0);
                break;
              case 1:
                analogWrite(k, 51);
                break;
              case 2:
                analogWrite(k, 102);
                break;
              case 3:
                analogWrite(k, 153);
                break;
              case 4:
                analogWrite(k, 204);
                break;
              case 5:
                analogWrite(k, 255);
                break;
            }
            break;
          case 8:
            switch (v) {
              case 0:
                analogWrite(k, 0);
                break;
              case 1:
                analogWrite(k, 51);
                break;
              case 2:
                analogWrite(k, 102);
                break;
              case 3:
                analogWrite(k, 153);
                break;
              case 4:
                analogWrite(k, 204);
                break;
              case 5:
                analogWrite(k, 255);
                break;
            }
            break;
          }
          //found the contiguous batch of data, break out and look for the next sensor data
          break;
        }
      }
    }
  }
}
