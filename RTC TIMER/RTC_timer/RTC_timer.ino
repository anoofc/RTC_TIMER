#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

int Hour;
int Minute;

int flag = 0;

const int relay =  9;      // the number of the LED pin


long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  delay(3000); // wait for console opening

  rtc.begin();

}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    updateTime();
    checkTime();
    digitalWrite(relay, flag);
  }

  

}

void updateTime() {
  DateTime now = rtc.now();
  Hour = now.hour();
  Minute = now.minute();
  Serial.print(Hour);
  Serial.print(Minute);
  Serial.println();
}

void checkTime() {
  if (Hour > 17 && Hour < 23) {
    flag = 1;
  }
//  else if (Hour == 17 && Minute > 30) {
//    flag = 1;
//  }
  else {
    flag = 0;
  }
}
