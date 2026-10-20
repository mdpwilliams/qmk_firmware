// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// How long a tap-hold key (home row mods, layer-tap thumbs) must be held
// before it registers as a hold instead of a tap. QMK's default is 200ms;
// trimmed down slightly here.
#define TAPPING_TERM 180

// Start on the typing heatmap rather than the rainbow sweep. This default is
// only applied when the keyboard's EEPROM is first initialised; after that the
// RGB keys on the Media layer change the mode, and the setting persists.
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

// Navigator trackpad: the automouse module raises this layer (_MOUSE in
// keymap.c, index 4) while the pad is touched and drops it after the timeout.
// Keep the number in step with the layer enum.
#define AUTOMOUSE_LAYER 4
#define AUTOMOUSE_TIMEOUT 650
#define AUTOMOUSE_THRESHOLD 10
