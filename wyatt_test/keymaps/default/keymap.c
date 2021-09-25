/* Copyright 2021 Wyatt
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
#include "pointing_device.h"
//#include "i2c_master.h"

/*

uint8_t encoderByte[1] = { 0 };
uint8_t I2C_SLAVE_ADDR = 0;//(1 << 1);
void keyboard_post_init_user(){
    palSetPadMode(GPIOB, 0, PAL_MODE_ALTERNATIVE_2); // PTB0/I2C0/SCL
    palSetPadMode(GPIOB, 1, PAL_MODE_ALTERNATIVE_2);
    i2c_init();
    //i2c_start(100);
    i2cStart(&I2CD1, &i2ccfg);
    //i2c_receive(uint8_t address, uint8_t* data, uint16_t length, uint16_t timeout);
    //i2c_receive(I2C_SLAVE_ADDR, encoderByte, 1, 100);
    for (int i=0; i<127;i++){
        
    i2c_transmit(I2C_SLAVE_ADDR, encoderByte, 1, 100);
    I2C_SLAVE_ADDR++;
    }
    i2c_stop();
    //i2c_receive(9, encoderByte, 1, 100);

    
}

void matrix_scan_user(void) {
    i2c_start(100);
    //i2c_receive(I2C_SLAVE_ADDR, encoderByte, 1, 100);
    i2c_transmit(I2C_SLAVE_ADDR, encoderByte, 1, 100);
    i2c_stop();
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT(
    KC_ESC,  KC_F1,KC_F2,KC_F3,KC_F4,  KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9,KC_F10,KC_F11,KC_F12,       KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,   KC_BSPC,         KC_INS,         KC_NLCK,KC_PSLS,KC_PAST,KC_MINS, \
     KC_TAB, KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC, KC_BSLS,        KC_DEL,         KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_PLUS, \
      KC_LCAP, KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,   KC_ENT,                          KC_KP_4,KC_KP_5,KC_KP_6,    \
       KC_LSHIFT,  KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,  KC_RSHIFT,                       KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_ENTER, \
     KC_LCTL, KC_LGUI, KC_LALT,  KC_NO  ,     KC_SPC        ,KC_RALT,KC_RGUI,KC_APP,KC_RCTL,    KC_PSCREEN,     KC_KP_0,KC_KP_0,KC_KP_DOT     \

    ),
/*    [1] = LAYOUT(
    _______,  _______,_______,_______,_______,  _______,_______,_______,_______,  _______,_______,_______,_______,    _______,   _______,   _______,   _______,  \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,      _______,   _______,_______,_______,_______, \
     _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______,      _______,   _______,_______,_______,_______, \
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,                      _______,_______,_______,    \
       _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,                           _______,_______,_______,_______, \
     _______,   _______,   _______,    _______    ,              _______          , _______, _______, _______, _______,      _______,   _______,_______,_______     \

    )
*/
};


//Rotary Encoders

