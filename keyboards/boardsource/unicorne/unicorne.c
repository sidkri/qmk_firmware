// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include <qp.h>

#include "quantum.h"
#include "lib/oled.h"
#include "oled/ocean_dream.h"
#include "oled/luna.h"
#include "oled/oled_setup.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

/////////////////////////////
//////// OLED STUFF /////////
/////////////////////////////
void oled_render_layer_state(void) {
    oled_set_cursor(0, 0);
    oled_write_ln_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("BASE "), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("ARROW"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("NUMS "), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("SYMS "), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("CTRL "), false);
            break;
    }
    oled_write_ln_P(PSTR("-----"), false);
}

void oled_render_wpm(void) {
    oled_set_cursor(2, 7);
    char wpm[6];
    itoa(get_current_wpm(), wpm, 10);
    oled_write_ln(wpm, false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_wpm();
#ifdef LUNA_ENABLE
        render_luna(0,13);
#endif
    } else {
#ifdef OCEAN_DREAM_ENABLE
        render_stars();
#endif
    }
    return false;
}
#endif

/////////////////////////////
///// PROCESS KEYS //////////
/////////////////////////////
void rgb_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
// Calms the ocean dream animation
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
#ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
#endif
#ifdef LUNA_ENABLE
            // Luna
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
#endif
            break;
        case KC_SPC:
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
#endif
            break;
    }
    return true;
}


/////////////////////////////
////// REBOOT HANDLER ///////
/////////////////////////////
void oled_render_boot(bool bootloader) {
    oled_clear();
    oled_set_cursor(0, 4);
    if (bootloader) {
        oled_write_P(PSTR("BOOT"), false);
    } else {
        oled_write_P(PSTR("REBOOT"), false);
    }
    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}