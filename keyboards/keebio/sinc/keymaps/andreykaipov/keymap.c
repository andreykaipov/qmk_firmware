#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK_QIX,
    _ISRT,
    _RAISE,
    _NOTHING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_80_with_macro(
    KC_MUTE,            KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,          KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                               KC_DEL, KC_INS,
    KC_F1,   KC_F2,     KC_GRV,       KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,                           KC_DEL,KC_BSPC, DF(_COLEMAK_QIX),
    RESET,   KC_F4,     KC_TAB,  /**/ KC_Q, KC_W, KC_E, KC_R, KC_T, /**/                 /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,    /**/  KC_LBRC,KC_RBRC,         KC_BSLS, DF(_ISRT),
    KC_F5,   KC_F6,     KC_CAPS, /**/ KC_A, KC_S, KC_D, KC_F, KC_G, /**/                 /**/ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, /**/  KC_QUOT,                  KC_ENT, DF(_QWERTY),
    KC_F7,   KC_F8,     KC_LSFT, /**/ KC_Z, KC_X, KC_C, KC_V, KC_B, /**/                 /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, /**/  KC_RSFT,                   KC_UP, KC_PGDN,
    KC_F9,   KC_F10,    KC_LCTL, KC_LALT, KC_LGUI, MO(_RAISE), KC_1,KC_X,              KC_A,KC_SPC,KC_RALT,KC_RCTL,    KC_RGUI,                         KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_COLEMAK_QIX] = LAYOUT_80_with_macro(
    KC_MUTE,            KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,          KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                               KC_DEL, KC_INS,
    KC_F1,   KC_F2,     KC_GRV,       KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_LBRC,                           KC_DEL,KC_BSPC, DF(_COLEMAK_QIX),
    RESET,   KC_F4,     KC_TAB,  /**/ KC_SCLN, KC_L, KC_C, KC_M, KC_K, /**/              /**/ KC_J, KC_F, KC_U,    KC_Y,   KC_Q,    /**/  KC_MINS,KC_RBRC,         KC_BSLS, DF(_ISRT),
    KC_F5,   KC_F6,     KC_CAPS, /**/ KC_A,    KC_R, KC_S, KC_T, KC_G, /**/              /**/ KC_P, KC_N, KC_E,    KC_I,   KC_O,    /**/  KC_QUOT,                  KC_ENT, DF(_QWERTY),
    KC_F7,   KC_F8,     KC_LSFT, /**/ KC_X,    KC_W, KC_D, KC_V, KC_Z, /**/              /**/ KC_B, KC_H, KC_SLSH, KC_DOT, KC_COMM, /**/  KC_RSFT,                   KC_UP, KC_PGDN,
    KC_F9,   KC_F10,    KC_LCTL, KC_LALT, KC_LGUI, MO(_RAISE),   KC_2,KC_Y,            KC_B,KC_SPC,KC_RALT,KC_RCTL,    KC_RGUI,                         KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_ISRT] = LAYOUT_80_with_macro(
    KC_MUTE,            KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,          KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                               KC_DEL, KC_INS,
    KC_F1,   KC_F2,     KC_GRV,       KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_LBRC,                           KC_DEL,KC_BSPC, DF(_COLEMAK_QIX),
    RESET,   KC_F4,     KC_TAB,  /**/ KC_Y, KC_C, KC_L, KC_M, KC_K, /**/                 /**/ KC_Z, KC_F, KC_U,    KC_COMM, KC_QUOT, /**/ KC_MINS,KC_RBRC,         KC_BSLS, DF(_ISRT),
    KC_F5,   KC_F6,     KC_CAPS, /**/ KC_I, KC_S, KC_R, KC_T, KC_G, /**/                 /**/ KC_P, KC_N, KC_E,    KC_A,    KC_O,    /**/ KC_SCLN,                  KC_ENT, DF(_QWERTY),
    KC_F7,   KC_F8,     KC_LSFT, /**/ KC_V, KC_W, KC_D, KC_J, KC_Q, /**/                 /**/ KC_B, KC_H, KC_SLSH, KC_DOT,  KC_X,    /**/ KC_RSFT,                   KC_UP, KC_PGDN,
    KC_F9,   KC_F10,    KC_LCTL, KC_LALT, KC_LGUI, MO(_RAISE),   KC_3,KC_Z,            KC_C,KC_SPC,KC_RALT,KC_RCTL,    KC_RGUI,                         KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_RAISE] = LAYOUT_80_with_macro(
    _______,               _______,       _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,                            _______, _______,
    RGB_HUI,   RGB_HUD,    KC_GESC,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     _______,_______, _______,
    RGB_SAI,   RGB_SAD,    RGB_TOG,  /**/ RGB_MOD, _______, KC_UP,   _______, _______, /**/          /**/ _______, _______, _______, _______, _______, /**/  _______,_______,         _______, _______,
    RGB_VAI,   RGB_VAD,    _______,  /**/ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, /**/          /**/ _______, _______, _______, _______, _______, /**/  _______,                 _______, _______,
    _______,   _______,    _______,  /**/ _______, _______, _______, _______, _______, /**/          /**/ _______, _______, _______, _______, _______, /**/  _______,                 _______, _______,
    _______,   _______,    _______,_______,_______,_______,           _______,_______,               _______,_______,       _______,_______,_______,                         _______, _______, _______
  ),
//  [4] = LAYOUT_80_with_macro(
//    _______,               _______,       _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,                            _______, _______,
//    _______,   _______,    _______,       _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,                    _______,_______, _______,
//    _______,   _______,    _______,  /**/ _______, _______, _______, _______, _______, /**/          /**/ _______, _______, _______, _______, _______, /**/  _______,_______,         _______, _______,
//    _______,   _______,    _______,  /**/ _______, _______, _______, _______, _______, /**/          /**/ _______, _______, _______, _______, _______, /**/  _______,                 _______, _______,
//    _______,   _______,    _______,  /**/ _______, _______, _______, _______, _______, /**/          /**/ _______, _______, _______, _______, _______, /**/  _______,                 _______, _______,
//    _______,   _______,    _______,_______,_______,_______,           _______,_______,               _______,_______,       _______,_______,_______,                         _______, _______, _______
//  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
