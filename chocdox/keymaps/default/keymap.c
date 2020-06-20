#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUM 1
#define _NAV 2

#define __ KC_NO
// #define NAV TO(2)
// #define NUM TO(1)
// #define ALPHA TO(0)
#define NPLUS KC_KP_PLUS
#define NMINUS KC_KP_MINUS
#define NSTAR KC_KP_ASTERISK
#define NSLASH KC_KP_SLASH
#define CAPS KC_CAPSLOCK

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUM,
  LPAREN,
  RPAREN,
  UND,
  EQU,
};

enum {
  Z = 0,
  Q,
  ENT,
  BSP,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.                  ,----------------------------------.
 * |Q/ESC |   W  |   E  |   R  |   T  |                  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   A  |  S   |   D  |   F  |   G  |                  |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |Z/Shft|   X  |   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  |//Shft|
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.       ,-------------------.
 *                      | Del  |Ent/Ct| Nav |       | Num|SP/RALT|  BSP |
 *                      `-------------------.       `-------------------.
 *                                
 */
[_QWERTY] = LAYOUT( \
  TD(Q),   KC_W,     KC_E,       KC_R,            KC_T,                 KC_Y,    KC_U,             KC_I,           KC_O,    KC_P,             \
  KC_A,    KC_S,     KC_D,       KC_F,            KC_G,                 KC_H,    KC_J,             KC_K,           KC_L,    KC_QUOT,  \
  LSFT(Z), KC_X,     KC_C,       KC_V,            KC_B,                 KC_N,    KC_M,             KC_COMM,        KC_DOT,  RSFT_T(KC_SLSH),          \
                     KC_DEL,     CTL_T(KC_ENT),   TO(1),                TO(2),   ALGR_T(KC_SPC),   KC_BSPC                              \
),

/* Num
 *
 * ,----------------------------------.                  ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   =  |   +  |   -  |   *  |   /  |                  |   (  |  )   |  [   |  ]   |   ;  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * | Shift|  ~/` |   _  |   \  |      |                  | Home | End  |  ,   |   .  | Shft |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.       ,-------------------.
 *                      | Del  |Ent/Ct| Alp |       | Nav|SP/RALT|  BSP |
 *                      `-------------------.       `-------------------.    
 */
[_NUM] = LAYOUT( \
  KC_1,     KC_2,      KC_3,      KC_4,      KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     \
  EQU,      NPLUS,     NMINUS,    NSTAR,     NSLASH,            LPAREN,  RPAREN,  KC_LBRC, KC_RBRC, KC_SCLN,  \
  KC_LSFT,  KC_GRAVE,  UND,       KC_BSLS,   __,                KC_HOME, KC_END,  KC_COMM, KC_DOT,  KC_RSFT,       \
                       KC_DEL,    CTL_T(KC_ENT),  TO(2),        TO(0),    ALGR_T(KC_SPC),  KC_BSPC                     \
),

/* Nav
 *
 * ,----------------------------------.                  ,----------------------------------.
 * |   Z  |   X  |  Mup |  C   |   V  |                  |      |LClck |  Up  |RClck | Reset|
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * | Win  |MLeft |MDown |MRight|  F6  |                  |  F7  | Left | Down |Right | Shft |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F8  |  F9  | F10  | F11  | F12  |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.       ,-------------------.
 *                      | Del  |Ent/Ct| Num |       | Alp|SP/RALT|  BSP |
 *                      `-------------------.       `-------------------.
 */
[_NAV] = LAYOUT( \
  KC_Z,      KC_X,     KC_MS_U,   KC_C,           KC_V,       __,       KC_BTN1,  KC_UP,      KC_BTN2,    RESET,  \
  KC_LCTRL,  KC_MS_L,  KC_MS_D,   KC_MS_R,        KC_F6,      KC_F7,    KC_LEFT,  KC_DOWN,    KC_RIGHT,   KC_LSFT,     \
  KC_F1,     KC_F2,    KC_F3,     KC_F4,          KC_F5,      KC_F8,    KC_F9,    KC_F10,     KC_F11,     KC_F12, \
                       KC_DEL,    CTL_T(KC_ENT),  TO(0),        TO(1),    ALGR_T(KC_SPC),   KC_BSPC                         \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) 
  {
    case LPAREN:
      if (record->event.pressed) 
      {
        SEND_STRING("(");
      } 
      else 
      {
      }
      break;
    case RPAREN:
      if (record->event.pressed) 
      {
        SEND_STRING(")");
      } 
      else 
      {
      }
      break;
    case UND:
      if (record->event.pressed) 
      {
        SEND_STRING("_");
      } 
      else 
      {
      }
      break;
    case EQU:
      if (record->event.pressed) 
      {
        SEND_STRING("=");
      } 
      else 
      {
      }
      break;
  }
  return true;
};

// Backlight code

//Color definition
#define rgblight_set_blue        rgblight_setrgb (0,  0, 255);
#define rgblight_set_green       rgblight_setrgb (0,  255, 0);
#define rgblight_set_purple      rgblight_setrgb (200,  0, 200);
#define rgblight_set_yellow      rgblight_setrgb (255,  255, 0);

uint32_t layer_state_set_user(uint32_t  state) {
    switch (biton32(state)) {
    case _QWERTY:
        rgblight_set_blue;
        break;
    case _NAV:
        rgblight_set_purple;
        break;
    case _NUM:
       rgblight_set_green;
        break;
    default:
        rgblight_set_blue;
       break;
    }
  return state;
};

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [Q]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_LCTRL),
  [BSP]  = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_RALT),
};

