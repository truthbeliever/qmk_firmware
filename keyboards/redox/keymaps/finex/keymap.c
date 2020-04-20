#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layer names
enum{
  // - Base layers:
  _COLEMAKDHMK,
  _NAV,
  _QWERTY,
  _FUNC,
 // - Adjust layer:
  _ADJUST
};

// Custom keycodes
enum custom_keycodes {
  COLEMAKDHMK = SAFE_RANGE,
  NAV,
  QWERTY,
  ASC_SAR,
  ASC_DAR,
  ASC_SQT,
  ASC_DQT,
  ASC_CIRC,
  ASC_TILD,
  ASC_HAP,
  ASC_SAD,
  ASC_BKT,
  ASC_CBRL,
  ASC_CBRR
};

// Tap dance keycodes
enum tap_dance{
  TD_SCLN, // ;; -> :
  TD_LBRC, // [[ -> {
  TD_RBRC, // ]] -> }
  TD_QMRK  // // -> ?
};

// Semicolon to Colon
void dance_scln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}
void dance_scln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

// Square braket to curly bracket (left)
void dance_lbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_LBRC);
  }
}
void dance_lbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_LBRC);
  }
}

// Square braket to curly bracket (right)
void dance_rbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_RBRC);
  }
}
void dance_rbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_RBRC);
  }
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_scln_finished, dance_scln_reset),
  [TD_LBRC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lbrc_finished, dance_lbrc_reset),
  [TD_RBRC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbrc_finished, dance_rbrc_reset)
};


// Shortcut to make keymap more readable

// - Adjustment Layer:
#define KC_ADEN LT(_ADJUST, KC_END)   // End / _ADJUST layer
#define KC_ADPU LT(_ADJUST, KC_PGUP)  // Page Up / _ADJUST layer

// - Custom layers:
//#define KC_SYSP LT(_SYMB, KC_SPC)     // Space / _symbols
//#define KC_NUES LT(_NUMB, KC_ESC)     // Esc / _numbers
#define KC_FUTA LT(_FUNC, KC_TAB)     // Tab / _functions
//#define KC_N_SH LT(_LHSH, KC_N)       // Pressing N key, enable shifted keys on other half (the left one)
//#define KC_T_SH LT(_RHSH, KC_T)       // Pressing T key, enable shifted keys on other half (the right one)

// - Custom keys/modifiers:
#define KC_ATAB RALT_T(KC_TAB)        // - Tab / Alt Gr
#define KC_CESC LCTL_T(KC_ESC)        // - Esc / Left Ctrl
#define KC_GSPC LGUI_T(KC_SPC)        // - Space / Left GUI
#define KC_CBSP LCTL_T(KC_BSPC)       // - Backspace / Left Ctrl

// -- Mac os mode:
#define KC_CSPC LCTL_T(KC_SPC)        // - Space / Left Ctrl
#define KC_GBSP LGUI_T(KC_BSPC)       // - Backspace / Left GUI


#define KC_AEQL LALT_T(KC_EQL)        // - Equals / Alt (left alt)
#define KC_CMIN RCTL_T(KC_MINUS)      // - Minus / Right Ctrl
#define KC_ADEL RALT_T(KC_DEL)        // - Del / Alt Gr
#define KC_RSEN RSFT_T(KC_ENT)        // - Enter / Right Shift (standard shift)
#define KC_LAEN LALT_T(KC_ENT)        // - Enter / Left Alt
#define KC_RAEN RALT_T(KC_ENT)        // - Enter / Right Alt

// Home row mod tap keys:
// - Left hand
#define KC_CT_A CTL_T(KC_A)           // A / Left Ctrl
#define KC_AL_S ALT_T(KC_S)           // S / Left Alt
// - Right hand
#define KC_AL_E ALT_T(KC_E)           // E / Left Alt
#define KC_CT_O CTL_T(KC_O)           // O / Left Ctrl

