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
#define MATRIX_ROW_PINS { B1, B5, B4, E6 }
#define MATRIX_COL_PINS { D4, D0, F5, F6, F7 }

#define SOFT_SERIAL_PIN D1

#define USE_SERIAL
#define MASTER_LEFT

#define RGB_DI_PIN F4
#define RGBLED_NUM 12
#define RGBLIGHT_LIMIT_VAL 255

#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D7 }

#define ENCODERS_PAD_A_RIGHT { D7 }
#define ENCODERS_PAD_B_RIGHT { C6 }


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
