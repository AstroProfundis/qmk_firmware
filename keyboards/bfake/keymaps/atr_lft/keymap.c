/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Base Layer / Default Layer
    * ,-----------------------------------------------------------.
    * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
    * |-----------------------------------------------------------|
    * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
    * |-----------------------------------------------------------|
    * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
    * |-----------------------------------------------------------|
    * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Sft|Up|Ctl|
    * |-----------------------------------------------------------|
    * |Ctrl|Gui |Alt |       Space            |Fn0|DEL|Lt |Dn |Rt |
    * `-----------------------------------------------------------'
    */
    [0] = LAYOUT_all(
        F(0),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,
        KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_UP,  KC_RCTL,
        KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                         MO(1),  KC_DEL, KC_LEFT,KC_DOWN,KC_RGHT
    ),
    /* Keymap _FL: Function Layer
    * ,-----------------------------------------------------------.
    * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |
    * |-----------------------------------------------------------|
    * |     |M1 |CUp|M2 |   |   |   |   |Ins|   |PSr|SLK|Pus|     |
    * |-----------------------------------------------------------|
    * |      |CLt|CDn|CRt|   |   |   |   |   |   |   |   |        |
    * |-----------------------------------------------------------|
    * |        |Fn1|   |   |   |   |   |Mut|Vo+|Vo-|Play| |PgUp|  |
    * |-----------------------------------------------------------|
    * |    |Menu|    |                      |   |   |Home|PgDn|End|
    * `-----------------------------------------------------------'
    */
    [1] = LAYOUT_all(
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,
        _______,KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,_______,_______,KC_INS, _______,KC_PSCR,KC_SLCK,KC_PAUS,_______,
        _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
        _______,_______,_______,_______,_______,_______,_______,KC_MUTE,KC_VOLU,KC_VOLD,KC_MPLY,_______,KC_PGUP,_______,
        _______,KC_MENU,_______,                _______,                        _______,_______,KC_HOME,KC_PGDN,KC_END
    ),
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
      shift_esc_shift_mask = IS_COMMAND();
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
