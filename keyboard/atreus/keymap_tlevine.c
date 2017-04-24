#include "keymap_common.h"

#define KA KC_A
#define KB KC_B
#define KC KC_C
#define KD KC_D
#define KE KC_E
#define KF KC_F
#define KG KC_G
#define KH KC_H
#define KI KC_I
#define KJ KC_J
#define KK KC_K
#define KL KC_L
#define KM KC_M
#define KN KC_N
#define KO KC_O
#define KP KC_P
#define KQ KC_Q
#define KR KC_R
#define KS KC_S
#define KT KC_T
#define KU KC_U
#define KV KC_V
#define KW KC_W
#define KX KC_X
#define KY KC_Y
#define KZ KC_Z

#define N1 KC_1
#define N2 KC_2
#define N3 KC_3
#define N4 KC_4
#define N5 KC_5
#define N6 KC_6
#define N7 KC_7
#define N8 KC_8
#define N9 KC_9
#define N0 KC_0

#define NORT KC_UP
#define WEST KC_LEFT
#define EAST KC_RIGHT
#define SOUT KC_DOWN
#define PGUP KC_PGUP
#define PGDN KC_PGDOWN
#define HOME KC_HOME
#define END  KC_END

#define DEL  KC_DELETE
#define ENT  KC_ENTER
#define ESC  KC_ESCAPE
#define BSPC KC_BSPACE
#define SPC  KC_SPACE
#define TAB  KC_TAB
#define DEL  KC_DELETE
#define MINS KC_MINUS
#define EQL  KC_EQUAL
#define RBRC KC_RBRACKET
#define LBRC KC_LBRACKET
#define COMM KC_COMMA
#define DOT  KC_DOT
#define BSLS KC_BSLASH
#define SLSH KC_SLASH
#define SCLN KC_SCOLON
#define GRV  KC_GRAVE
#define QUOT KC_QUOTE

#define CTL1 KC_LCTRL
#define SFT1 KC_LSHIFT
#define ALT1 KC_LALT
#define GUI1 KC_LGUI
#define CTL2 KC_RCTRL
#define SFT2 KC_RSHIFT
#define ALT2 KC_RALT
#define GUI2 KC_RGUI
#define CAPS KC_CAPSLOCK

#define K_SL KC_KP_SLASH
#define K_EN KC_KP_ENTER

// Compose key
#define COM1 KC_PSCREEN
#define COM2 KC_SCROLLLOCK
#define COM3 KC_PAUSE

// Programmable
#define OPT1 KC_KP_1
#define OPT2 KC_KP_2
#define OPT3 KC_KP_3
#define OPT4 KC_KP_4

// Internal
#define TT   KC_TRANSPARENT
#define RST  KC_FN2
#define FUNC KC_FN1
#define BOOT KC_FN0

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(BOOTLOADER), // Bootloader
  [1] = ACTION_LAYER_MOMENTARY(1),   // Function overlay
  [2] = ACTION_LAYER_MOMENTARY(2),   // Reset overlay
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Letters

    ' , . p y f g c r l
    a o e u i d h t n s
    ; q j k x b m w v z

  */
  KEYMAP(KQ,   KW,   KE,   KR,   KT,               KY,   KU,   KI,   KO,   KP,    \
         KA,   KS,   KD,   KF,   KG,               KH,   KJ,   KK,   KL,   SCLN,  \
         KZ,   KX,   KC,   KV,   KB,               KN,   KM,   COMM, DOT,  SLSH,  \
         ESC,  K_SL, GUI1, SFT2, BSPC, CTL1, ALT1, SPC,  FUNC, QUOT, COM1, K_EN), \

  /* 1: Punctuation
 
    `     comp3  up    del   [         ]     opt3  opt4  /     =
    pgup  left   down  right home      1     2     3     4     5
    pgdn  opt1   opt2  caps  end       6     7     8     9     0

  */
  KEYMAP(GRV,  COM3, NORT, DEL,  MINS,             EQL,  OPT3, OPT4, LBRC, RBRC,  \
         PGUP, WEST, SOUT, EAST, HOME,             N1,   N2,   N3,   N4,   N5,    \
         PGDN, OPT1, OPT2, CAPS, END,              N6,   N7,   N8,   N9,   N0,    \
         TT,   RST,  GUI2, SFT2, BSPC, CTL2, ALT2, TAB,  TT,   BSLS, COM2, ENT),  \

  /* 2: Reset
   
    Same as above, except that there is a reset button

  */
  KEYMAP(TT,   TT,   TT,   TT,   BOOT,             TT,   TT,   TT,   TT,   TT,    \
         TT,   TT,   TT,   TT,   TT,               TT,   TT,   TT,   TT,   TT,    \
         TT,   TT,   TT,   TT,   TT,               TT,   TT,   TT,   TT,   TT,    \
         TT,   TT,   TT,   TT,   TT,   TT,   TT,   TT,   TT,   TT,   TT,   TT)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
