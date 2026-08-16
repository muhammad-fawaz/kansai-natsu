#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

bool initDisplay();
void showMessage(const char* message);

#endif