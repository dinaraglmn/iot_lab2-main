#include <Arduino.h>

const int RED = 26, GREEN = 27, YELLOW = 12, BLUE = 14;

const int leds[] = {RED, GREEN, YELLOW, BLUE};
const int ledCount = 4;

// sequence: RED -> GREEN -> YELLOW -> BLUE -> YELLOW -> GREEN
const int seq[] = {RED, GREEN, YELLOW, BLUE, YELLOW, GREEN};
const char* names[] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};
const int seqLen = 6;

int step = 0;


void setup() {
  Serial.begin(115200);
  for (int i = 0; i < ledCount; i++) pinMode(leds[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < ledCount; i++) digitalWrite(leds[i], LOW);  // all off
  digitalWrite(seq[step], HIGH);                                  // one on

  Serial.print("chase=");
  Serial.println(names[step]);

  delay(150);                       // the only delay
  step = (step + 1) % seqLen;
}