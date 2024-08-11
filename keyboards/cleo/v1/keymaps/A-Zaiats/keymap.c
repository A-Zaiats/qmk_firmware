#include "../keymaps_base.c"

// void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//    debug_keyboard=true;
//    debug_mouse=true;
// }

#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif