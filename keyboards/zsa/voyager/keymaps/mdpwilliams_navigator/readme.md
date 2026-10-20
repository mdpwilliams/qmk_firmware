# mdpwilliams_navigator

Same keys, layers and lighting as `../mdpwilliams`, plus support for the ZSA
Navigator **trackpad**. It does **not** build in this repository: the trackpad
driver and the `zsa/*` modules only exist in ZSA's fork.

## Building
1. Clone https://github.com/zsa/qmk_firmware on branch `firmware25`
   (`make git-submodule` pulls `modules/zsa`, which is `zsa/qmk_modules`).
2. Copy this folder to `keyboards/zsa/voyager/keymaps/mdpwilliams_navigator/`.
3. `make zsa/voyager:mdpwilliams_navigator`

## What is added
- `keymap.json`: enables the `zsa/navigator_trackpad` module (I2C Cirque pad at
  0x58, reported to the host as a touchpad), `zsa/automouse` and `zsa/defaults`.
- `_MOUSE` layer (index 4): `KC_BTN1/2/3` on the home row, F/D/S on the left
  hand and J/K/L on the right. Everything else is transparent.
- `config.h`: `AUTOMOUSE_LAYER 4`, 650 ms timeout, motion threshold 10.
- Lighting: `_MOUSE` keys glow blue while the layer is up.

## Notes
- Tracking, taps and scroll gestures are handled by the host as a precision
  touchpad. Tune the pad's feel in your OS settings.
- While the pad is touched, the home row mods are replaced by the mouse buttons
  until the timeout ends. Lower `AUTOMOUSE_TIMEOUT` if that interrupts typing.
- Not compiled or flashed yet; the layer hue (blue) and timings are untested.
