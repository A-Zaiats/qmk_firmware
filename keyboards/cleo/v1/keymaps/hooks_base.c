void hooks_housekeeping_task_user(void);


void hooks_housekeeping_task_user() {
    #ifdef RGB_MATRIX_ENABLE
        int val = rgb_matrix_get_val();
        if (val > RGB_MATRIX_MAXIMUM_BRIGHTNESS) {
            rgb_matrix_decrease_val();
        }
    #endif
}