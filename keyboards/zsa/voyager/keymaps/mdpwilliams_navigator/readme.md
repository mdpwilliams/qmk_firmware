# mdpwilliams_navigator

Same keys, layers and lighting as `../mdpwilliams`, plus support for the ZSA
Navigator **trackpad**. It does **not** build in this repository: the trackpad
driver and the `zsa/*` modules only exist in ZSA's fork.

## Building
1. Clone https://github.com/zsa/qmk_firmware on branch `firmware25`
   (`make git-submodule` pulls `modules/zsa`, which is `zsa/qmk_modules`).
2. Copy this folder to `keyboards/zsa/voyager/keymaps/mdpwilliams_navigator/`.
3. Apply the scroll patch to ZSA's module (see below):
   `git -C modules/zsa apply keyboards/zsa/voyager/keymaps/mdpwilliams_navigator/navigator_trackpad_scroll.patch`
4. `make zsa/voyager:mdpwilliams_navigator`

## What is added
- `keymap.json`: enables the `zsa/navigator_trackpad` module (I2C Cirque pad at
  0x58, reported to the host as a touchpad), `zsa/automouse` and `zsa/defaults`.
- `_MOUSE` layer (index 4): `KC_BTN1/2/3` on the home row, F/D/S on the left
  hand and J/K/L on the right. Everything else is transparent.
- `rules.mk`: `POINTING_DEVICE_DRIVER = custom`. The automouse module forces pointing-device
  support on, and the trackpad reports through the digitizer, so without this the build stops
  with "Invalid POINTING_DEVICE_DRIVER".
- `config.h`: `AUTOMOUSE_LAYER 4`, 650 ms timeout, motion threshold 10.
- Lighting: `_MOUSE` keys glow blue while the layer is up.

## Two-finger scroll (macOS)
macOS never switches the pad into Precision Touchpad mode, so the pad runs as a
plain mouse, and ZSA's module has no scroll in that mode (the fallback report has
no wheel). `navigator_trackpad_scroll.patch` patches `modules/zsa` so that two
fingers on the pad scroll by the motion of their midpoint, sent as wheel ticks on
the normal mouse report. Taps are suppressed during a scroll.
- Tunables (in `config.h`): `TRACKPAD_SCROLL_UNITS_PER_NOTCH` (default 60, higher is
  slower), `TRACKPAD_SCROLL_INVERT` (1 reverses vertical), `TRACKPAD_SCROLL_HORIZONTAL`
  (FALSE disables sideways).
- Hosts that do use PTP (Windows) handle scrolling themselves and ignore this.
- Compiles; direction and speed are untested on hardware.

## Notes
- Tracking, taps and scroll gestures are handled by the host as a precision
  touchpad. Tune the pad's feel in your OS settings.
- While the pad is touched, the home row mods are replaced by the mouse buttons
  until the timeout ends. Lower `AUTOMOUSE_TIMEOUT` if that interrupts typing.
- Compiles against ZSA's `firmware25` (commit `93b2b9e`). Not yet tested on hardware; the layer hue (blue) and timings are untested.
