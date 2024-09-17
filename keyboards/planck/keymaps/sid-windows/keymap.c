#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
    #include "muse.h"
#endif
//#include "eeprom.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

enum planck_keycodes {
  ST_MACRO_0,
  ST_MACRO_1
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
      /*
      1,                        2,                      3,                      4,                      5,                      6,
                                7,                      8,                      9,                      10,                     11,                     12
      */
      LT(5,KC_TAB),             KC_Q,                   KC_W,                   KC_E,                   KC_R,                   KC_T,
                                KC_Y,                   KC_U,                   KC_I,                   KC_O,                   KC_P,                   LCTL(KC_BSPACE),
      KC_LCTRL,                 LT(6,KC_A),             LT(1,KC_S),             KC_D,                   KC_F,                   KC_G,
                                KC_H,                   KC_J,                   KC_K,                   KC_L,                   KC_SCOLON,              KC_QUOTE,
      KC_LSHIFT,                LT(4,KC_Z),             KC_X,                   KC_C,                   KC_V,                   KC_B,
                                KC_N,                   KC_M,                   KC_COMMA,               KC_DOT,                 KC_SLASH,               KC_ENTER,
      MT(MOD_HYPR, KC_ESCAPE),  MO(4),                  KC_AT,                  KC_LGUI,                KC_LALT,                KC_BSPACE,
                                KC_SPACE,               RAISE,                  MO(4),                  KC_EQUAL,               KC_PLUS,                KC_MINUS),

  [_LOWER] = LAYOUT_planck_grid(
      KC_TRANSPARENT,           KC_TRANSPARENT,         LALT(KC_LEFT),          KC_UP,                  LALT(KC_RIGHT),         KC_HOME,        
                                KC_TRANSPARENT,         LALT(KC_LEFT),          KC_UP,                  LALT(KC_RIGHT),         KC_TRANSPARENT,         KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_DOWN,                KC_RIGHT,               KC_END,
                                LGUI(KC_LEFT),          KC_LEFT,                KC_DOWN,                KC_RIGHT,               LGUI(KC_RIGHT),         KC_TAB,
      KC_TRANSPARENT,           KC_TRANSPARENT,         LALT(LSFT(KC_LEFT)),    KC_END,                 LALT(LSFT(KC_RIGHT)),   KC_TRANSPARENT,    
                                LGUI(LSFT(KC_LEFT)),    LALT(LSFT(KC_LEFT)),    KC_END,                 LALT(LSFT(KC_RIGHT)),   LGUI(LSFT(KC_RIGHT)),   KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_MS_ACCEL0,           KC_MS_ACCEL1,           KC_MS_ACCEL2),

  [_RAISE] = LAYOUT_planck_grid(
      KC_ESCAPE,                KC_TRANSPARENT,         KC_TILD,                KC_LCBR,                KC_RCBR,                KC_CIRC,
                                KC_GRAVE,               KC_KP_PLUS,             KC_MINUS,               KC_EQUAL,               KC_PERC,                KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_LPRN,                KC_RPRN,                KC_PIPE,
                                KC_AMPR,                KC_DLR,                 KC_AT,                  KC_HASH,                KC_EXLM,                KC_DELETE,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_PIPE,                KC_LBRACKET,            KC_RBRACKET,            KC_GRAVE,
                                KC_ASTR,                KC_KP_SLASH,            KC_KP_ASTERISK,         KC_BSLASH,              KC_TRANSPARENT,         KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT),

  [_ADJUST] = LAYOUT_planck_grid(
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_AUDIO_MUTE,          KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         AU_ON,                  AU_OFF,                 AU_TOG,                 KC_TRANSPARENT,
                                KC_AUDIO_VOL_UP,        KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         MU_ON,                  MU_OFF,                 MU_TOG,                 MU_MOD,
                                KC_AUDIO_VOL_DOWN,      KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         RESET),

  [_LAYER4] = LAYOUT_planck_grid(
      KC_TRANSPARENT,           KC_PERC,                KC_7,                   KC_8,                   KC_9,                   KC_EQUAL,
                                KC_EQUAL,               KC_7,                   KC_8,                   KC_9,                   KC_PERC,                KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_KP_MINUS,            KC_4,                   KC_5,                   KC_6,                   KC_KP_PLUS,
                                KC_KP_PLUS,             KC_4,                   KC_5,                   KC_6,                   KC_KP_MINUS,            KC_PIPE,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_1,                   KC_2,                   KC_3,                   KC_KP_ASTERISK,
                                KC_KP_ASTERISK,         KC_1,                   KC_2,                   KC_3,                   KC_KP_DOT,              KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_0,                   KC_KP_DOT,              KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_0,                   KC_TRANSPARENT,         KC_SLASH,               RCTL_T(KC_KP_PLUS),     KC_BSPACE),

  [_LAYER5] = LAYOUT_planck_grid(
      KC_TRANSPARENT,           LALT(KC_LEFT),          KC_UP,                  LALT(KC_RIGHT),         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_MS_WH_UP,            KC_MS_BTN1,             KC_MS_UP,               KC_MS_BTN2,             KC_TRANSPARENT,         KC_TRANSPARENT,
      LGUI(KC_LEFT),            KC_LEFT,                KC_DOWN,                KC_RIGHT,               LGUI(KC_RIGHT),         KC_TRANSPARENT,
                                KC_MS_WH_DOWN,          KC_MS_LEFT,             KC_MS_DOWN,             KC_MS_RIGHT,            KC_TRANSPARENT,         KC_TRANSPARENT,
      LGUI(LSFT(KC_LEFT)),      LALT(LSFT(KC_LEFT)),    KC_END,                 LALT(LSFT(KC_RIGHT)),   LGUI(LSFT(KC_RIGHT)),   KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_MS_WH_LEFT,          KC_MS_BTN3,             KC_MS_WH_RIGHT,         KC_TRANSPARENT,         KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_HOME,                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_MS_ACCEL0,           KC_MS_ACCEL1,           KC_MS_ACCEL2),

  [_LAYER6] = LAYOUT_planck_grid(
      KC_TRANSPARENT,           KC_TRANSPARENT,         LCTL(KC_F4),            LALT(KC_F12),           KC_TRANSPARENT,         LSFT(KC_F4),
                                LCTL(LSFT(KC_LEFT)),    LCTL(KC_LEFT),          KC_UP,                  LCTL(KC_RIGHT),         LCTL(LSFT(KC_RIGHT)),   KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         LCTL(KC_MINUS),         KC_F11,                 KC_F10,                 LALT(KC_F11),
                                KC_HOME,                KC_LEFT,                KC_DOWN,                KC_RIGHT,               KC_END,                 KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         ST_MACRO_1,             LSFT(KC_F12),           ST_MACRO_0,             KC_F5,
                                LSFT(KC_HOME),          LCTL(LSFT(KC_LEFT)),    KC_END,                 LCTL(LSFT(KC_RIGHT)),   LSFT(KC_END),           KC_TRANSPARENT,
      KC_TRANSPARENT,           KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_RSHIFT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_T)));

            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_LBRACKET)) SS_DELAY(100) SS_TAP(X_S));

            }
            break;
    }
    return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
