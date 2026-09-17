// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _REGEX,   // right-hand regex/bracket symbols, held with the left thumb
    _SYMBOLS, // left-hand extra symbols + right-hand nav, held with the right thumb
    _MEDIA,   // music/volume control, held with both thumbs together
};

// Shifted symbols with no plain KC_* alias, used as ordinary (non mod-tap) keycodes below.
#define KC_LABK S(KC_COMMA) // <
#define KC_RABK S(KC_DOT)   // >

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_BSPC, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,                                KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,
        KC_NO,   KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,                                KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_BSLS,
        KC_ESC,  CTL_T(KC_A), ALT_T(KC_S), SFT_T(KC_D), GUI_T(KC_F), KC_G,                                KC_H,        RGUI_T(KC_J),RSFT_T(KC_K),RALT_T(KC_L),RCTL_T(KC_SCLN),KC_QUOT,
        KC_LGUI, KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,                                KC_N,        KC_M,        KC_COMMA,    KC_DOT,      KC_SLSH,     KC_RCTL,
                                            LT(_REGEX, KC_ENT), KC_TAB,               KC_BSPC, LT(_SYMBOLS, KC_SPC)
    ),
    // Regex/symbol placement borrowed from BEAKL Pi's symbols-and-regex layer
    // (thedarnedestthing.com/beakl pi): each row pairs an anchor character
    // with a bracket pair around a middle symbol -- . [ ^ ] / ? ( $ ) / | { # }.
    [_REGEX] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        _______, _______, _______, _______, _______, _______,                      KC_DOT,  KC_LBRC, KC_CIRC, KC_RBRC, KC_MINS, KC_BSLS,
        _______, _______, _______, _______, _______, _______,                      KC_QUES, KC_LPRN, KC_DLR,  KC_RPRN, KC_UNDS, _______,
        _______, _______, _______, _______, _______, _______,                      KC_PIPE, KC_LCBR, KC_HASH, KC_RCBR, _______, _______,
                                            _______, _______,             KC_DEL,  _______
    ),
    // Left hand mirrors BEAKL Pi's symbol rows (. * & / < % > ~ / + @ / |);
    // right hand gets its nav cluster (Home/Up/End/PgUp, Left/Down/Right/PgDn).
    [_SYMBOLS] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_DOT,  KC_ASTR, KC_AMPR, KC_EXLM, KC_MINS,                      _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, KC_LABK, KC_PERC, KC_RABK, KC_TILD, KC_UNDS,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, KC_PLUS, KC_AT,   KC_SLSH, KC_PIPE, _______,                      _______, _______, _______, _______, _______, _______,
                                            _______, KC_EQL,              _______, _______
    ),
    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______,                      _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                            _______, _______,             _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _REGEX, _SYMBOLS, _MEDIA);
}
