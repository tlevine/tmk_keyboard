#include "keymap_common.h"

// This is the softdvorak layout with some changes.
//
// The left gui, shift, ctrl and alt keys are switched
// for right gui, shift, ctrl and alt keys in
// the second layer,  that is, the arrows and function layer.
// This way, you can make these keys do different things
// depending on which layer you are on.
//
// A bunch of other things switched back to the common layout.
// For example, the FN4 key is removed, (I don't know what it did.)
// and the gui and shift keys are swapped, putting them
// in their common locations.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,     \
         // KC_MINS and KC_LBRC are inverse-dvorakized
         KC_SPC, KC_FN0, KC_QUOT, KC_LBRC, KC_ENT),                     \

  /* 1: fn with undvorak-ized punctuation
   *
   * In software Dvorak layout, the result should be this.
   *
   *  !    @     up     {    }        ||     pgup    7     8     9    *
   *  #  left   down  right  $        ||     pgdn    4     5     6    +
   *  [    ]      (     )    &        ||       `     1     2     3    \
   * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
   *
   */
  KEYMAP(SHIFT(KC_1), SHIFT(KC_2), KC_UP, SHIFT(KC_MINS), SHIFT(KC_EQUAL), \
         KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8), \
         SHIFT(KC_3), KC_LEFT, KC_DOWN, KC_RIGHT, SHIFT(KC_4), \
         KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_RBRC), \
         KC_MINS, KC_EQUAL, SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_GRAVE), \
         KC_GRAVE, KC_1, KC_2, KC_3, KC_BSLS,                       \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, \
         KC_LALT, KC_SPC, KC_FN0, KC_E, KC_0, KC_RBRC), \
  /* 2: arrows and function keys
   *
   * In software Dvorak layout, the result should be this.
   *
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   * mouse volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_NO, KC__VOLUP, KC_NO, KC_NO, KC_FN3, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         KC_NO, KC__VOLDOWN, KC_RGUI, KC_RSFT, KC_BSPC, KC_RCTL, KC_RALT, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENT)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
