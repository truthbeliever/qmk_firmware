/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_german_ch.h"
#include <stdio.h>

enum layers {
    _QWERTZ = 0,
    _COLEMAK,
    _RAISE,
    _NAV,
    _ADJUST
};

char wpm_str[10];
uint16_t wpm_graph_timer = 0;
uint16_t copy_paste_timer =0;
#define KC_BSPSHT MT(MOD_LSFT,KC_BSPC)

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTZ
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   U  |   I  |   O  |   P  |  ü     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |ctrlTAB |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ö    |  ä ctrl|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT ( |   Y  |   X  |   C  |   V  |   B  |NUMENT|ALTcap|  | ALTcP| Numb |   N  |   M  | ,  ; | . :  | - _  | ) RSFT |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | PSCR | Nav  | Bspc | Del  | spc  |  | bSPC | Enter| Space| Nav  |adjust|
 *                        |      |      | shft |      |      |  |      |      | shift|      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 */
  [_QWERTZ] = LAYOUT(
      KC_ESC,  CH_Q,   CH_W,   CH_E,   CH_R,   CH_T,                                                 CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    CH_UE,
      MT(MOD_LCTL,KC_TAB),  CH_A,   CH_S,   CH_D,   CH_F,   CH_G,                                    CH_H,    CH_J,    CH_K,    CH_L,    CH_OE,   MT(MOD_RCTL,CH_AE),
      KC_LSPO, CH_Y,   CH_X,   CH_C,   CH_V,   CH_B,   LT(_RAISE, KC_ENT), MT(MOD_LALT,KC_CAPS) , MT(MOD_RALT,KC_CAPS),   MO(_RAISE), CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_MINS, KC_RSPC,
              KC_CCCV, MO(_NAV),KC_BSPSHT, KC_DEL, KC_SPC,    KC_BSPC, KC_ENT,  MT(MOD_RSFT,KC_SPC), MO(_NAV), MO(_ADJUST)
    ),
