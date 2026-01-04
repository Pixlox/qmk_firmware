#pragma once

/* I2C for OLED */
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP7

/* OLED Configuration */
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 0  // Never timeout

/* Encoder Configuration */
#define ENCODER_RESOLUTION 4

/* RGB Light Configuration */
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 128
#define RGBLIGHT_LIMIT_VAL 200
