
#include "Arduino.h"
#include <Wire.h>

#include "Adafruit_GFX.h"

#ifndef bw_movingsign_h
#define bw_movingsign_h

// class bw_movingsign {
//  public:
//  bw_movingsign(void);
//};

class bw_movingsign : public Adafruit_GFX {
 public:

  bw_movingsign(int16_t w, int16_t h);
  
  void drawPixel(int16_t x, int16_t y, uint16_t color);

 private:
};

#endif // - ifndef bw_movingign_h
