#include <Arduino.h>

const int RED = 26, GREEN = 27, YELLOW = 12, BLUE = 14;
const int BUTTON = 25;

const int leds[] = {RED, GREEN, YELLOW, BLUE};  // fill order
const int ledCount = 4;

int counter = 0;
bool lastState = LOW;
unsigned long lastChange = 0;

void showPattern() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], i < counter ? HIGH : LOW);
  }
}


void setup() {
  Serial.begin(115200);
  for (int i = 0; i < ledCount; i++) pinMode(leds[i], OUTPUT);
  pinMode(BUTTON, INPUT_PULLDOWN);   // active high
  showPattern();
}

void loop() {
  bool state = digitalRead(BUTTON);

  // rising edge = one press
  if (state == HIGH && lastState == LOW && millis() - lastChange > 30) {
    lastChange = millis();
    counter = (counter + 1) % 5;     // 0,1,2,3,4,0,...
    showPattern();
    Serial.print("count=");
    Serial.println(counter);
  }
  lastState = state;
}