#include <SoftwareSerial.h>

int i, l, m;
int k = 2;
uint8_t dat[800] = { 0 };
unsigned long v1, v2, v3, v4, t, avg1, sum1, count1, avg2, sum2, count2, avg3, count3, sum3, avg4, sum4, count4;
SoftwareSerial mySerial(11, 10); // RX, TX

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop()
{
  //figure out where the start of the first contiguous batch of data is
  Reading:
  //if the sensor is providing data
  if (mySerial.available() >= 800) {
    for (m = 0; m < 800; m++) {
      dat[m] = mySerial.read();
  }
    
  for (i = 0; i < 400; i++) {
    //these are the conditions for the start of a batch
    if (dat[i] == 0x57 && dat[i + 1] == 0x01 && dat[i + 2] == 0xff && dat[i + 3] == 0) {
      //print out time
      t = ((dat[i + 7] * 255 + dat[i + 6]) * 255 + dat[i + 5]) * 255 + dat[i + 4];
      Serial.print("Time = ");
      Serial.print(t);
      sum1 = 0;
      count1 = 0;
      avg1 = 0;
      sum2 = 0;
      count2 = 0;
      avg2 = 0;
      sum3 = 0;
      count3 = 0;
      avg3 = 0;
      sum4 = 0;
      count4 = 0;
      avg4 = 0;
      //find avg distance of all 4 quadrants (bl - 1, br - 2, tl - 3, tr - 4)
      for (l = 0; l < 64; l++) {
        switch (l) {
          case 0:
          case 1:
          case 2:
          case 3:
          case 8:
          case 9:
          case 10:
          case 11:
          case 16:
          case 17:
          case 18:
          case 19:
          case 24:
          case 25:
          case 26:
          case 27:
            //if signal strength is 0, move onto next data point
            if (dat[i + 13 + (6 * l)] + dat[i + 14 + (6 * l)] * 255 == 0) {
              continue;
            }
            //if signal strength is not 0 add to sum
            else {
              count1++;
              sum1 += ((dat[i + 11 + (6 * l)] * 255 + dat[i + 10 + (6 * l)]) * 255 + dat[i + 9 + (6 * l)]);
            }
            break;
          case 4:
          case 5:
          case 6:
          case 7:
          case 12:
          case 13:
          case 14:
          case 15:
          case 20:
          case 21:
          case 22:
          case 23:
          case 28:
          case 29:
          case 30:
          case 31:
            //if signal strength is 0, move onto next data point
            if (dat[i + 13 + (6 * l)] + dat[i + 14 + (6 * l)] * 255 == 0) {
              continue;
            }
            //if signal strength is not 0 add to sum
            else {
              count2++;
              sum2 += ((dat[i + 11 + (6 * l)] * 255 + dat[i + 10 + (6 * l)]) * 255 + dat[i + 9 + (6 * l)]);
            }
            break;
          case 32:
          case 33:
          case 34:
          case 35:
          case 40:
          case 41:
          case 42:
          case 43:
          case 48:
          case 49:
          case 50:
          case 51:
          case 56:
          case 57:
          case 58:
          case 59:
            //if signal strength is 0, move onto next data point
            if (dat[i + 13 + (6 * l)] + dat[i + 14 + (6 * l)] * 255 == 0) {
              continue;
            }
            //if signal strength is not 0 add to sum
            else {
              count3++;
              sum3 += ((dat[i + 11 + (6 * l)] * 255 + dat[i + 10 + (6 * l)]) * 255 + dat[i + 9 + (6 * l)]);
            }
            break;
          case 36:
          case 37:
          case 38:
          case 39:
          case 44:
          case 45:
          case 46:
          case 47:
          case 52:
          case 53:
          case 54:
          case 55:
          case 60:
          case 61:
          case 62:
          case 63:
            //if signal strength is 0, move onto next data point
            if (dat[i + 13 + (6 * l)] + dat[i + 14 + (6 * l)] * 255 == 0) {
              continue;
            }
            //if signal strength is not 0 add to sum
            else {
              count4++;
              sum4 += ((dat[i + 11 + (6 * l)] * 255 + dat[i + 10 + (6 * l)]) * 255 + dat[i + 9 + (6 * l)]);
            }
            break;
        }
      }
      avg1 = sum1 / count1;
      avg1 = avg1 / 1000;
      avg2 = sum2 / count2;
      avg2 = avg2 / 1000;
      avg3 = sum3 / count3;
      avg3 = avg3 / 1000;
      avg4 = sum4 / count4;
      avg4 = avg4 / 1000;
      Serial.print(" Average Distance Quadrant 1 = ");
      Serial.print(avg1);
      Serial.print("mm");
      Serial.print(" Average Distance Quadrant 2 = ");
      Serial.print(avg2);
      Serial.print("mm");
      Serial.print(" Average Distance Quadrant 3 = ");
      Serial.print(avg3);
      Serial.print("mm");
      Serial.print(" Average Distance Quadrant 4 = ");
      Serial.print(avg4);
      Serial.println("mm");
      if (avg1 <= 500) {
        v1 = 0;
      }
      else if (avg1 > 500 && avg1 <= 2000) {
        v1 = 5;
      }
      else if (avg1 > 2000 && avg1 <= 3500) {
        v1 = 4;
      }
      else if (avg1 > 3500 && avg1 <= 5000) {
        v1 = 3;
      }
      else if (avg1 > 5000 && avg1 <= 6500) {
        v1 = 2;
      }
      else if (avg1 > 6500 && avg1 <= 8000) {
        v1 = 1;
      }
      else {
        v1 = 0;
      }
      if (avg2 <= 500) {
        v2 = 0;
      }
      else if (avg2 > 500 && avg2 <= 2000) {
        v2 = 5;
      }
      else if (avg2 > 2000 && avg2 <= 3500) {
        v2 = 4;
      }
      else if (avg2 > 3500 && avg2 <= 5000) {
        v2 = 3;
      }
      else if (avg2 > 5000 && avg2 <= 6500) {
        v2 = 2;
      }
      else if (avg2 > 6500 && avg2 <= 8000) {
        v2 = 1;
      }
      else {
        v2 = 0;
      }
      if (avg3 <= 500) {
        v3 = 0;
      }
      else if (avg3 > 500 && avg3 <= 2000) {
        v3 = 5;
      }
      else if (avg3 > 2000 && avg3 <= 3500) {
        v3 = 4;
      }
      else if (avg3 > 3500 && avg3 <= 5000) {
        v3 = 3;
      }
      else if (avg3 > 5000 && avg3 <= 6500) {
        v3 = 2;
      }
      else if (avg3 > 6500 && avg3 <= 8000) {
        v3 = 1;
      }
      else {
        v3 = 0;
      }
      if (avg4 <= 500) {
        v4 = 0;
      }
      else if (avg4 > 500 && avg4 <= 2000) {
        v4 = 5;
      }
      else if (avg4 > 2000 && avg4 <= 3500) {
        v4 = 4;
      }
      else if (avg4 > 3500 && avg4 <= 5000) {
        v4 = 3;
      }
      else if (avg4 > 5000 && avg4 <= 6500) {
        v4 = 2;
      }
      else if (avg4 > 6500 && avg4 <= 8000) {
        v4 = 1;
      }
      else {
        v4 = 0;
      }
      //decide which motor to give voltage to based on sensor and quadrant number
      switch (k) {
        case 2:
          switch (v1) {
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
          switch (v2) {
            case 0:
              analogWrite(k + 1, 0);
              break;
            case 1:
              analogWrite(k + 1, 51);
              break;
            case 2:
              analogWrite(k + 1, 102);
              break;
            case 3:
              analogWrite(k + 1, 153);
              break;
            case 4:
              analogWrite(k + 1, 204);
              break;
            case 5:
              analogWrite(k + 1, 255);
              break;
          }
          switch (v3) {
            case 0:
              analogWrite(k + 2, 0);
              break;
            case 1:
              analogWrite(k + 2, 51);
              break;
            case 2:
              analogWrite(k + 2, 102);
              break;
            case 3:
              analogWrite(k + 2, 153);
              break;
            case 4:
              analogWrite(k + 2, 204);
              break;
            case 5:
              analogWrite(k + 2, 255);
              break;
          }
          switch (v4) {
            case 0:
              analogWrite(k + 3, 0);
              break;
            case 1:
              analogWrite(k + 3, 51);
              break;
            case 2:
              analogWrite(k + 3, 102);
              break;
            case 3:
              analogWrite(k + 3, 153);
              break;
            case 4:
              analogWrite(k + 3, 204);
              break;
            case 5:
              analogWrite(k + 3, 255);
              break;
          }
          break;
        case 6:
          switch (v1) {
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
          switch (v2) {
            case 0:
              analogWrite(k + 1, 0);
              break;
            case 1:
              analogWrite(k + 1, 51);
              break;
            case 2:
              analogWrite(k + 1, 102);
              break;
            case 3:
              analogWrite(k + 1, 153);
              break;
            case 4:
              analogWrite(k + 1, 204);
              break;
            case 5:
              analogWrite(k + 1, 255);
              break;
          }
          switch (v3) {
            case 0:
              analogWrite(k + 2, 0);
              break;
            case 1:
              analogWrite(k + 2, 51);
              break;
            case 2:
              analogWrite(k + 2, 102);
              break;
            case 3:
              analogWrite(k + 2, 153);
              break;
            case 4:
              analogWrite(k + 2, 204);
              break;
            case 5:
              analogWrite(k + 2, 255);
              break;
          }
          switch (v4) {
            case 0:
              analogWrite(k + 3, 0);
              break;
            case 1:
              analogWrite(k + 3, 51);
              break;
            case 2:
              analogWrite(k + 3, 102);
              break;
            case 3:
              analogWrite(k + 3, 153);
              break;
            case 4:
              analogWrite(k + 3, 204);
              break;
            case 5:
              analogWrite(k + 3, 255);
              break;
          }
          break;
        }
        //found the contiguous batch of data, go back to Reading to get the next sensor's data
        k = k + 4;
        if (k == 10) {
          k = 2;
          Serial.println("Resetting");
          goto Reading;
        }
        else {
          Serial.println("Switching");
          goto Reading;
        }
      }
    }
  }
}
