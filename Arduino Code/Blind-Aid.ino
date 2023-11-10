/*!
 * @file  DFRobot_TFmini_test.ino
 * @brief This example use TFmini to measure distance
 * @n With initialization completed, we can get distance value and signal strength
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license  The MIT License (MIT)
 * @author  DFRobot
 * @version  V1.0
 * @date  2018-01-10
 */
#include <SoftwareSerial.h>

int i;
int dat[32] = { 0 };
unsigned long a, p, q, z, t;
SoftwareSerial mySerial(11, 10); // RX, TX

void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop()
{
  //if the sensor is providing data
  if (mySerial.available() >= 32) {
    //every 500 milliseconds save 2 batches of data into the array
    for (i = 0;i < 32;i++) {
      dat[i] = mySerial.read();
    }

    //figure out where the start of the first contiguous batch of data is
    for (i = 0;i < 16;i++) {
      //these are the conditions for the start of a batch
      if (dat[i] == 0x57 && dat[i + 1] == 0 && dat[i + 2] == 0xFFFFFFFF && dat[i + 3] == 0) {
        //these are the indexes with the data, check for data
        if (dat[i + 12] + dat[i + 13] * 255 == 0) {
          Serial.println("Out of range!");
          analogWrite(7, 0);
        } else {
          t = ((dat[i + 7] * 255 + dat[i + 6]) * 255 + dat[i + 5]) * 255 + dat[i + 4];
          Serial.print("Time = ");
          Serial.print(t);
          //if data print out data
          z = dat[i + 11];
          Serial.print(" Status = ");
          Serial.print(z);
          p = dat[i + 12] + dat[i + 13] * 255;
          Serial.print("  Strength = ");
          Serial.print(p);
          q = (dat[i + 10] * 255 + dat[i + 9]) * 255 + dat[i + 8];
          Serial.print("  Distance = ");
          Serial.print(q);
          Serial.println("mm");
          if (q <= 500) {
            analogWrite(7, 0);
          }
          else if (q > 8000) {
            analogWrite(7, 0);
          }
          else if (q > 500 && q <= 2000) {
            analogWrite(7, 255);
          }
          else if (q > 2000 && q <= 3500) {
            analogWrite(7, 204);
          }
          else if (q > 3500 && q <= 5000) {
            analogWrite(7, 153);
          }
          else if (q > 5000 && q <= 6500) {
            analogWrite(7, 102);
          }
          else if (q > 6500 && q <= 8000) {
            analogWrite(7, 51);
          }
        }
        //found the contiguous batch of data, break out and look for the next contiguous batch of data
        break;
      }
    }
  }
}