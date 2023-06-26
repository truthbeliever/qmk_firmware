#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK = 0,
    _NAV

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [_COLEMAK] = LAYOUT_all(
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_PSCR, KC_SLCK, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,          KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_M,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_NUHS, KC_ENT,                                    KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_NUBS,KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RO,   KC_RSFT,              KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    KC_LCTL, KC_LALT, MO(_NAV), XXXXXXX, XXXXXXX,        MT(MOD_RSFT,KC_SPC),        XXXXXXX, XXXXXXX, XXXXXXX,  MO(_NAV),  KC_RALT, XXXXXXX, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),
    [_NAV] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,   ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,   ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,   ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  KC_DEL, KC_ENT, KC_ENT,  KC_HOME,   KC_UP, KC_PGUP,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  KC_BSPC, ______, KC_BSPC,  KC_LEFT,  KC_DOWN, KC_RIGHT,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, KC_DEL,  KC_DEL,   KC_END, KC_PGDN,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,            ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    )
};
/*
[_COLEMAK] = LAYOUT_all(
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_PSCR, KC_SLCK, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_F16,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,          KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_M,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_NUHS, KC_ENT,                                    KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_NUBS,KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RO,   KC_RSFT,              KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    KC_LCTL, KC_LALT, MO(_NAV), XXXXXXX, XXXXXXX,        MT(MOD_RSFT,KC_SPC),        XXXXXXX, XXXXXXX, XXXXXXX,  MO(_NAV),  KC_RALT, XXXXXXX, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),
    [_NAV] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,   ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,   ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,   ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  KC_DEL, KC_ENT, KC_ENT,  KC_HOME,   KC_UP, KC_PGUP,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  KC_BSPC, ______, KC_BSPC,  KC_LEFT,  KC_DOWN, KC_RIGHT,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, KC_DEL,  KC_DEL,   KC_END, KC_PGDN,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,            ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    )

    */
