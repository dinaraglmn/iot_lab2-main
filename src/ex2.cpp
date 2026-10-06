#include "Arduino.h"

const int LIGHT = 33;
unsigned long lastRun = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long now = millis();
  if (now - lastRun >= 1000) {
    lastRun = now;

    int mn = 4095, mx = 0;
    long sum = 0;
    for (int i = 0; i < 10; i++) {
      int v = analogRead(LIGHT);    // back-to-back, no delay
      if (v < mn) mn = v;
      if (v > mx) mx = v;
      sum += v;
    }
    int avg = sum / 10;

    Serial.print("min="); Serial.print(mn);
    Serial.print(" max="); Serial.print(mx);
    Serial.print(" avg="); Serial.println(avg);
  }
}