/*
 * COLMAK Layer:
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  Q   | W    | F    |  P   |  B   |                              | J    | L    | U    |  Y   | ;    |  -     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  A   | R    | S    | T    |  G   |                              | M    | N    |  E   |   I  |  O   |  =     |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  Z   | X    | C    | D    |  V   |      |      |  |      |      | K    |  H   |  ,   |  .   | /    |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_COLEMAK] = LAYOUT(
      _______, KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B   ,                                     KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_MINUS ,
      _______, KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G   ,                                     KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,MT(MOD_RCTL, KC_EQL),
      _______, KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V   , _______, _______, _______, _______, KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1 + |  2 " |  3 * |  4 ç |  5 % |                              |   6 &|  7 / |  8 ( |  9 ) |  0 = |  ' ?   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |    | |  @   |  #   |      |      |                              |      |      |      |   [  |   ]  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |<>    |  \   |      |      |      |      |      |  |      |      |      |      |      |   {  |   }  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      CH_RING, CH_1,    CH_2,    CH_3,    CH_4,    CH_5,                                        CH_6,    CH_7,    CH_8,    CH_9,    CH_0,    CH_QUOT,
      _______, CH_PIPE, CH_AT,   CH_HASH, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, CH_LBRC, CH_RBRC, XXXXXXX,
      _______, CH_LESS, CH_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, CH_LCBR, CH_RCBR, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | MS U |      | WH U |                              |Enter | Home | Up   | PG Up|      | ScrlLk |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | MS L | MS D | MS R | WH D |                              |Backsp| Left | Down | Right|      | CapsLk |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  End |      |PG Dow|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |MS BT1|MS BT2|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U,                                     KC_ENT, KC_HOME ,KC_UP   ,KC_PGUP,  XXXXXXX, XXXXXXX,
      _______, XXXXXXX, KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D,                                     KC_BSPC,KC_LEFT ,KC_DOWN ,KC_RIGHT, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_DEL, KC_END  ,XXXXXXX ,KC_PGDN , XXXXXXX, _______,
                                 _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   F1   |  F2  | F3   | F4   |  F5  |   F6 |                              |  F7  | F8   | F9   | F10  | F11  |  F12   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |QWERTZ| M_P  | TOG  | MOD  |      |                              | HUD  | HUI  | SAD  | SAI  | VAD  | VAI    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |COLMAK|      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                                          KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12,
      XXXXXXX, TO(_QWERTZ), RGB_M_P ,RGB_TOG ,RGB_MOD, XXXXXXX,                                      RGB_HUD,RGB_HUI , RGB_SAD ,RGB_SAI, RGB_VAD, RGB_VAI,
      _______, TO(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
/*
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _NAV, _ADJUST);
} */



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev 1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTZ:
            oled_write_P(PSTR("Qwertz CH\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak DHm\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Zahlen\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Einstellungen\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
   // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
     #ifdef WPM_ENABLE
    // Write WPM
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_P(PSTR("\n"), false);
    oled_write(wpm_str, false);
    #endif
}


static uint8_t zero_bar_count = 0;
static uint8_t bar_count = 0;

static void render_wpm_graph(void) {
    uint8_t bar_height = 0;
    uint8_t bar_segment = 0;

    if (wpm_graph_timer == 0) {
	render_kyria_logo();
	wpm_graph_timer = timer_read();
	return;
    }
    if(timer_elapsed(wpm_graph_timer) > 500) {
	wpm_graph_timer = timer_read();

	if(OLED_DISPLAY_HEIGHT == 64)
		bar_height = get_current_wpm() / 2;
	if(OLED_DISPLAY_HEIGHT == 32)
		bar_height = get_current_wpm() / 4;
	if(bar_height > OLED_DISPLAY_HEIGHT)
		bar_height = OLED_DISPLAY_HEIGHT;

	if(bar_height == 0) {
	    // keep track of how many zero bars we have drawn.  If
	    // there is a whole screen worth, turn the display off and
	    // wait until there is something to do
	    if (zero_bar_count > OLED_DISPLAY_WIDTH) {
		oled_off();
		return;
	    }
	    zero_bar_count++;
	} else
	    zero_bar_count=0;

	oled_pan(false);
	bar_count++;
	for (uint8_t i = (OLED_DISPLAY_HEIGHT / 8); i > 0; i--) {
	    if (bar_height > 7) {
		if (i % 2 == 1 && bar_count % 3 == 0)
		    bar_segment = 254;
		else
		    bar_segment = 255;
		bar_height -= 8;
	    } else {
		switch (bar_height) {
		    case 0:
			bar_segment = 0;
			break;

		    case 1:
			bar_segment = 128;
			break;

		    case 2:
			bar_segment = 192;
			break;

		    case 3:
			bar_segment = 224;
			break;

		    case 4:
			bar_segment = 240;
			break;

		    case 5:
			bar_segment = 248;
			break;

		    case 6:
			bar_segment = 252;
			break;

		    case 7:
			bar_segment = 254;
			break;
		}
		bar_height = 0;

		if (i % 2 == 1 && bar_count % 3 == 0)
		    bar_segment++;
	    }
	    oled_write_raw_byte(bar_segment, (i-1) * OLED_DISPLAY_WIDTH);
	}
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_wpm_graph();
         //render_kyria_logo();
    }
}

#endif

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
	if (clockwise) {
	  if (!is_alt_tab_active) {
	    is_alt_tab_active = true;
	    register_code(KC_LALT);
	  }
	  alt_tab_timer = timer_read();
	  tap_code16(KC_TAB);
	} else {
	  if (!is_alt_tab_active) {
	    is_alt_tab_active = true;
	    register_code(KC_LALT);
	  }
	  alt_tab_timer = timer_read();
	  tap_code16(S(KC_TAB));
	}
    }
    else if (index == 1) {
         // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
       /*  if (clockwise) {
            tap_code16(C(A(KC_RIGHT)));
        } else {
            tap_code16(C(A(KC_LEFT)));
        } */
    }
}
#endif

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 700) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CCCV:  // One key copy/paste
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
    }
    return true;
    //return true;
}

/* #ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_RGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif */
