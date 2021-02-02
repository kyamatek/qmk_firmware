/* Copyright 2020 kushima8
 * Copyright 2020 utubo
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
#include <stdio.h>

enum layer_number {
    _FIRST = 0,
    _FN,
    _FN2,
    _LEDSET,
    _DVORAK,
    _MOUSE,
    _MFN,
    _TEN,
    _TENFN,
    _SPUP,
    _SPDOWN
};

#define FIRST  TO(_FIRST)
#define FN  MO(_FN)
#define FN2  TO(_FN2)
#define LEDSET TO(_LEDSET)
#define DVORAK TO(_DVORAK)
#define MOUSE TO(_MOUSE)
#define TEN TO(_TEN)
#define TENFN MO(_TENFN)
#define MFN MO(_MFN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FIRST] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,                     KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,KC_DEL, KC_BSPC ,
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                             KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,KC_BSLS,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                             KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,KC_ENT ,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                             KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RCTL,FN2    ,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_ESC, FN     ,KC_RGUI                ,KC_SPC ,KC_LALT,MOUSE  ,     LEDSET ,KC_RSFT,KC_RGUI        ,KC_BSPC,FN
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_FN] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                     KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_INS ,KC_DEL ,
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_CAPS,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                             KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_PSCR,KC_SLCK,KC_PAUS,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_LCTL,KC_BTN1,KC_MS_L,KC_MS_U,KC_MS_D,KC_MS_R,                             KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_MINS,KC_EQL ,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        KC_LSFT,KC_BTN2,KC_DEL ,_______,LALT(KC_LEFT),LALT(KC_RIGHT),                TEN    ,MOUSE  ,KC_HOME,KC_END ,KC_PGDN,KC_MUTE,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_ESC ,_______,KC_RGUI                ,KC_SPC ,KC_LALT,_______,     _______,KC_RSFT,KC_RGUI        ,KC_DEL ,_______
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_FN2] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                     KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_INS ,KC_DEL ,
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_CAPS,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                             KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_PSCR,KC_SLCK,KC_PAUS,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_LCTL,KC_BTN1,KC_MS_L,KC_MS_U,KC_MS_D,KC_MS_R,                             KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_MINS,KC_EQL ,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        KC_LSFT,KC_BTN2,KC_DEL ,_______,LALT(KC_LEFT),LALT(KC_RIGHT),                _______,MOUSE  ,KC_HOME,KC_END ,KC_PGDN,KC_MUTE,FIRST  ,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_ESC ,_______,_______                ,_______,KC_LALT,_______,     _______,KC_RSFT,_______        ,KC_DEL ,_______
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_LEDSET] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,                             _______,_______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,                             _______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,                             _______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______                ,_______,_______,FIRST  ,     DVORAK ,_______,_______        ,_______,_______
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_DVORAK] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,                     KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_LBRC,KC_RBRC,KC_DEL, KC_BSPC ,
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_TAB ,KC_QUOT,KC_COMM,KC_DOT ,KC_P   ,KC_Y   ,                             KC_F   ,KC_G   ,KC_C   ,KC_R   ,KC_L   ,KC_SLSH,KC_EQL ,KC_BSLS,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_LCTL,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,                             KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_MINS,KC_ENT ,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        KC_LSFT,KC_SCLN,KC_Q   ,KC_J   ,KC_K   ,KC_X   ,                             KC_B   ,KC_M   ,KC_W   ,KC_V   ,KC_Z   ,KC_RSFT,FN     ,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        KC_ESC, FN     ,KC_RGUI                ,KC_SPC ,KC_LALT,LEDSET ,     MOUSE  ,KC_RSFT,KC_RGUI        ,KC_BSPC,FN
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_MOUSE] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,_______,_______, 
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_SPDOWN,KC_MS_U,_SPUP  ,_______,                             _______,_______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_BTN1,KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN2,                             KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_S   ,KC_MINS,KC_ENT ,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,                             _______,FIRST  ,_______,_______,_______,_______,FN     ,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,MFN    ,_______                ,_______,_______,DVORAK ,     FIRST  ,_______,_______        ,_______,MFN
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_MFN] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,_______,_______, 
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,KC_MS_U,_______,_______,                             _______,_______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_BTN1,KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN2,                             KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_S   ,KC_MINS,KC_ENT ,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,                             _______,FIRST  ,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______                ,_______,_______,DVORAK ,     FIRST  ,_______,_______        ,_______,_______
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_TEN] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,_______,_______, 
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_DEL ,KC_1   ,KC_2   ,KC_3   ,KC_BSPC,                             _______,_______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_ENT ,KC_4   ,KC_5   ,KC_6   ,KC_MINS,                             KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_S   ,KC_MINS,KC_ENT ,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        _______,_______,KC_7   ,KC_8   ,KC_9   ,KC_EQL ,                             FIRST  ,FIRST  ,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,TENFN  ,_______                ,KC_0   ,KC_ENT ,_______,     _______,_______,_______        ,_______,_______
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
    [_TENFN] = LAYOUT(
    // ,-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------.
        _______,_______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,_______,_______, 
    // |-------+-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_DEL ,KC_1   ,KC_2   ,KC_3   ,KC_BSPC,                             _______,_______,_______,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_ENT ,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,                             KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_S   ,KC_MINS,KC_ENT ,
    // |-------+-------+-------+-------+-------+-------|                            |-------+-------+-------+-------+-------+-------+-------|
        _______,_______,KC_7   ,KC_8   ,KC_9   ,KC_EQL ,                             FIRST  ,FIRST  ,_______,_______,_______,_______,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______                ,KC_0   ,KC_ENT ,_______,     _______,_______,_______        ,_______,_______
    // `-------+-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------'
    ),
};

uint8_t MOUSE_SPEED = 10;

void mouse_move(int8_t x, int8_t y){

    report_mouse_t report = {0};
    report.x = x;
    report.y = y;
    host_mouse_send(&report);

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(get_highest_layer(layer_state) == _MOUSE) {
    switch(keycode){
            case _MOUSE:
                case _SPUP:
                    if (record->event.pressed) {
                        MOUSE_SPEED = MOUSE_SPEED + 5;
                    }
                    return false;
                case _SPDOWN:
                    if (record->event.pressed) {
                        if (MOUSE_SPEED > 0) {
                            MOUSE_SPEED = MOUSE_SPEED - 5;
                        }
                    }
                    return false;
    }
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {

    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _FIRST:
            oled_write_ln_P(PSTR("1st"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case _FN2:
            oled_write_ln_P(PSTR("FN2"), false);
            break;
        case _LEDSET:
            oled_write_ln_P(PSTR("conf"), false);
            break;
        case _DVORAK:
            oled_write_ln_P(PSTR("dvor"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("mous"), false);
            break;
        case _MFN:
            oled_write_ln_P(PSTR("MFN"), false);
            break;
        case _TEN:
            oled_write_ln_P(PSTR("TEN"), false);
            break;
        case _TENFN:
            oled_write_ln_P(PSTR("TNFN"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    #ifdef RGBLIGHT_ENABLE
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("LED"), false);
        oled_write_ln_P(PSTR(""), false);
        static char rgbMode[6] = {0};
        snprintf(rgbMode, sizeof(rgbMode), "M:%-3d", rgblight_get_mode());
        oled_write(rgbMode, false);
        static char rgbHue[6] = {0};
        snprintf(rgbHue, sizeof(rgbHue), "H:%-3d", rgblight_get_hue());
        oled_write(rgbHue, false);
        static char rgbSat[6] = {0};
        snprintf(rgbSat, sizeof(rgbSat), "S:%-3d", rgblight_get_sat());
        oled_write(rgbSat, false);
        static char rgbVal[6] = {0};
        snprintf(rgbVal, sizeof(rgbVal), "V:%-3d", rgblight_get_val());
        oled_write(rgbVal, false);
    #endif

    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("MOUSE"), false);
    static char speed[6] = {0};
    snprintf(speed, sizeof(speed), "SP:%-3d", MOUSE_SPEED);
    oled_write(speed, false);

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
        //print_status_narrow();
    }
}

#endif

#ifdef ENCODER_ENABLE

/* Rotary encoder settings */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Left rotary
        switch (get_highest_layer(layer_state)) {
            case _FIRST:
            case _LEDSET:
            case _TEN:
            case _TENFN:
            case _DVORAK:
                tap_code(clockwise ? KC_WH_U : KC_WH_D);
                break;
            case _MOUSE:
                clockwise ? mouse_move(0, MOUSE_SPEED) : mouse_move(0, - MOUSE_SPEED); 
                break;
            case _FN:
                tap_code(clockwise ? KC_DOWN : KC_UP);
                break;
            case _FN2:
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
                break; 
            case _MFN:
                tap_code(clockwise ? KC_WH_U : KC_WH_D);
                break;
            default:
                break;
        }
    } else if (index == 1) {
        // Right rotary Note:Reverse Rotation
        switch (get_highest_layer(layer_state)) {
            case _FIRST:
            case _LEDSET:
            case _TEN:
            case _TENFN:
            case _DVORAK:
                tap_code(clockwise ? KC_WH_L : KC_WH_R);
                break;
            case _MOUSE:
                clockwise ? mouse_move(MOUSE_SPEED, 0) : mouse_move(- MOUSE_SPEED, 0);  
                break;
            case _FN:
                tap_code(clockwise ? KC_RGHT : KC_LEFT);
                break;
            case _FN2:
                tap_code(clockwise ? KC_BRID : KC_BRIU);
                break;
            case _MFN:
                tap_code(clockwise ? KC_WH_L : KC_WH_R);
                break;
            default:
                break;
        }
    }
}

#endif
