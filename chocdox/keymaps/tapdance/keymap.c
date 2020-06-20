#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUM 1
#define _NAV 2
#define _GAM 3
#define _GANAV 4

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
  GAM,
  LPAREN,
  RPAREN,
  UND,
  EQU,
};

enum {
  Z = 0,
  W,
  U,
  X,
  SLS,
  Q,
  Y_ALP,
  Y_GAM,
  _F1,
  _F2,
  _F3,
  _GAMENAV,

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.                  ,----------------------------------.
 * |Q/ESC |  W/( |   E  |   R  |   T  |                  | Y/Gam| U/)  | I/Win|   O  |   P  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |A/Shft|   S  |   D  |F/Ctrl|   G  |                  |   H  |J/Alt |   K  |   L  |'/Shft|
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |Z/Home| X/TAB|   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  | /End |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.       ,-------------------.
 *                      | Del  | Enter| Num |       | Nav| Space| Bkspc |
 *                      `-------------------.       `-------------------.                             
 */
[_QWERTY] = LAYOUT( \
  TD(Q),          TD(W),    KC_E,       KC_R,                  KC_T,                 TD(Y_GAM), TD(U),                 LWIN_T(KC_I),    KC_O,     KC_P,             \
  LSFT_T(KC_A),   KC_S,     KC_D,      MT(MOD_RCTL, KC_F),    KC_G,                 KC_H,      MT(MOD_RALT, KC_J),    KC_K,            KC_L,     RSFT_T(KC_QUOT),  \
  TD(Z),          TD(X),    KC_C,       KC_V,                  KC_B,                 KC_N,      KC_M,                  KC_COMM,         KC_DOT,   TD(SLS),          \
                            KC_DEL,     KC_ENTER,              TO(1),                TO(2),     KC_SPC,                KC_BSPC                               \
),

/* Num
 * ,----------------------------------.                  ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * | Shift|   +  |   -  |   *  |   /  |                  |   (  |  )   |  [   |  ]   |   ;  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   =  |  ~/` |   _  |   \  |      |                  |      |      |  ,   |   .  | Shft |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.       ,-------------------.
 *                      | Del  | Enter| Nav |       | Alp| Space| Bkspc |
 *                      `-------------------.       `-------------------.    
 */
[_NUM] = LAYOUT( \
  KC_1,     KC_2,      KC_3,      KC_4,      KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     \
  KC_LSFT,  NPLUS,     NMINUS,    NSTAR,     NSLASH,       LPAREN,  RPAREN,  KC_LBRC, KC_RBRC, KC_SCLN,  \
  EQU,      KC_GRAVE,  UND,       KC_BSLS,   __,           __,      __,      KC_COMM, KC_DOT,  KC_RSFT,       \
                       KC_DEL,    KC_ENTER,  TO(2),        TO(0),   KC_SPC,  KC_BSPC                     \
),

/* Nav
 * ,----------------------------------.                  ,----------------------------------.
 * |   Z  |   X  |  Mup |  C   |   V  |                  |   F  |LClck |  Up  |RClck | Reset|
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * | Ctrl |MLeft |MDown |MRight|  F6  |                  |  F7  | Left | Down |Right | Shft |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F8  |  F9  | F10  | F11  | F12  |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.       ,-------------------.
 *                      | Del  | Enter| Alp |       | Num| Space| Bkspc |
 *                      `-------------------.       `-------------------.
 */
[_NAV] = LAYOUT( \
  KC_Z,      KC_X,     KC_MS_U,   KC_C,      KC_V,       KC_F,     KC_BTN1,  KC_UP,      KC_BTN2,    RESET,  \
  KC_LCTRL,  KC_MS_L,  KC_MS_D,   KC_MS_R,   KC_F6,      KC_F7,    KC_LEFT,  KC_DOWN,    KC_RIGHT,   KC_LSFT,     \
  KC_F1,     KC_F2,    KC_F3,     KC_F4,     KC_F5,      KC_F8,    KC_F9,    KC_F10,     KC_F11,     KC_F12, \
                       KC_DEL,    KC_ENTER,  TO(0),      TO(1),    KC_SPC,   KC_BSPC                         \
),

/* Gaming
 * ,----------------------------------.                  ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                  |Y/ALP | U/F3 | I/F2 |   O  |   P  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   A  |   S  |   D  |F/Ctrl|   G  |                  |   H  | J/F1 |   K  |   L  |'/Shft|
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |Z/Shft|   X  |   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.      ,-------------------.
 *                      |  Del | Ent | Tab |      | Esc/4 | Space|Bkspc|
 *                      `-------------------.      `-------------------.                             
 */
[_GAM] = LAYOUT( \
  KC_Q,           KC_W,     KC_E,       KC_R,                  KC_T,                                         TD(Y_ALP),  TD(_F3),      TD(_F2),  KC_O,     KC_P,             \
  KC_A,           KC_S,     KC_D,       MT(MOD_RCTL, KC_F),    KC_G,                                         KC_H,       TD(_F1),      KC_K,     KC_L,     RSFT_T(KC_QUOT),  \
  LSFT_T(KC_Z),   KC_X,     KC_C,       KC_V,                  KC_B,                                         KC_N,       KC_M,         KC_COMM,  KC_DOT,   KC_SLSH,          \
                                        KC_DEL,                KC_ENT, KC_TAB,               TD(_GAMENAV),   KC_SPC,     KC_BSPC                               \
),

/* Gaming Nav
 * ,----------------------------------.                  ,----------------------------------.
 * |   Z  |   X  |      |   C  |   V  |                  |      |      |  Up  |      |      |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * | Ctrl |      |      |      |      |                  |      | Left | Down |Right | Shift|
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |      |      |      |      |      |                  |      |      |      |      |      |
 * `----------------------------------'                  `----------------------------------'
 *                      ,-------------------.      ,-------------------.
 *                      |  Del | Ent | Tab  |      |Esc/4| Space| Bkspc |
 *                      `-------------------.      `-------------------.                              
 */
[_GANAV] = LAYOUT( \
  KC_Z,      KC_X,     __,         KC_C,    KC_V,                                         __,        __,          KC_UP,      __,         __,             \
  KC_LCTRL,  __,       __,         __,      __,                                           __,        KC_LEFT,     KC_DOWN,    KC_RIGHT,   KC_LSFT,  \
  __,        __,       __,         __,      __,                                           __,        __,          __,         __,         __,          \
                                   KC_DEL,  KC_ENT,  KC_TAB,              TD(_GAMENAV),   KC_SPC,    KC_BSPC                               \
),
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
#define rgblight_set_orange      rgblight_setrgb (255,  50, 0);
#define rgblight_set_red         rgblight_setrgb (255,  0, 0);

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
    case _GAM:
   		rgblight_set_orange;
    	break;
    case _GANAV:
		rgblight_set_red;
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
void gaming (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
  	tap_code(KC_Y);
  }
  else if (state->count >= 3) {
    layer_on(_GAM);
  }
  reset_tap_dance (state);
};

void alpha (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
  	tap_code(KC_Y);
  }
  else if (state->count >= 3) {
    layer_off(_GAM);
  }
  reset_tap_dance (state);
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [Z]  = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_HOME),
  [W]  = ACTION_TAP_DANCE_DOUBLE(KC_W, LSFT(KC_9)),
  [X]  = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_TAB),
  [U]  = ACTION_TAP_DANCE_DOUBLE(KC_U, LSFT(KC_0)),
  [SLS]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_END),
  [Q]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [_F1]  = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_F1),
  [_F2]  = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_F2),
  [_F3]  = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_F3),
  [_GAMENAV]  = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, 4),
  [Y_ALP] = ACTION_TAP_DANCE_FN(alpha),
  [Y_GAM] = ACTION_TAP_DANCE_FN(gaming),

};
