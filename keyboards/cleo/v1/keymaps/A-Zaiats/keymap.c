#include QMK_KEYBOARD_H
#include "hooks.c"

enum LAYER_NAMES {
    _BASE,
    _NUMBERS,
    _FUNCTIONS,
    _NAVIGATION,
    _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_GRAVE,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_MINUS, CTL_T(KC_A), ALT_T(KC_S), CMD_T(KC_D), SFT_T(KC_F), KC_G,        KC_H, SFT_T(KC_J), CMD_T(KC_K), ALT_T(KC_L), CTL_T(KC_SCLN), KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_EQUAL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        LT(_FUNCTIONS, KC_TAB), LT(_NUMBERS, KC_SPACE), LT(_NAVIGATION, KC_ESC), LT(_MOUSE, KC_ENT), KC_BSPC, KC_DEL
        //                                    `--------------------------'  `--------------------------'

        ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_KP_ASTERISK, KC_KP_SLASH,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6, KC_KP_PLUS, KC_KP_MINUS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 KC_BACKSLASH,    KC_1,    KC_2,    KC_3, KC_KP_DOT, KC_KP_EQUAL,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_0, XXXXXXX
        //                                    `--------------------------'  `--------------------------'
        ),

    [_FUNCTIONS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CW_TOGG,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
        //                                    `--------------------------'  `--------------------------'
        ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
        //                                    `--------------------------'  `--------------------------'
        ),

    [_MOUSE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_UP, KC_WH_R, KC_WH_U,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_BTN2, KC_BTN1, KC_BTN3,    XXXXXXX, XXXXXXX, XXXXXXX
        //                                    `--------------------------'  `--------------------------'
        ),
};

led_config_t g_led_config = {{// Key Matrix to LED Index
                              {19, 18, 13, 12, 5, 4},
                              {20, 17, 14, 11, 6, 3},
                              {21, 16, 15, 10, 7, 2},
                              {9, 8, 1},

                              {44, 43, 38, 37, 30, 29},
                              {45, 42, 39, 36, 31, 28},
                              {46, 41, 40, 35, 32, 27},
                              {34, 33, 26}

                             },
                             {
                                 // LED Index to Physical Position
                                 {100, 0},  {90, 21},  {90, 42},  {90, 63}, // Col 5
                                 {72, 63},  {72, 42},  {72, 21},  {81, 0},  // Col 4
                                 {62, 0},   {54, 21},  {54, 42},  {54, 63}, // Col 3
                                 {36, 63},  {36, 42},  {36, 21},            // Col 2
                                 {18, 21},  {18, 42},  {18, 63},            // Col 1
                                 {0, 63},   {0, 42},   {0, 21},             // Col 0
                                 {25, 30},  {25, 50},  {80, 50},  {80, 20}, // Underglow

                                 {115, 0},  {134, 21}, {134, 42}, {134, 63}, // Col 0
                                 {152, 63}, {152, 42}, {152, 21}, {145, 0},  // Col 1
                                 {160, 0},  {170, 21}, {170, 42}, {170, 63}, // Col 2
                                 {188, 63}, {188, 42}, {188, 21},            // Col 3
                                 {206, 21}, {206, 42}, {206, 63},            // Col 4
                                 {223, 63}, {223, 42}, {223, 21},            // Col 5
                                 {190, 30}, {190, 50}, {140, 50}, {140, 20}  // Underglow
                             },
                             {// LED Index to Flag
                              4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2}};
