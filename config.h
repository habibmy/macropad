#pragma once

#define VIAL_KEYBOARD_UID {0x8C, 0x4D, 0x1A, 0x55, 0x7E, 0x90, 0x12, 0x3F}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }

// 4 Rows x 3 Columns Direct Pin Matrix
// GP0 is the Layer Switch; GP1 through GP9 are the remaining 9 keys
#define DIRECT_PINS { \
    { GP0,  NO_PIN, GP12 }, \
    { GP1,  GP2,    GP3  }, \
    { GP4,  GP5,    GP6  }, \
    { GP7,  GP8,    GP9  }  \
}

// Rotary Encoder Pins
#define ENCODERS_PAD_A { GP10 }
#define ENCODERS_PAD_B { GP11 }
#define ENCODER_RESOLUTION 4

// Addressable WS2812 Strip (10 switch positions)
#define WS2812_DI_PIN GP13
#define DRIVER_LED_TOTAL 10
#define RGB_MATRIX_LED_COUNT DRIVER_LED_TOTAL
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180

#define ENABLE_RGB_MATRIX_SOLID_COLOR
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE