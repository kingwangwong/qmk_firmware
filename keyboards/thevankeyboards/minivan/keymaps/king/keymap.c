#include QMK_KEYBOARD_H




extern uint8_t is_master;


enum layer_number {
  _ML = 0,
  _FL,
  _NL,
  _SL,
  _RL
};




// Layer Mode aliases
#define SPC_FUN LT(_FL, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_ML] = LAYOUT(

  /* 0: Main Layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
   * │ ESC │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │BKSPC    │  
   * ├─────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────────┤
   * │ TAB  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ ;   │'       │
   * ├──────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┤
   * │ LSHFT   │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │ENTER│
   * ├────────┬┴─────┴─┬───┴─┬───┴─────┴──┬──┴─────┴─────┴─┬───┴─┬───┴─┬───┴─────┤
   * │ LCTRL  │ LGUI   │LALT │SPACE(_NL)  │MO(_NL)         │MO SL│MO(RL│         │
   * └────────┴────────┴─────┴────────────┴────────────────┴─────┴─────┴─────────┘
   */

        KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,   KC_I,    KC_O,     KC_P,KC_BSPC,  
        KC_TAB,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,     KC_SCLN,  KC_QUOT,         
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_ENT,     
        KC_LCTL, KC_LGUI, KC_LALT,         SPC_FUN,                      MO(_NL),        MO(_SL), MO(_RL),  XXXXXXX
  ),


  [_FL] = LAYOUT(
      
  /* 1: Function Layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
   * │     │     │HOME │ UP  │END  │PGUP │     │ F1  │ F2  │ F3  │ F4  │         │
   * ├─────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────────┤
   * │ CAPS │     │LEFT │DOWN │RIGHT│PGDN │     │ F5  │ F6  │ F7  │ F8  │        │
   * ├──────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┤
   * │         │     │     │ DEL │ INS │     │     │ F9  │ F10 │ F11 │ F12 │     │
   * ├────────┬┴─────┴─┬───┴─┬───┴─────┴──┬──┴─────┴─────┴─┬───┴─┬───┴─┬───┴─────┤
   * │        │        │     │            │                │     │     │         │
   * └────────┴────────┴─────┴────────────┴────────────────┴─────┴─────┴─────────┘
   */

        _______,   XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, KC_F1, KC_F2,   KC_F3,    KC_F4,   _______,  
        KC_CAPS,   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_F5, KC_F6,   KC_F7,    KC_F8,   _______,        
        _______,   XXXXXXX, XXXXXXX, KC_DEL,  KC_INS,  XXXXXXX, XXXXXXX, KC_F9, KC_F10,  KC_F11,   KC_F12,  _______,        
        _______,   _______,  _______,         _______,          _______,        _______, _______,  _______
  ),

  [_NL] = LAYOUT(


  /* 2: Number Layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
   * │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │         │
   * ├─────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────────┤
   * │   `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  8  │ 0   │        │
   * ├──────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┤
   * │         │     │     │     │     │     │     │     │     │     │     │     │
   * ├────────┬┴─────┴─┬───┴─┬───┴─────┴──┬──┴─────┴─────┴─┬───┴─┬───┴─┬───┴─────┤
   * │        │        │     │            │                │     │     │         │
   * └────────┴────────┴─────┴────────────┴────────────────┴─────┴─────┴─────────┘
   */

        KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  _______,  
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,         
        _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,           
        _______,  _______,   _______,        _______,          _______,          _______, _______, _______
  ),

  [_SL] = LAYOUT(

          /* 3: Symbol Layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
   * │     │  _  │  +  │  {  │  }  │  |  │     │     │     │     │     │         │
   * ├─────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────────┤
   * │      │  -  │  =  │  [  │  ]  │  \  │     │ DEL │ INS │     │     │        │
   * ├──────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┤
   * │         │     │     │     │     │     │     │     │     │     │     │     │
   * ├────────┬┴─────┴─┬───┴─┬───┴─────┴──┬──┴─────┴─────┴─┬───┴─┬───┴─┬───┴─────┤
   * │        │        │     │            │                │     │     │         │
   * └────────┴────────┴─────┴────────────┴────────────────┴─────┴─────┴─────────┘
   */
        _______,  KC_UNDS, KC_PLUS,  KC_LCBR, KC_RCBR,  KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
        _______,  KC_MINS, KC_EQL,   KC_LBRC, KC_RBRC,  KC_BSLS, XXXXXXX, KC_DEL,  KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX,           
        _______,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           
        _______,  _______,  _______,          _______,           _______,          _______, _______, _______

  ),

  [_RL] = LAYOUT(

  /* 4: Reset Layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
   * │RESET│     │     │     │     │     │     │     │     │     │     │         │
   * ├─────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────────┤
   * │      │     │     │     │     │     │     │     │     │     │     │        │
   * ├──────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┤
   * │         │     │     │     │     │     │     │     │     │     │     │     │
   * ├────────┬┴─────┴─┬───┴─┬───┴─────┴──┬──┴─────┴─────┴─┬───┴─┬───┴─┬───┴─────┤
   * │        │        │     │            │                │     │     │         │
   * └────────┴────────┴─────┴────────────┴────────────────┴─────┴─────┴─────────┘
   */
        QK_BOOT,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           
        XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    )
};



