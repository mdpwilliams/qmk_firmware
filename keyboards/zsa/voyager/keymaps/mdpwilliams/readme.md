# ZSA Voyager – mdpwilliams keymap

Four layers with tap-hold home row modifiers.

## Home row mods (base layer)

Tap for the letter, hold for the modifier. Mirrored outward from the
center of the keyboard:

| Finger  | Left | Mod     | Right | Mod     |
|---------|------|---------|-------|---------|
| Pinky   | A    | Control | ;     | Control |
| Ring    | S    | Alt     | L     | Alt     |
| Middle  | D    | Shift   | K     | Shift   |
| Index   | F    | Command (GUI) | J | Command (GUI) |

## Layers

- **Layer 0 (`_BASE`)** – standard QWERTY with the home row mods above.
  Top-left corner is `` ` `` (grave), outer-pinky home-row key is `Esc`
  (swapped from stock QMK's usual placement). The old Caps Word key is
  `Delete` for now — a placeholder pending a better idea. Thumbs, left
  to right: `Enter` (tap) / layer 1 (hold), `Backspace`, `Space`, and
  `Tab` (tap) / layer 2 (hold). The two layer keys are the upper, outer
  key of each thumb cluster.
- **Layer 1 (`_REGEX`)** – held with the **left** thumb. Right-hand
  layout borrowed from [BEAKL Pi's symbols-and-regex
  layer](http://thedarnedestthing.com/beakl%20pi#symbols-and-regex):
  each row pairs an anchor character with a bracket pair around a
  middle symbol — `. [ ^ ] -` / `? ( $ ) _` / `| { # }` — plus `Del`
  on the right hand's inner thumb key (under `Space`) and `\` at its usual key. Numbers stay
  available on the number row for repetition counts like `{2,4}`. The
  left hand carries the navigation cluster: Home/↑/End/PgUp on `W E R T`
  and ←/↓/→/PgDn on `S D F G`.
- **Layer 2 (`_SYMBOLS`)** – held with the **right** thumb. Left hand
  also mirrors BEAKL Pi's symbol rows — `. * & ! -` / `< % > ~ _` /
  `+ @ / |` — with `=` on the left inner thumb; right hand is a
  number pad of keypad keys: `7 8 9 / −` on the Y row, `4 5 6 * +` on the
  home row, and `0 1 2 3 . Enter` on the bottom row (`0` on `N`).
  Navigation lives on the Regex layer. F1–F12 run across the top row.
- **Layer 3 (`_MEDIA`)** – activated automatically when **both** thumb
  layer keys are held together (via QMK's tri-layer helper). Media
  controls run along the left home row — `Next`, `Vol−`, `Vol+`,
  `Play/Pause` on A/S/D/F — plus `QK_BOOT` in the top-right corner for
  entering the bootloader to reflash. The only lighting key is `Toggle`
  (`RM_TOGG`, right half, bottom row, second key), which turns the RGB on and off.

## Lighting

The board runs the **typing heatmap** effect (`config.h`; applied when the
EEPROM is first initialised, then saved). The Media layer can only toggle the
lighting on and off, which keeps the saved effect, so it comes back as the
heatmap. Keys glow from blue through green and
yellow to red the more you type them, and cool off over a few seconds.

While a layer is held, every key that does something on it is lit in the
layer's colour, drawn over the running effect (`keymap.c`,
`rgb_matrix_indicators_advanced_user`):

| Layer    | Colour |
|----------|--------|
| Regex    | teal   |
| Symbols  | pink   |
| Media    | amber  |

The overlay follows the Media-layer brightness setting and is hidden when
lighting is toggled off. The four status LEDs above the thumb clusters keep
showing the active layer in binary.

## Timing

`TAPPING_TERM` (`config.h`) is set to **180ms**, down slightly from
QMK's 200ms default — the max hold time before a tap-hold key (the
home row mods, the two layer-tap thumb keys) commits to being a hold
rather than a tap. Lower it further if holds still feel slow to
register; raise it if taps are misfiring as holds.

## Flashing

```
qmk flash -kb zsa/voyager -km mdpwilliams
```

or use the Wally flashing tool from ZSA with the built
`zsa_voyager_mdpwilliams.bin` file.

### Getting back to the heatmap
The effect, speed, hue and brightness cannot be changed from the keyboard any
more, so the heatmap stays put. If the board is ever on a different effect
(for example after flashing an older build that had the cycle keys), either:
- flash a build that still has `RM_NEXT`/`RM_PREV`, cycle to the typing
  heatmap, then flash this one again; or
- temporarily put `EE_CLR` on a key, build, flash, and press it. That clears the
  saved settings, and `RGB_MATRIX_DEFAULT_MODE` (the heatmap) is applied on the
  next boot. There is no such key in the keymap today.
