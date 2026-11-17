/**
 * @file car_ac_logic.h
 *
 * Hand-written logic of the car A/C UI: what the XML cannot express with bindings.
 *
 * - The intro of screen_controls plays once per screen object: C pulses `subject_intro`,
 *   which starts the timeline of the XML. The timeline also drives the speed and the band
 *   of the gear dial, through two empty objects whose `translate_x` C copies into them.
 * - The Mode Control sheet of screen_ac follows the finger and snaps open or closed.
 *   Its position is published in `subject_sheet_pos` (0..100), which the XML binds
 *   the car image to.
 * - Every change of `subject_threshold` is logged, and screen_history lists the log.
 * - `subject_preset` copies its temperature into `subject_threshold`.
 * - `subject_power` ramps `subject_speed` down to 0 and back up.
 * - `subject_clock` is kept up to date.
 *
 * The `*_cb` functions are the `<event_cb>` callbacks of the XML files; they are
 * declared in car_ac_ui_gen.h.
 */

#ifndef CAR_AC_LOGIC_H
#define CAR_AC_LOGIC_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Start the logic. Call it after car_ac_ui_init_gen(), which creates the subjects.
 */
void car_ac_logic_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CAR_AC_LOGIC_H*/
