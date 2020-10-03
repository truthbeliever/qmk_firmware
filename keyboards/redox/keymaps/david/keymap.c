#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAKDHMK 0
#define _COLEMAK 1
#define _NAV 2
#define _QWERTY 3
#define _SYMB 4
#define _FUNC 5
#define _ADJUST 6

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))


enum custom_keycodes {
  COLEMAKDHMK = SAFE_RANGE,
  COLEMAK,
  QWERTY,
  SYMB,
  NAV,
  ADJUST,
  KC_CCCV,
  DE_AE,
  DE_UE,
  DE_OE
};

uint16_t copy_paste_timer;
#define TAPPING_TERM 200

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define NAV_L   MO(_NAV)
#define KC_FUNC_E LT(_FUNC, KC_ENT)
#define KC_FUNC MO(_FUNC)
#define KC_FUNC_C LT(_FUNC, KC_CLCK)
#define KC_AD_PSCR LT(_ADJUST, KC_PSCR)
#define KC_AD_INS LT(_ADJUST, KC_INS)
#define KC_CTPL_CPS LCTL_T(KC_CLCK)

#define KC_CTPL_BS LCTL_T(KC_BSPC)

#define KC_RALT_CPS RALT_T(KC_CLCK)
#define KC_RSFT_CPS RSFT_T(KC_CLCK)
#define KC_LSFT_CPS LSFT_T(KC_CLCK)
#define KC_FUNC_SPC LT(_FUNC, KC_SPC)
#define KC_FUNC_BKSPC LT(_FUNC, KC_BSPC)
#define KC_FUNC_CPS LT(_FUNC, KC_CLCK)
#define KC_LALT_DEL LALT_T(KC_DEL)
#define KC_COLDH TG(_COLEMAKDHMK)
#define KC_COLE TG(_COLEMAK)
#define KC_QWERTY TG(_QWERTY)
#define KC_ATAB RALT_T(KC_TAB)        // - Tab / Alt Gr
#define KC_CMIN RCTL_T(KC_MINUS)      // - Minus / Right Ctrl
#define KC_RAEN RALT_T(KC_ENT)        // - Enter / Right Alt
#define KC_LAEN LALT_T(KC_ENT)        // - Enter / Left Alt
#define KC_CBSP LCTL_T(KC_BSPC)

#define KC_BSPSHT MT(MOD_LSFT,KC_BSPC)
#define KC_SPCSHT MT(MOD_RSFT,KC_SPC)

//ganz schnell aa drücken gibt ae

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   // Colemak DM-MK Mod
  [_COLEMAKDHMK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_CMIN ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ATAB ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_LBRC                           ,KC_RBRC ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_EQL  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_DEL                            ,KC_BSPC ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_RSFT ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_BSLS ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_SPC  ,KC_FUNC_E       ,KC_FUNC_CPS,KC_CCCV ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_QUOT ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       KC_LCTL ,KC_AD_PSCR,KC_LALT,NAV_L       ,KC_BSPC     ,KC_DEL  ,KC_LSFT         ,KC_RSFT ,KC_ENT      ,KC_SPC       ,NAV_L   ,KC_ALGR ,KC_RGUI ,KC_RCTL
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   [_COLEMAK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,_______                           ,_______ ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,_______  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,_______                           ,_______ ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,_______ ,_______         ,_______ ,_______ ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______      ,_______     ,_______ ,_______         ,_______ ,_______     ,_______      ,_______ ,_______ ,_______ ,_______
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,_______ ,                          _______ ,KC_ENT  ,KC_HOME ,KC_UP   ,KC_PGUP ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,_______ ,                          _______ ,KC_BSPC ,KC_LEFT ,KC_DOWN ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,KC_DEL  ,KC_END  ,XXXXXXX ,KC_PGDN ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  // QWERTY
  [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_______                           ,_______ ,KC_Z    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_BSLS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,_______                           ,_______ ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_Y    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,_______ ,_______         ,_______ ,_______ ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______  ,_______     ,_______     ,_______ ,_______         ,_______ ,_______     ,_______      ,_______ ,_______ ,_______ ,_______
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  // Function layer
  [_FUNC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,DE_UE   ,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,DE_AE   ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,DE_OE   ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_PSCR ,KC_NLCK ,KC_INS  ,KC_CAPS ,KC_APP  ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_COLDH,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,KC_QWERTY,RGB_M_K ,RGB_M_X ,RGB_M_G ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_COLE ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

void tap_key(uint16_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CCCV:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            break;
        case DE_AE:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                clear_mods();
                register_code(KC_LALT);
                if (temp_mod & MODS_SHIFT_MASK) {
                tap_key(KC_P1); tap_key(KC_P4); tap_key(KC_P2); // Ä
                } else {
                tap_key(KC_P1); tap_key(KC_P3); tap_key(KC_P2); // ä
                }
                unregister_code(KC_LALT);
                return false;
            }
            break;
        case DE_UE:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                clear_mods();
                register_code(KC_LALT);
                if (temp_mod & MODS_SHIFT_MASK) {
                tap_key(KC_P1); tap_key(KC_P5); tap_key(KC_P4); // UE
                } else {
                tap_key(KC_P1); tap_key(KC_P2); tap_key(KC_P9); // ue
                }
                unregister_code(KC_LALT);
                return false;
            }
            break;
        case DE_OE:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                clear_mods();
                register_code(KC_LALT);
                if (temp_mod & MODS_SHIFT_MASK) {
                tap_key(KC_P1); tap_key(KC_P5); tap_key(KC_P3); // OE
                } else {
                tap_key(KC_P1); tap_key(KC_P4); tap_key(KC_P8); // oe
                }
                unregister_code(KC_LALT);
                return false;
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_WIN);
};