int sensMult = 1;
int encoderCCW[4] = { 0 , 0 };
int encoderCW[4] = { 0 , 0 };

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder
        uint8_t layer = biton32(layer_state);
            switch (layer) {
            case 0:
            case 1:
            case 2:
                if (clockwise) {

                sensMult = 1;
                encoderCW[index]++;
                if ( (encoderCW[index] % sensMult) == 0 ){
                    tap_code(KC_RIGHT);
                    encoderCW[index] = 0;
                }
            } else {
                encoderCCW[index]++;
                if ( (encoderCCW[index] % sensMult) == 0){
                    tap_code(KC_LEFT);
                    encoderCCW[index]=0;
                }
            }
            break;
            case 3:

            sensMult = 18;
            report_mouse_t currentReport = pointing_device_get_report();
                if (clockwise) {
                    //tap_code16(KC_MS_RIGHT);
                    currentReport.y = -sensMult;
                } else {
                    //tap_code16(KC_MS_LEFT);
                    currentReport.y = sensMult;
                }
            pointing_device_set_report(currentReport);
            pointing_device_send();
            break;
            }
            
    }

    if (index == 1) { // First encoder
        uint8_t layer = biton32(layer_state);
            switch (layer) {
            case 0:
            case 1:
            case 2:
                if (clockwise) {

                sensMult = 1;
                encoderCW[index]++;
                if ( (encoderCW[index] % sensMult) == 0 ){
                    tap_code(KC_RIGHT);
                    encoderCW[index] = 0;
                }
            } else {
                encoderCCW[index]++;
                if ( (encoderCCW[index] % sensMult) == 0){
                    tap_code(KC_LEFT);
                    encoderCCW[index]=0;
                }
            }
            break;
            case 3:

            sensMult = 18;
            report_mouse_t currentReport = pointing_device_get_report();
                if (clockwise) {
                    //tap_code16(KC_MS_RIGHT);
                    currentReport.y = -sensMult;
                } else {
                    //tap_code16(KC_MS_LEFT);
                    currentReport.y = sensMult;
                }
            pointing_device_set_report(currentReport);
            pointing_device_send();
            break;
            }
            
    }

        if (index == 2) { // First encoder
        uint8_t layer = biton32(layer_state);
            switch (layer) {
            case 0:
            case 1:
            case 2:
                if (clockwise) {

                sensMult = 1;
                encoderCW[index]++;
                if ( (encoderCW[index] % sensMult) == 0 ){
                    tap_code(KC_RIGHT);
                    encoderCW[index] = 0;
                }
            } else {
                encoderCCW[index]++;
                if ( (encoderCCW[index] % sensMult) == 0){
                    tap_code(KC_LEFT);
                    encoderCCW[index]=0;
                }
            }
            break;
            case 3:

            sensMult = 18;
            report_mouse_t currentReport = pointing_device_get_report();
                if (clockwise) {
                    //tap_code16(KC_MS_RIGHT);
                    currentReport.y = -sensMult;
                } else {
                    //tap_code16(KC_MS_LEFT);
                    currentReport.y = sensMult;
                }
            pointing_device_set_report(currentReport);
            pointing_device_send();
            break;
            }
            
    }

        if (index == 3) { // First encoder
        uint8_t layer = biton32(layer_state);
            switch (layer) {
            case 0:
            case 1:
            case 2:
                if (clockwise) {

                sensMult = 1;
                encoderCW[index]++;
                if ( (encoderCW[index] % sensMult) == 0 ){
                    tap_code(KC_RIGHT);
                    encoderCW[index] = 0;
                }
            } else {
                encoderCCW[index]++;
                if ( (encoderCCW[index] % sensMult) == 0){
                    tap_code(KC_LEFT);
                    encoderCCW[index]=0;
                }
            }
            break;
            case 3:

            sensMult = 18;
            report_mouse_t currentReport = pointing_device_get_report();
                if (clockwise) {
                    //tap_code16(KC_MS_RIGHT);
                    currentReport.y = -sensMult;
                } else {
                    //tap_code16(KC_MS_LEFT);
                    currentReport.y = sensMult;
                }
            pointing_device_set_report(currentReport);
            pointing_device_send();
            break;
            }
            
    }
    return true;
}

/*
    if (index == 1) { // Second encoder
        uint8_t layer = biton32(layer_state);
            switch (layer) {
            case 0:
            case 1:
            case 2:

            if (clockwise) {

                sensMult = 4;
                encoderCW[index]++;
                if ( (encoderCW[index] % sensMult) == 0 ){
                    tap_code(KC_RIGHT);
                    encoderCW[index]=0;
                }
            } else {
                encoderCCW[index]++;
                if ( (encoderCCW[index] % sensMult) == 0){
                    tap_code(KC_LEFT);
                    encoderCCW[index]=0;
                }
            }
            break;
            case 3:

            sensMult = 18;
            report_mouse_t currentReport = pointing_device_get_report();
                if (clockwise) {
                    //tap_code(KC_MS_DOWN);
                    currentReport.x = sensMult;
                } else {
                    //tap_code(KC_MS_UP);
                    currentReport.x = -sensMult;
                }
            pointing_device_set_report(currentReport);
            pointing_device_send();
            break;

        }
      
    }
    return true;
}
*/