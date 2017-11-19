
# gfx_mvmessage_interface_test

Basic test of adaptation for using Moving Message sign with Adafruit GFX
library.

## Usage

1. Have `bw_movingsign.cpp` and `bw_movingsign.h` in same directory as your sketch.

2. Include `bw_movingsign.h` along with `Adafruit_GFX`, `MsTimer2` and `Wire` libraries:

    #include <Wire.h>
    #include <MsTimer2.h>
    #include "Adafruit_GFX.h"
    #include "bw_movingsign.h"

3. Create a new `bw_movingsign` object:

    bwms = bw_movingsign();

The `bw_movingsign` object is programmable with the [Adafruit GFX library](https://learn.adafruit.com/adafruit-gfx-graphics-library):

    https://learn.adafruit.com/adafruit-gfx-graphics-library
