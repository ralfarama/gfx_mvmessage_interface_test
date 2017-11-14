

#include <Wire.h>
#include <MsTimer2.h>

#include "Adafruit_GFX.h"
#include "bw_movingsign.h"

bw_movingsign bwms = bw_movingsign();

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

void timer_handler() {
  bwms.writeDisplay();  
}

void setup() {
  // put your setup code here, to run once:
  bwms.movingsign_bootstrap();
  MsTimer2::set(10,timer_handler);
  MsTimer2::start();
}

int LED_ON = 1;
int c;
int iters = 0;

void old_bitpattern_loop() {
  if ( iters % 2 == 0 ) {
    int qq = (millis() >> 8) & 0x7f;
    for ( c = 0; c < 8; c++ ) {
      bwms.set_buffer_column(c,0);
    }
    for ( c = 8; c < 60; c++ ) {
      bwms.set_buffer_column(c,qq+c);
    }
    bwms.drawBitmap(0, 0, smile_bmp, 8, 8, 1);
  }
  iters = iters + 1;
  bwms.writeDisplay();
//  delay(50);
}

void adafruit_matrix8x8_test_loop() {
  bwms.clear();
  bwms.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
//  bwms.writeDisplay();
//  delay(500);

  bwms.clear();
  bwms.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
//  bwms.writeDisplay();
//  delay(500);

  bwms.clear();
  bwms.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
//  bwms.writeDisplay();
//  delay(500);

  bwms.clear();      // clear display
  bwms.drawPixel(0, 0, LED_ON);  
//  bwms.writeDisplay();  // write the changes we just made to the display
//  delay(500);

  bwms.clear();
  bwms.drawLine(0,0, 7,7, LED_ON);
//  bwms.writeDisplay();  // write the changes we just made to the display
//  delay(500);

  bwms.clear();
  bwms.drawRect(0,0, 8,8, LED_ON);
  bwms.fillRect(2,2, 4,4, LED_ON);
//  bwms.writeDisplay();  // write the changes we just made to the display
//  delay(500);

  bwms.clear();
  bwms.drawCircle(3,3, 3, LED_ON);
//  bwms.writeDisplay();  // write the changes we just made to the display
//  delay(500);

  bwms.setTextSize(1);
  bwms.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  bwms.setTextColor(LED_ON);
  // start with static text display
  bwms.clear();
  bwms.setCursor(0,0);
  bwms.print("1234567890Hello1234567890");
//  bwms.writeDisplay();
  delay(500);
  for (int8_t x=0; x>=-36; x--) {
    // bwms.set_autobufferupdate(0);
    bwms.clear();
    bwms.setCursor(x,0);
    bwms.print("Hellowacky");
    // bwms.writeDisplay();
    delay(100);
    //bwms.set_autobufferupdate(1);
  }
  bwms.setRotation(3);
  for (int8_t x=7; x>=-36; x--) {
    // bwms.set_autobufferupdate(0);
    bwms.clear();
    bwms.setCursor(x,0);
    bwms.print("World");
//    bwms.writeDisplay();
    // bwms.set_autobufferupdate(1);
    delay(100);
  }
  bwms.setRotation(0);  
}

void loop() {
  adafruit_matrix8x8_test_loop();
//  old_bitpattern_loop();
}

