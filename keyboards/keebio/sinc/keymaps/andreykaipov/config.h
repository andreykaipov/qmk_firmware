//

#pragma once

#define TAPPING_TERM 210
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define SHIFT_NORM(kc1, kc2) \
if (record->event.pressed) { \
  timer_timeout(); \
  if (lshift || rshift) { \
    register_code(KC_LSFT); \
    unregister_code(kc2); \
    register_code(kc2); \
  } else { \
    unregister_code(KC_LSFT); \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
} \
return false;

/*
#define RGBLIGHT_SPLIT
#include QMK_KEYBOARD_H

extern bool rshiftp;
extern uint16_t lshift_timer;
extern uint16_t rshift_timer;

extern uint8_t prev_indx;
extern uint16_t prev_kcs[6];
void add_to_prev(uint16_t kc);
void unreg_prev(void);

extern bool esct;

void timer_timeout(void);
void timer_timeout_keymap(void);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Normal shift status
#define SHIFT_NORM(kc1, kc2) \
if (record->event.pressed) { \
  timer_timeout(); \
  if (lshift || rshift) { \
    register_code(KC_LSFT); \
    unregister_code(kc2); \
    register_code(kc2); \
    add_to_prev(kc2); \
  } else { \
    unregister_code(KC_LSFT); \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
} \
return false;

// Inverted shift status
#define SHIFT_SWITCH(kc1, kc2) \
if (record->event.pressed) { \
  timer_timeout(); \
  if (lshift || rshift) { \
    unregister_code(KC_LSFT); \
    unregister_code(kc2); \
    register_code(kc2); \
    add_to_prev(kc2); \
  } else { \
    register_code(KC_LSFT); \
    unregister_code(kc1); \
    register_code(kc1); \
    add_to_prev(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  unreg_prev(); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;

// Always shifted
#define SHIFT_ALL(kc1, kc2) \
if (record->event.pressed) { \
  timer_timeout(); \
  register_code(KC_LSFT); \
  if (lshift || rshift) { \
    unregister_code(kc2); \
    register_code(kc2); \
    add_to_prev(kc2); \
  } else { \
    unregister_code(kc1); \
    register_code(kc1); \
    add_to_prev(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  unreg_prev(); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;

// Never shifted
#define SHIFT_NO(kc1, kc2) \
if (record->event.pressed) { \
  timer_timeout(); \
  unregister_code(KC_LSFT); \
  if (lshift || rshift) { \
    unregister_code(kc2); \
    register_code(kc2); \
    add_to_prev(kc2); \
  } else { \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  unreg_prev(); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;

// Always AltGr
#define SHIFT_ALGR(kc1, kc2) \
if (record->event.pressed) { \
  timer_timeout(); \
  unregister_code(KC_LSFT); \
  register_code(KC_ALGR); \
  if (lshift || rshift) { \
    unregister_code(kc2); \
    register_code(kc2); \
    unregister_code(kc2); \
    register_code(KC_LSFT); \
  } else { \
    unregister_code(kc1); \
    register_code(kc1); \
    unregister_code(kc1); \
  } \
  unregister_code(KC_ALGR); \
} \
return false;

// Different keycode when Ctrl is pressed
#define CTRL(kc1, kc2) \
if(record->event.pressed) { \
  timer_timeout(); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
  if (keyboard_report->mods & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL))){ \
    register_code(kc2); \
  } else { \
    register_code(kc1); \
  } \
} else { \
    unregister_code(kc1); \
    unregister_code(kc2); \
} \
return false;

// Template for keys on deadkey layer (mostly Umlaute)
#define UML(kc) \
if(record->event.pressed) { \
  timer_timeout(); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
  register_code(kc); \
  unregister_code(kc); \
  layer_off(_DEADKEY); \
} \
return false;
*/
