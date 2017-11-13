
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

  bw_movingsign(void);
  
  void movingsign_bootstrap(void);
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  void clear(void);
  void set_buffer_column(int x, byte c);
  void set_column_strobe_interval(int t);
  void set_autobufferupdate(byte t);
  void writeDisplay(void);
  
 private:
  byte drawbuffer[];
  byte displaybuffer[];
  byte autobufferupdate;
  int column_strobe_interval;
  void set_matrix_col_latch(int latch_num, int latch_bit, int latch_set);
  void set_matrix_bank_register(int bank,int reg_value);
  void enable_col(int colnum);
};

#endif // - ifndef bw_movingign_h
