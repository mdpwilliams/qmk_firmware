# mdpwilliams — Keychron K3 Pro (ANSI, RGB)

Record copy of a keymap that builds against **Keychron's** QMK fork, not this one.
This fork has no `keyboards/keychron/k3_pro` board definition, so it will not
compile here.

## Provenance
- Base: Keychron's `default` keymap for `k3_pro/ansi/rgb`
- Source: https://github.com/Keychron/qmk_firmware, branch `wireless_playground`,
  commit `666862c` ("Add Q2 Max JIS")
- Changes: home row mods on both base layers (Mac and Windows), `TAPPING_TERM` 180,
  VIA enabled (same as Keychron's `via` keymap), and lighting limited to the typing heatmap

## Home row mods
| Hand  | Keys                                  |
|-------|---------------------------------------|
| Left  | A = Ctrl, S = Alt, D = Shift, F = GUI |
| Right | J = GUI, K = Shift, L = Alt, ; = Ctrl |

## Lighting
Keychron's `info.json` enables 21 RGB effects. `config.h` undefines all but
`TYPING_HEATMAP`, which is also the default mode, and `keyboard_post_init_user()`
forces it on boot in case EEPROM from stock firmware holds a removed mode. The
Fn-layer mode keys (`RGB_MOD`/`RGB_RMOD`) therefore have nothing else to cycle to;
brightness, hue, saturation, speed and on/off still work. Checked by symbol: only
`TYPING_HEATMAP` is in the compiled firmware (65 KB -> 54 KB).

## Building
Clone Keychron's fork (read-only; never push there), copy this folder to
`keyboards/keychron/k3_pro/ansi/rgb/keymaps/mdpwilliams/`, fetch the submodules,
then run:

    make keychron/k3_pro/ansi/rgb:mdpwilliams

Compiled cleanly on 2026-10-15; not yet tested on hardware.

## Flashing
Set the mode switch to Off, connect USB, hold Esc (or the reset button under the
space bar), then switch to Cable to enter the bootloader.
