// Copyright 2026 imfred
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUM,
    _SYM,
    _NAV
};

enum {
    TD_BSP
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BSP] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LCTL(KC_BSPC))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *                          BASE
     * ┌───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │              │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │              │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │ Z │ X │ C │ V │ B │              │ N │ M │ , │ . │ / │
     * └───┴───┼───┼───┤───┤              ├───┼───┼───┼───┴───┘
     *         │ESC│SPC│TAB│              │ENT│BAC│DEL│
     *         └───┴───┴───┘              └───┴───┴───┘
     *             _NUM _NAV              _SYM
     *                           NUM
     * ┌───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │              │   │   │   │   │   │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │ 1 │ 2 │ 3 │ 4 │ 5 │              │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │   │   │   │   │   │              │   │   │   │   │   │
     * └───┴───┼───┼───┤───┤              ├───┼───┼───┼───┴───┘
     *         │   │   │   │              │   │   │   │
     *         └───┴───┴───┘              └───┴───┴───┘
     *                  _NUM              _SYM
     *                          SYMBOL
     * ┌───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┐
     * │ " │ & │ * │ { │ } │              │   │   │   │   │   │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │ : │ $ │ % │ [ │ ] │              │   │   │   │   │   │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │ ' │ ! │ @ │ - │ + │              │   │   │   │   │   │
     * └───┴───┼───┼───┤───┤              ├───┼───┼───┼───┴───┘
     *         │ ( │ ) | _ │              │   │   │   │
     *         └───┴───┴───┘              └───┴───┴───┘
     *                  _NUM              _SYM
     *
     *
     *                           NAV
     * ┌───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┐
     * │pwr│   │   │   │   │              │   │   │   │   │   │
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │slp│   │vld│vlu│   │              │   │LFT│DWN│UP │RHT│
     * ├───┼───┼───┼───┤───┤              ├───┼───┼───┼───┤───┤
     * │   │   │   │   │   │              │   │   │   │   │   │
     * └───┴───┼───┼───┤───┤              ├───┼───┼───┼───┴───┘
     *         │   │   │   │              │HOM│bot│END│
     *         └───┴───┴───┘              └───┴───┴───┘
     *                  _NUM              _SYM
     *
     */

    [_BASE] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R,       KC_T,                               KC_Y,   KC_U,   KC_I,       KC_O,       KC_P,
        MT(MOD_LGUI, KC_A),  MT(MOD_LALT,KC_S),   MT(MOD_LCTL,KC_D),   MT(MOD_LSFT,KC_F),       KC_G,                               KC_H,   MT(MOD_RSFT,KC_J),   MT(MOD_RCTL,KC_K),       MT(MOD_RALT,KC_L),       MT(MOD_RGUI,KC_SEMICOLON),
        KC_Z,   KC_X,   KC_C,   KC_V,       KC_B,                               KC_N,   KC_M,   KC_COMM,    KC_DOT,     KC_SLASH,
        KC_NO,  KC_NO,  KC_ESC, LT(_NUM, KC_SPC),LT(_NAV, KC_TAB),              LT(_SYM, KC_ENTER), TD(TD_BSP),  KC_DEL,    KC_NO,    KC_NO
    ),

    [_NUM] = LAYOUT(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,  KC_NO,  KC_LSFT,  KC_NO,  KC_NO
    ),


    [_SYM] = LAYOUT(
        KC_DQT, KC_AMPR,   KC_ASTR, KC_LCBR,  KC_RCBR,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_COLON, KC_DLR, KC_PERC, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_QUOTE,  KC_EXLM, KC_AT, KC_MINS, KC_PLUS,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_UNDS,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    [_NAV] = LAYOUT(
        KC_PWR,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_SLEP,  KC_NO,  KC_VOLD,  KC_VOLU,  KC_NO,                              KC_NO,  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_HOME,  QK_BOOT,  KC_END,  KC_NO,  KC_NO
    )
};
