/*
Copyright 2020 Ayden <aydenvis@gmail.com>

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

#pragma once

#define DEVICE_VER      0x0001

// wiring of each half
#define MATRIX_ROW_PINS { B4, C6, D7, E6 }
#define MATRIX_COL_PINS { B5, F5, D1, F4, D2 }

#define SOFT_SERIAL_PIN D3

#define USE_SERIAL
#define MASTER_LEFT

//RGB
#define RGB_DI_PIN B0
#define RGBLED_NUM 12
#define RGBLIGHT_LIMIT_VAL 255

// Encoders
#define ENCODERS_PAD_A { B6 }
#define ENCODERS_PAD_B { B2 }

#define ENCODERS_PAD_A_RIGHT { B2 }
#define ENCODERS_PAD_B_RIGHT { B6 }
#define ENCODER_RESOLUTION 4

//Mouse
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 50
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_WHEEL_DELAY 300
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define TAPPING_TERM 175
#define IGNORE_MOD_TAP_INTERRUPT //for use with tapdance keymap
