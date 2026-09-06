#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Default / Media
    [0] = LAYOUT(
        MO(8),   KC_NO,   KC_MUTE,   // GP0 (Fn/Layer Picker), Empty, GP12 (Encoder Press)
        KC_MPRV, KC_MNXT, KC_MPLY,   // GP1, GP2, GP3
        KC_C,    KC_V,    KC_Z,      // GP4, GP5, GP6
        KC_ENT,  KC_BSPC, KC_SPC     // GP7, GP8, GP9
    ),

    // Layer 8: Fn Picker (Active ONLY while holding GP0)
    // Tapping any key immediately locks into that layer profile
    [8] = LAYOUT(
        KC_TRNS, KC_NO,   KC_TRNS,   // GP0 is held
        TO(0),   TO(1),   TO(2),     // Keys 2, 3, 4 select Layers 0, 1, 2
        TO(3),   TO(4),   TO(5),     // Keys 5, 6, 7 select Layers 3, 4, 5
        TO(6),   TO(7),   KC_NO      // Keys 8, 9 select Layers 6, 7
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [8] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif

// Visual RGB feedback per active layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);

    for (uint8_t i = led_min; i < led_max; i++) {
        switch (current_layer) {
            case 0: rgb_matrix_set_color(i, 0, 180, 255); break; // Cyan (Base)
            case 1: rgb_matrix_set_color(i, 0, 255, 60);  break; // Green (Productivity)
            case 2: rgb_matrix_set_color(i, 255, 0, 180); break; // Magenta (Design)
            case 8: rgb_matrix_set_color(i, 255, 140, 0); break; // Amber (Fn Menu Active)
            default: rgb_matrix_set_color(i, 120, 120, 120); break;
        }
    }
    return false;
}