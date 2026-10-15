# mdpwilliams — Keychron K3 Pro (ANSI, RGB)

Record copy of a keymap that builds against **Keychron's** QMK fork, not this one.
This fork has no `keyboards/keychron/k3_pro` board definition, so it will not
compile here.

## Provenance
- Base: Keychron's `default` keymap for `k3_pro/ansi/rgb`
- Source: https://github.com/Keychron/qmk_firmware, branch `wireless_playground`,
  commit `666862c` ("Add Q2 Max JIS")
- Changes: home row mods on both base layers (Mac and Windows), `TAPPING_TERM` 180,
  VIA enabled (same as Keychron's `via` keymap)

## Home row mods
| Hand  | Keys                                  |
|-------|---------------------------------------|
| Left  | A = Ctrl, S = Alt, D = Shift, F = GUI |
| Right | J = GUI, K = Shift, L = Alt, ; = Ctrl |

## Building
Clone Keychron's fork (read-only; never push there), copy this folder to
`keyboards/keychron/k3_pro/ansi/rgb/keymaps/mdpwilliams/`, fetch the submodules,
then run:

    make keychron/k3_pro/ansi/rgb:mdpwilliams

Compiled cleanly on 2026-10-15; not yet tested on hardware.

## Flashing
Set the mode switch to Off, connect USB, hold Esc (or the reset button under the
space bar), then switch to Cable to enter the bootloader.
