

#include "Arduino.h"
#include <Wire.h>

#include "Adafruit_GFX.h"
#include "bw_movingsign.h"

bw_movingsign::bw_movingsign(int16_t w, int16_t h) : Adafruit_GFX(7, 60) {
}

void bw_movingsign::drawPixel(int16_t x, int16_t y, uint16_t color) {
}
