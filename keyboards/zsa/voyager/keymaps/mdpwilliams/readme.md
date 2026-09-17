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
  (swapped from stock QMK's usual placement); Backspace lives on the
  right inner thumb. The old Caps Word key is `Delete` for now — a
  placeholder pending a better idea. Left inner thumb key is `Enter`
  (tap) / layer 1 (hold). Right inner thumb key is `Space` (tap) /
  layer 2 (hold).
- **Layer 1 (`_REGEX`)** – held with the **left** thumb. Right-hand
  layout borrowed from [BEAKL Pi's symbols-and-regex
  layer](http://thedarnedestthing.com/beakl%20pi#symbols-and-regex):
  each row pairs an anchor character with a bracket pair around a
  middle symbol — `. [ ^ ] -` / `? ( $ ) _` / `| { # }` — plus `Del`
  on the right inner thumb and `\` at its usual key. Numbers stay
  available on the left hand for repetition counts like `{2,4}`.
- **Layer 2 (`_SYMBOLS`)** – held with the **right** thumb. Left hand
  also mirrors BEAKL Pi's symbol rows — `. * & ! -` / `< % > ~ _` /
  `+ @ / |` — with `=` on the left inner thumb; right hand gets a
  navigation cluster (Home/↑/End/PgUp, ←/↓/→/PgDn) instead. F1–F12
  run across the top row.
- **Layer 3 (`_MEDIA`)** – activated automatically when **both** thumb
  layer keys are held together (via QMK's tri-layer helper). Volume
  and media transport controls sit on the right hand, plus `QK_BOOT`
  in the top-right corner for entering the bootloader to reflash.

## Flashing

```
qmk flash -kb zsa/voyager -km mdpwilliams
```

or use the Wally flashing tool from ZSA with the built
`zsa_voyager_mdpwilliams.bin` file.
