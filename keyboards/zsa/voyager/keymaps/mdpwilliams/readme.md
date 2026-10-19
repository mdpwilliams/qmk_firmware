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
  to right: `Enter` (tap) / layer 1 (hold), `Backspace`, then on the
  right hand `Space` (tap) / layer 2 (hold), and `Tab` on the outer key.
- **Layer 1 (`_REGEX`)** – held with the **left** thumb. Right-hand
  layout borrowed from [BEAKL Pi's symbols-and-regex
  layer](http://thedarnedestthing.com/beakl%20pi#symbols-and-regex):
  each row pairs an anchor character with a bracket pair around a
  middle symbol — `. [ ^ ] -` / `? ( $ ) _` / `| { # }` — plus `Del`
  on the right hand's outer thumb key (under `Tab`) and `\` at its usual key. Numbers stay
  available on the left hand for repetition counts like `{2,4}`.
- **Layer 2 (`_SYMBOLS`)** – held with the **right** thumb. Left hand
  also mirrors BEAKL Pi's symbol rows — `. * & ! -` / `< % > ~ _` /
  `+ @ / |` — with `=` on the left inner thumb; right hand gets a
  navigation cluster (Home/↑/End/PgUp, ←/↓/→/PgDn) instead. F1–F12
  run across the top row.
- **Layer 3 (`_MEDIA`)** – activated automatically when **both** thumb
  layer keys are held together (via QMK's tri-layer helper). Media
  controls run along the left home row — `Next`, `Vol−`, `Vol+`,
  `Play/Pause` on A/S/D/F — plus `QK_BOOT` in the top-right corner for
  entering the bootloader to reflash. The right half carries the RGB
  controls: `Prev`/`Next` effect and `Speed−`/`Speed+` (Y row), `Hue−`/
  `Hue+` and `Bright−`/`Bright+` (home row), and `Toggle` plus
  `Sat−`/`Sat+` (bottom row).

## Lighting

The board boots into the **typing heatmap** effect (`config.h`; applied
when the EEPROM is first initialised, after which the Media-layer RGB keys
and their saved settings take over). Keys glow from blue through green and
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
