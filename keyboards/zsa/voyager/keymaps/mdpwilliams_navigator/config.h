// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// How long a tap-hold key (home row mods, layer-tap thumbs) must be held
// before it registers as a hold instead of a tap. QMK's default is 200ms;
// trimmed down slightly here.
#define TAPPING_TERM 180

// Start on the typing heatmap rather than the rainbow sweep. This default is
// only applied when the keyboard's EEPROM is first initialised; after that the
// Media layer only toggles the RGB on and off, so the saved mode persists.
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

// Navigator trackpad: the automouse module raises this layer (_MOUSE in
// keymap.c, index 4) while the pad is touched and drops it after the timeout.
// Keep the number in step with the layer enum.
#define AUTOMOUSE_LAYER 4
#define AUTOMOUSE_TIMEOUT 300
#define AUTOMOUSE_THRESHOLD 10

// Two-finger scroll (needs navigator_trackpad_scroll.patch, see readme): reverse
// the vertical direction to suit macOS.
#define TRACKPAD_SCROLL_INVERT 1
