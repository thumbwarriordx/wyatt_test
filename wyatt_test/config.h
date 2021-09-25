/*
Copyright 2021 Wyatt

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//#include "i2c_master.h"
#pragma once

//#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER Wyatt
#define PRODUCT      wyatt_test

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 10

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_COL_PINS {  D1,  C0, B0,  B1,  B3, B2, D5, D6, C1, C2 }
// { 23, 22, 21, 20, 19, 18, 17, 16, 15, 14 }
#define MATRIX_ROW_PINS {  C2,  C1, D6,  D5,  B2, B3, B1, B0, C0, D1 }
// { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }

/*
#define MATRIX_ROW_PINS {  C2,  C1, D6,  D5,  B2, B3, C8, C9, C0, D1 }

#define MATRIX_COL_PINS { B16, B17, D0, A12, A13, D7, D4, D2, D3, C3 }
*/
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

//deprecated
//#define NUMBER_OF_ENCODERS 4
#define ENCODERS_PAD_A {  A5, E1, C8, B18 } // { 24, 26, 28, 32 }
#define ENCODERS_PAD_B { B19, C9, E0, A4  } // { 25, 27, 31, 33 }
//#define ENCODERS_PAD_A {  A5 } // { 24, 26, 28, 32 }
//#define ENCODERS_PAD_B { B19  } // { 25, 27, 31, 33 }
#define ENCODER_RESOLUTIONS { 4,4,4,4 }  

#define USB_POLLING_INTERVAL_MS 2
#define MATRIX_IO_DELAY 10

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
#define LED_CAPS_LOCK_PIN C5
//#define LED_SCROLL_LOCK_PIN C11
//#define LED_NUM_LOCK_PIN C10


/*
#define I2C1_CLOCK_SPEED 400000
#define I2C1_SCL_PAL_MODE PAL_MODE_ALTERNATIVE_2
#define I2C1_SDA_PAL_MODE PAL_MODE_ALTERNATIVE_2
#define I2C1_BANK GPIOB
#define I2C1_SCL 0
#define I2C1_SDA 1
*/


/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
