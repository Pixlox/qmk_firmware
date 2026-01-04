#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,
    _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer
     * ┌─────┬─────┬─────┬─────┬─────┐
     * │  1  │  2  │  3  │  4  │ ENC │
     * └─────┴─────┴─────┴─────┴─────┘
     */
    [_BASE] = LAYOUT(
        KC_F13,  KC_F14,  KC_F15,  KC_F16,  MO(_FUNC)
    ),

    /*
     * Func Layer
     * ┌─────┬─────┬─────┬─────┬─────┐
     * │RGBTG│RGB+ │RGB- │BOOT │     │
     * └─────┴─────┴─────┴─────┴─────┘
     */
    [_FUNC] = LAYOUT(
        RM_TOGG, RM_NEXT, RM_PREV, QK_BOOT, _______
    )
};

// Encoder handling
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (layer_state_is(_FUNC)) {
            // In func layer, adjust led brightness
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        } else {
            // In base layer, volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}
#endif
