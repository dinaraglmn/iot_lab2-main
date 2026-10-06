
#include <Arduino.h>

const int LIGHT = 33;
bool alertActive = false;
unsigned long lastRead = 0;

void setup() {
  Serial.begin(115200);
}


void loop() {
  unsigned long now = millis();
  if (now - lastRead >= 300) {
    lastRead = now;
    int value = analogRead(LIGHT);

    if (value > 3000 && !alertActive) {
      alertActive = true;
      Serial.println("ALERT=1");
    } else if (value < 2500 && alertActive) {
      alertActive = false;
      Serial.println("ALERT=0");
    }
  }
}