// - Tap dance:
#define KC_TDSC TD(TD_SCLN)           // ;; -> :
#define KC_TDLB TD(TD_LBRC)           // [[ -> {
#define KC_TDRB TD(TD_RBRC)           // ]] -> }

// - Keyboard base maps:
#define LR1 COLEMAKDHMK
//#define LR2 NAV
#define LR3 QWERTY
//#define LR4 QWERTY_MAC

// - David
#define NAV_L   MO(_NAV)
#define KC_AD_PSCR LT(_ADJUST, KC_PSCR)
#define KC_AD_INS LT(_ADJUST, KC_INS)
#define KC_CTPL_CPS LCTL_T(KC_CLCK)
#define KC_RALT_CPS RALT_T(KC_CLCK)
#define KC_CTPR_CPS RCTL_T(KC_CLCK)
#define KC_FUNC_SPC LT(_FUNC, KC_SPC)
#define KC_FUNC_BKSPC LT(_FUNC, KC_BSPC)
#define KC_LALT_DEL LALT_T(KC_DEL)

// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case ASC_SAR:
        SEND_STRING("->");
        return false;
      case ASC_DAR:
        SEND_STRING("=>");
        return false;
      case ASC_SQT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("'"));
        return false;
      case ASC_DQT:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("\"")));
        return false;
      case ASC_CIRC:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("^"));
        return false;
      case ASC_TILD:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("~")));
        return false;
      case ASC_HAP:
        SEND_STRING(":-) ");
        return false;
      case ASC_SAD:
        SEND_STRING(":-( ");
        return false;
      case ASC_BKT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("`"));
        return false;
      case ASC_CBRL:
        SEND_STRING("{");
        return false;
      case ASC_CBRR:
        SEND_STRING("}");
        return false;
      case QWERTY:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
      case COLEMAKDHMK:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_COLEMAKDHMK);
        }
        return false;
        break;
      case _NAV:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_NAV);
        }
        return false;
        break;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Colemak DM-MK Mod
  [_COLEMAKDHMK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_EQL  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ATAB ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_DEL                            ,KC_BSPC ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_TDSC ,KC_QUOT ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_BSLS ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_TDLB ,                          KC_TDRB ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_CMIN ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSPO ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_LBRC ,KC_AD_PSCR      ,KC_AD_INS,KC_RBRC,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSPC ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       KC_LCTL ,KC_HYPR ,KC_MEH  ,NAV_L       ,KC_FUNC_BKSPC,KC_LALT_DEL,KC_CTPL_CPS ,KC_CTPR_CPS, KC_RAEN ,KC_FUNC_SPC   ,NAV_L   ,KC_ALGR ,KC_RGUI ,KC_RCTL
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
       KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_EQL,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ATAB ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_DEL   ,                          KC_BSPC,KC_Z    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_QUOT ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_BSLS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_TDLB ,                          KC_TDRB ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_TDSC ,KC_CMIN ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSPO ,KC_Y    ,KC_X    ,KC_C    ,KC_V    ,KC_B     ,KC_LBRC ,KC_AD_PSCR      ,KC_AD_INS,KC_RBRC ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSPC ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       KC_LCTL ,KC_HYPR ,KC_MEH  ,NAV_L        ,KC_CBSP ,    KC_DEL  ,KC_CTPL_CPS     ,KC_RALT_CPS ,KC_LAEN , KC_SPC ,     NAV_L   ,KC_ALGR ,KC_RGUI ,KC_RCTL
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  // Function layer and some extra keys on right hand
  [_FUNC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,_______ ,                          _______ ,KC_6    ,KC_7   ,KC_8     ,KC_9    ,KC_0    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_PSCR ,KC_NLCK ,KC_INS  ,KC_CAPS ,KC_APP  ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  // Adjust layer (RGB, Reset and base layer switch)
  [_ADJUST] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12 ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,LR1     ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,LR3     ,RGB_M_K ,RGB_M_X ,RGB_M_G ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};
