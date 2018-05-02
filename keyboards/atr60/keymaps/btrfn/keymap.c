#include "atr60.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _RL 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |       Space            |Fn0|Lt |Dn |Up |Rt |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_BTRFN(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                         MO(_FL),KC_LEFT,KC_DOWN, KC_UP,  KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |
   * |-----------------------------------------------------------|
   * |     |M1 |CUp|M2 |   |   |   |   |Ins|   |PSr|SLK|Pus|Del  |
   * |-----------------------------------------------------------|
   * |      |CLt|CDn|CRt|   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |Fn1|   |   |   |   |   |Mut|Vo+|Vo-|Play|         |
   * |-----------------------------------------------------------|
   * |    |Menu|    |                     |   |Home|PgDn|PgUp|End|
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_BTRFN(
   KC_GRV, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,  KC_F12, _______, \
  _______, KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,_______,_______, KC_INS,_______,KC_PSCR,KC_SLCK,KC_PAUS, KC_DEL,  \
  _______, KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,_______,_______,_______,_______,_______,_______,         _______, \
  _______, MO(_RL),_______,_______,_______,_______,_______,KC_MUTE,KC_VOLU,KC_VOLD,KC_MPLY,                 _______, \
  _______, KC_MENU,_______,                 _______,                       _______,KC_HOME,KC_PGDN,KC_PGUP, KC_END),

  /* Keymap _RL: Function Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |  RESET|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |BLTG|   |   |   |   |   |         |
   * |-----------------------------------------------------------|
   * |    |    |    |                     |   |    |    |    |   |
   * `-----------------------------------------------------------'
   */
[_RL] = KEYMAP_BTRFN(
#ifdef RGBLIGHT_ENABLE
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, RESET ,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,  \
  _______,_______,_______,_______,_______,BL_TOGG,_______,_______,_______,_______,_______,                _______, \
  _______,_______,_______,                _______,                _______,_______,_______,_______,_______),
#else
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, RESET ,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                _______, \
  _______,_______,_______,                _______,                _______,_______,_______,_______,_______),
#endif
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
