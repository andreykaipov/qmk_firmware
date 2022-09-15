#include QMK_KEYBOARD_H

enum layers {
    _COLEMAQ,
    _QWERTY,
    _LOWER,
    _RAISE
};

#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________COLEMAQ_L1________________       KC_SCLN, KC_W,    KC_F,    KC_P,    KC_B
#define _________________COLEMAQ_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________COLEMAQ_L3________________       KC_X,    KC_C,    KC_D,    KC_K,    KC_Z
#define _________________COLEMAQ_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_Q
#define _________________COLEMAQ_R2________________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAQ_R3________________       KC_V,    KC_H,    KC_SLSH, KC_DOT,  KC_COMM

#define LAYOUT_80_with_macro_wrapper(...) LAYOUT_80_with_macro(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_80_with_macro_wrapper(
    KC_MUTE,                    KC_ESC,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  KC_DEL,        KC_INS,
    KC_A,         KC_F2,        KC_B,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_NO,KC_BSPC, KC_HOME,
    KC_F3,        KC_F4,        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS,       KC_END,
    KC_F5,        KC_F6,        KC_CAPS, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,          KC_ENT,        KC_PGUP,
    TO(_COLEMAQ), TO(_QWERTY),  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,          KC_RSFT, KC_UP,         TG(_COLEMAQ),
    TO(_COLEMAQ), TO(_QWERTY),  KC_LCTL, KC_LALT, KC_LGUI, MO(1),   KC_SPC,  KC_SPC,           MO(1),   KC_SPC,  KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN,       KC_RGHT
  ),
  [_COLEMAQ] = LAYOUT_80_with_macro_wrapper(

    KC_MUTE,               KC_ESC,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  KC_DEL,        KC_INS,
    KC_F1,   KC_F2,        KC_GRV,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_NO,KC_BSPC, KC_HOME,
    KC_F3,   KC_F4,        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS,       KC_END,
    KC_F5,   KC_F6,        KC_CAPS, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,          KC_ENT,        KC_PGUP,
    TO(_QWERTY), TO(_COLEMAQ),  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,          KC_RSFT, KC_UP,         KC_PGDN,
    TO(_COLEMAQ), TO(_QWERTY),  KC_LCTL, KC_LALT, KC_LGUI, MO(1),   KC_SPC,  KC_SPC,           MO(1),   KC_SPC,  KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN,       KC_RGHT
  ),
  [_RAISE] = LAYOUT_80_with_macro_wrapper(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_HUI, RGB_HUD, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
    RGB_SAI, RGB_SAD, RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_VAI, RGB_VAD, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
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
