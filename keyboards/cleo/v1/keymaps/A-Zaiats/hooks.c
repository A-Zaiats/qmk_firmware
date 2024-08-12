#include "../hooks_base.c"

void keyboard_post_init_user(void) {
    rgblight_sethsv(HSV_BLUE);
}

void housekeeping_task_user() {
    hooks_housekeeping_task_user();
}

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv(HSV_YELLOW);
    } else {
        rgblight_sethsv(HSV_BLUE);
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_SEMICOLON: // letter O on the Colemak layout.
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif
