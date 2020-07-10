/* Copyright 2018 Jack Humbert
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
#include "quantum.h"
#include "version.h"

#define _BASE 0
#define _FN1 1
#define _MAKE 2

enum custom_keys {
  KC_MAKE = SAFE_RANGE
};

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_MAKE:
    if (record->event.pressed) {
      //uint8_t mods = get_mods(); <- get pressed modifier keys
      //clear_mods();
      //make kingly_keys/romac:mrksdck
      send_string_with_delay_P(PSTR("sudo make " QMK_KEYBOARD ":" QMK_KEYMAP), 1);
      //send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), 10);

      /*if (mods & MOD_MASK_SHIFT) {
        reset_keyboard();
      }*/

    }
    return false;
  }
  return true;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		KC_7, KC_8, OSL(_MAKE), \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		MO(_FN1), KC_F13, KC_F20 \
	),

	[_FN1] = LAYOUT(
		KC_TRNS, KC_HOME, KC_PGUP, \
		KC_TRNS, KC_END, KC_PGDN, \
		KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_ENT \
	),
	

    [_MAKE] = LAYOUT(
		KC_7, KC_8, KC_MAKE, \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		KC_ENT, KC_MAKE, RESET \
	)

};
