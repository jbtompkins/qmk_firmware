#include QMK_KEYBOARD_H
#include "version.h"

#define DVRK 0 // default Dvorak layer
#define LOWR 1 // misc symbols, character navigation, media keys
#define RASE 2 // function keys, numpad, page navigation

enum custom_keycodes {
VRSN,
RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default Dvorak Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  | Bksp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  | TOG  |           | TOG  |   F  |   G  |   C  |   R  |   L  |   \    |
 * |--------+------+------+------+------+------| LOWR |           | RASE |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------| Caps |           |      |------+------+------+------+------+--------|
 * | LShift | SCLN |   Q  |   J  |   K  |   X  |  Lk  |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Grv  | LCtl | LAlt | LGUI | LOWR |                                       | RASE | RGUI | RAlt | RCtl |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  /   |   =  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 |LShift|Space |------|       |------|Enter |Space |
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DVRK] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LBRC,
  KC_TAB,          KC_QUOT,     KC_COMM,       KC_DOT,  KC_P,    KC_Y,    TG(LOWR),
  KC_LCTL,         KC_A,        KC_O,          KC_E,    KC_U,    KC_I,
  KC_LSFT,         KC_SCLN,     KC_Q,          KC_J,    KC_K,    KC_X,    KC_CAPS,
  KC_GRV,          KC_LCTL,     KC_LALT,       KC_LGUI, TT(LOWR),
                                                                  KC_TRNS, KC_TRNS,
                                                                           KC_HOME,
                                                         KC_LSFT,  KC_SPC, KC_END,
  // right hand
  KC_RBRC,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_BSPC,
  TG(RASE),     KC_F,    KC_G,    KC_C,    KC_R,              KC_L,           KC_BSLS,
  KC_D,         KC_H,    KC_T,    KC_N,    KC_S,              KC_MINS,
  KC_TRNS,      KC_B,    KC_M,    KC_W,    KC_V,              KC_Z,           KC_RSFT,
  TT(RASE),      KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS,
  KC_SLSH, KC_EQL,
  KC_PGUP,
  KC_PGDN, KC_ENT, KC_SPC
),
/* Keymap 1: Symbols, Character Navigation, Media Keys Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   Del  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    `    |      | MRWD |      | MFFD | VOLU |      |           |      |      |      |   ~  |   /  |   =  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | MPRV | MPLY | MNXT | VOLD |------|           |------|      | LEFT | DOWN |  UP  | RGHT |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LShift |      |      | MSTP |      | MUTE |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       | LCtl | LAlt | LGUI |      |                                       |      | RGUI | RAlt | RCtl |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LOWR] = LAYOUT_ergodox(
  // left hand
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
  KC_GRV,  KC_TRNS, KC_MRWD, KC_TRNS, KC_MFFD, KC_VOLU, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD,
  KC_LSFT, KC_TRNS, KC_TRNS, KC_MSTP, KC_TRNS, KC_MUTE, KC_TRNS,
  KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD, KC_SLSH, KC_EQL,  KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Function Keys, Numpad, Page Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F12   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   7  |   8  |   9  |   *  |      |           |      | MENU | PSCR | PAUS | INS  | SLCK |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   4  |   5  |   6  |   -  |------|           |------|      | HOME | PGDN | PGUP | END  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Version|      |   1  |   2  |   3  |   +  |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |   0  |   .  |   /  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  =   |   0  |------|       |------|      | BSPC |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RASE] = LAYOUT_ergodox(
  // left hand
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_MINS,
  VRSN,    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_0,    KC_DOT,  KC_SLSH,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_EQL,  KC_0,    KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_MENU, KC_PSCR, KC_PAUS, KC_INS,  KC_SLCK, KC_TRNS,
           KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_BSPC
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
