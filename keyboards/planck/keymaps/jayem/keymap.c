/**
 * Build command from qmk_firmware/ directory:
 * $ make planck-rev4-jayem-dfu
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  LOWER,
  RAISE
};

#define JM_ESC MT(MOD_LGUI, KC_ESC)
#define JM_NAV LT(_NAV, KC_SPC)

// Tap Dance Declarations
// TODO: Square brace, angle brace, paren, single/double quote, back/forward slash, dash underscore
enum {
  SHIFT_CAP = 0,
  LEFT_HOME,
  DOWN_PGDN,
  UP_PGUP,
  RIGHT_END,
  CURLY_BRACE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |  Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |   (  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   \  | Ctrl |  Alt |  GUI | Lower|  NAV | Space| Raise|  GUI |  Alt | Ctrl |  `   |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = {
    {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
    {JM_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOT},
    {KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT },
    {KC_BSLASH, KC_LCTRL, KC_LALT, KC_LGUI, LOWER, JM_NAV, KC_SPC, RAISE, KC_RGUI, KC_RALT, KC_RCTRL, KC_GRAVE}
  },

  /* Dvorak
   * ,-----------------------------------------------------------------------------------.
   * |      |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | Lower|  NAV | Space| Raise|      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_DVORAK] = {
    {KC_TRNS, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_TRNS},
    {KC_TRNS, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH},
    {KC_TRNS, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_TRNS },
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOWER, JM_NAV, KC_SPC, RAISE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  /* Lower (Numeric Layer)
   * ,-----------------------------------------------------------------------------------.
   * | ⌘-` |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   #  |   A  |   B  |   C  |   D  |   E  |   F  | #### |   .  | #### |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |  Del |      |      |      |      | #### |
   * `-----------------------------------------------------------------------------------'
   */
   [_LOWER] = {
     {LGUI(KC_GRV), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS},
     {KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS},
     {KC_TRNS, KC_HASH, KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_NO, KC_DOT, KC_NO, KC_TRNS},
     {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
   },

  /* Raise (Symbol Layer)
   * ,-----------------------------------------------------------------------------------.
   * |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   =  |   +  |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   (  |   {  |   [  |   <  |   _  |   -  |   >  |   ]  |   }  |   )  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | Lower| Bksp | Space| Raise|      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
   [_RAISE] = {
     {KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS},
     {KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQUAL, KC_TRNS},
     {KC_TRNS, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, KC_UNDS, KC_MINUS, KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, KC_TRNS},
     {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPACE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
   },

  /* Navigation
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      | Home | PgUp | PgDn |  End |      |  Up  | Down | Left | Right|      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_NAV] = {
    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_NO, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO},
    {KC_LSHIFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, JM_NAV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
  },

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * | RESET|      |      |      |      |      |      |      |      |      |      | DEBUG|
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |Qwerty|      |      |      |      |      |      |      |      |      |      |Dvorak|
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |Mus On|      |      |      |      |      |      |      |      |      |      |MusOff|
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = {
    {RESET,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DEBUG},
    {QWERTY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DVORAK},
    {KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    {MU_ON,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MU_OFF}
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SHIFT_CAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
  [DOWN_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
  [UP_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
  [RIGHT_END] = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),
  [CURLY_BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
