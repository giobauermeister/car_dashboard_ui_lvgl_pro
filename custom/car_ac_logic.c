/**
 * @file car_ac_logic.c
 *
 * See car_ac_logic.h.
 */

/*********************
 *      INCLUDES
 *********************/

#include "car_ac_logic.h"
#include "../car_ac_ui.h"

/*********************
 *      DEFINES
 *********************/

#define SHEET_ANIM_MS       450
#define SHEET_INTRO_DELAY   350     /* The car is shown alone for a moment */
#define SHEET_TAP_LIMIT     12      /* A press that moves less than this is a tap */

#define HISTORY_MAX         40
#define HISTORY_LOG_DELAY   700     /* Log a threshold once it has stopped changing */
#define HISTORY_ANIM_MS     350

#define PRESET_BASE_TEMP    18
#define PRESET_STEP_TEMP    4

#define CRUISE_SPEED        60
#define SPEED_ANIM_MS       1200

/* The clock starts here, as there is no RTC behind the demo */
#define CLOCK_START_SEC     (2 * 3600 + 58 * 60 + 15)

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    uint8_t hour;       /* 0..23 */
    uint8_t minute;
    int8_t temp;
} history_entry_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static bool intro_value_get(lv_event_t * e, int32_t * value);

static void sheet_set_y(lv_obj_t * sheet, int32_t y);
static void sheet_anim_cb(void * sheet, int32_t y);
static void sheet_slide(lv_obj_t * sheet, bool open, uint32_t delay);

static void history_add(uint8_t hour, uint8_t minute, int8_t temp);
static void history_log_timer_cb(lv_timer_t * timer);

static void threshold_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
static void preset_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
static void power_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
static void speed_anim_cb(void * subject, int32_t v);

static uint32_t clock_now(void);
static void clock_timer_cb(lv_timer_t * timer);

/**********************
 *  STATIC VARIABLES
 **********************/

/* Newest first */
static history_entry_t history[HISTORY_MAX];
static uint32_t history_cnt;
static lv_timer_t * history_log_timer;

/* The screen the history was opened from, to return to it */
static lv_obj_t * history_origin;

/* Set while returning from the history: the sheet stays as it was left */
static bool sheet_keep;

/* The observers are notified once when they are added. Nothing changed then. */
static bool observers_ready;

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void car_ac_logic_init(void)
{
    /* What the list shows before the first change, oldest first */
    static const history_entry_t seed[] = {
        {0, 19, 27}, {0, 19, 26}, {0, 20, 23}, {0, 21, 17}, {0, 21, 21}, {0, 21, 26}, {0, 21, 18},
        {0, 21, 22}, {2, 51, 29}, {2, 51, 24}, {2, 51, 18}, {2, 51, 26}, {2, 56, 17}, {2, 56, 26},
        {2, 56, 18}, {2, 57, 30}, {2, 57, 20}, {2, 57, 18}, {2, 57, 26},
    };

    history_cnt = 0;
    for(uint32_t i = 0; i < sizeof(seed) / sizeof(seed[0]); i++) {
        history_add(seed[i].hour, seed[i].minute, seed[i].temp);
    }

    history_log_timer = lv_timer_create(history_log_timer_cb, HISTORY_LOG_DELAY, NULL);
    lv_timer_pause(history_log_timer);

    observers_ready = false;
    lv_subject_add_observer(subject_threshold, threshold_observer_cb, NULL);
    lv_subject_add_observer(subject_preset, preset_observer_cb, NULL);
    lv_subject_add_observer(subject_power, power_observer_cb, NULL);
    observers_ready = true;

    lv_timer_t * clock_timer = lv_timer_create(clock_timer_cb, 1000, NULL);
    clock_timer_cb(clock_timer);
}

/* screen_controls starts to load: play the intro, once per screen object and not once per
 * run. The Editor's preview creates the screen again on every reload while the subjects
 * keep their values, and the intro has to play there too. Coming back from another screen
 * loads the same object, which is marked here. */
void controls_screen_load_cb(lv_event_t * e)
{
    lv_obj_t * screen = lv_event_get_current_target_obj(e);

    if(lv_obj_get_user_data(screen)) return;
    lv_obj_set_user_data(screen, (void *)(lv_uintptr_t)1);

    /* The timeline of the XML plays when this turns 1 */
    lv_subject_set_int(subject_intro, 0);
    lv_subject_set_int(subject_intro, 1);
}

/* The intro timeline can only animate style properties, but the values of the two dials are
 * a subject and an arc angle. So it animates `translate_x` of two empty objects of
 * screen_controls.xml instead, and these callbacks copy that number into the real value on
 * every step. The timeline stays the only clock: it also works from the Editor's
 * Animations panel. */
void intro_speed_cb(lv_event_t * e)
{
    int32_t speed;

    if(!intro_value_get(e, &speed)) return;
    if(lv_subject_get_int(subject_power) == 0) return;

    lv_subject_set_int(subject_speed, speed);
}

void intro_band_cb(lv_event_t * e)
{
    int32_t angle;

    if(!intro_value_get(e, &angle)) return;

    lv_obj_t * band = lv_obj_find_by_name(lv_obj_get_screen(lv_event_get_current_target_obj(e)), "gear_band");
    if(band) lv_arc_set_bg_end_angle(band, angle % 360);
}

/* Works around lv_scale (LVGL 9.6): a tick inside a section is drawn with the plain line_opa
 * of the section or of the scale, without the opacity inherited from the parents. While
 * screen_controls fades in, or the speedometer fades in during the intro, the red ticks and
 * the bright dot were at full opacity from the first frame. This mixes the inherited
 * opacity into those ticks. The ticks outside a section already have it, so they are
 * recognised by their value and left alone. Needs `send_draw_task_events` on the scale. */
void scale_section_opa_cb(lv_event_t * e)
{
    lv_draw_task_t * task = lv_event_get_draw_task(e);
    if(lv_draw_task_get_type(task) != LV_DRAW_TASK_TYPE_LINE) return;

    lv_draw_line_dsc_t * dsc = lv_draw_task_get_line_dsc(task);
    lv_part_t part = dsc->base.part;
    if(part != LV_PART_INDICATOR && part != LV_PART_ITEMS) return;

    /* The same opacity lv_obj_init_draw_line_dsc() mixes into the other ticks */
    lv_obj_t * scale = lv_event_get_current_target_obj(e);
    lv_opa_t inherited = lv_obj_get_style_opa_recursive(scale, part);
    if(inherited >= LV_OPA_MAX) return;

    lv_opa_t outside = LV_OPA_MIX2(lv_obj_get_style_line_opa(scale, part), inherited);
    if(dsc->opa != outside) dsc->opa = LV_OPA_MIX2(dsc->opa, inherited);
}

/* screen_ac starts to load: show the car alone, with the sheet closed */
void ac_screen_load_cb(lv_event_t * e)
{
    lv_obj_t * sheet = lv_obj_find_by_name(lv_event_get_current_target_obj(e), "sheet");

    if(sheet == NULL || sheet_keep) return;

    lv_anim_delete(sheet, sheet_anim_cb);
    sheet_set_y(sheet, SHEET_CLOSED_Y);
}

/* screen_ac is loaded: slide the sheet open */
void ac_screen_loaded_cb(lv_event_t * e)
{
    lv_obj_t * sheet = lv_obj_find_by_name(lv_event_get_current_target_obj(e), "sheet");

    if(sheet == NULL) return;

    if(sheet_keep) {
        sheet_keep = false;
        return;
    }

    sheet_slide(sheet, true, SHEET_INTRO_DELAY);
}

/* The header of the sheet: the sheet follows the finger, and on release it slides
 * open or closed. A tap toggles it. */
void sheet_handle_event_cb(lv_event_t * e)
{
    static lv_point_t press_point;
    static int32_t press_y;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * sheet = lv_obj_get_parent(lv_event_get_current_target_obj(e));
    lv_indev_t * indev = lv_indev_active();

    if(indev == NULL) return;

    if(code == LV_EVENT_PRESSED) {
        lv_anim_delete(sheet, sheet_anim_cb);
        lv_indev_get_point(indev, &press_point);
        press_y = lv_obj_get_y_aligned(sheet);
    }
    else if(code == LV_EVENT_PRESSING) {
        lv_point_t point;
        lv_indev_get_point(indev, &point);
        sheet_set_y(sheet, press_y + point.y - press_point.y);
    }
    else if(code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
        lv_point_t point;
        lv_indev_get_point(indev, &point);

        int32_t moved = point.y - press_point.y;
        bool open;
        if(LV_ABS(moved) < SHEET_TAP_LIMIT) open = press_y != SHEET_OPEN_Y;
        else open = moved < 0;

        sheet_slide(sheet, open, 0);
    }
}

/* The Temperature History row of the settings drawer. The XML loads the screen. */
void history_open_cb(lv_event_t * e)
{
    history_origin = lv_obj_get_screen(lv_event_get_current_target_obj(e));
    lv_subject_set_int(subject_settings_open, 0);
}

/* screen_history starts to load: list the log */
void history_screen_load_cb(lv_event_t * e)
{
    lv_obj_t * list = lv_obj_find_by_name(lv_event_get_current_target_obj(e), "history_list");

    if(list == NULL) return;

    lv_obj_clean(list);

    for(uint32_t i = 0; i < history_cnt; i++) {
        char time[16];
        char temp[8];
        uint32_t hour12 = history[i].hour % 12;
        if(hour12 == 0) hour12 = 12;

        lv_snprintf(time, sizeof(time), "%d:%02d %s", (int)hour12, (int)history[i].minute,
                    history[i].hour < 12 ? "AM" : "PM");
        lv_snprintf(temp, sizeof(temp), "%d°", (int)history[i].temp);

#if defined(LV_EDITOR_PREVIEW)
        /* The preview builds the UI from XML */
        const char * attrs[] = {"time", time, "temp", temp, NULL, NULL};
        lv_xml_create(list, "history_item", attrs);
#else
        history_item_create(list, time, temp);
#endif
    }

    lv_obj_scroll_to_y(lv_obj_get_parent(list), 0, LV_ANIM_OFF);
}

/* The close button of screen_history: back to where it was opened from */
void history_close_cb(lv_event_t * e)
{
    LV_UNUSED(e);

    if(history_origin == NULL || !lv_obj_is_valid(history_origin)) return;

    sheet_keep = true;
    lv_screen_load_anim(history_origin, LV_SCREEN_LOAD_ANIM_OUT_BOTTOM, HISTORY_ANIM_MS, 0, false);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* The number an animation of the timeline has put into `translate_x` of the event's object.
 * False until one did: the style is also refreshed when the object is created. */
static bool intro_value_get(lv_event_t * e, int32_t * value)
{
    lv_style_value_t v;

    if(lv_obj_get_local_style_prop(lv_event_get_current_target_obj(e), LV_STYLE_TRANSLATE_X, &v, 0) != LV_STYLE_RES_FOUND) {
        return false;
    }

    *value = v.num;
    return true;
}

static void sheet_set_y(lv_obj_t * sheet, int32_t y)
{
    y = LV_CLAMP(SHEET_OPEN_Y, y, SHEET_CLOSED_Y);

    lv_obj_set_y(sheet, y);
    lv_subject_set_int(subject_sheet_pos, (SHEET_CLOSED_Y - y) * 100 / (SHEET_CLOSED_Y - SHEET_OPEN_Y));
}

static void sheet_anim_cb(void * sheet, int32_t y)
{
    sheet_set_y(sheet, y);
}

static void sheet_slide(lv_obj_t * sheet, bool open, uint32_t delay)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, sheet);
    lv_anim_set_exec_cb(&a, sheet_anim_cb);
    lv_anim_set_values(&a, lv_obj_get_y_aligned(sheet), open ? SHEET_OPEN_Y : SHEET_CLOSED_Y);
    lv_anim_set_duration(&a, SHEET_ANIM_MS);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_start(&a);
}

static void history_add(uint8_t hour, uint8_t minute, int8_t temp)
{
    uint32_t keep = LV_MIN(history_cnt, HISTORY_MAX - 1);

    for(uint32_t i = keep; i > 0; i--) history[i] = history[i - 1];

    history[0].hour = hour;
    history[0].minute = minute;
    history[0].temp = temp;
    history_cnt = keep + 1;
}

static void history_log_timer_cb(lv_timer_t * timer)
{
    uint32_t now = clock_now();

    lv_timer_pause(timer);
    history_add((uint8_t)(now / 3600), (uint8_t)(now / 60 % 60), (int8_t)lv_subject_get_int(subject_threshold));
}

static void threshold_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(observer);
    LV_UNUSED(subject);

    if(!observers_ready) return;

    /* Holding + or - changes the value many times: log only where it settles */
    lv_timer_reset(history_log_timer);
    lv_timer_resume(history_log_timer);
}

static void preset_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(observer);

    if(!observers_ready) return;

    lv_subject_set_int(subject_threshold, PRESET_BASE_TEMP + PRESET_STEP_TEMP * lv_subject_get_int(subject));
}

static void power_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(observer);

    if(!observers_ready) return;

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, subject_speed);
    lv_anim_set_exec_cb(&a, speed_anim_cb);
    lv_anim_set_values(&a, lv_subject_get_int(subject_speed), lv_subject_get_int(subject) ? CRUISE_SPEED : 0);
    lv_anim_set_duration(&a, SPEED_ANIM_MS);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
    lv_anim_start(&a);
}

static void speed_anim_cb(void * subject, int32_t v)
{
    lv_subject_set_int(subject, v);
}

/* Seconds since midnight */
static uint32_t clock_now(void)
{
    return (CLOCK_START_SEC + lv_tick_get() / 1000) % (24 * 3600);
}

static void clock_timer_cb(lv_timer_t * timer)
{
    LV_UNUSED(timer);

    char buf[8];
    uint32_t now = clock_now();

    lv_snprintf(buf, sizeof(buf), "%02d:%02d", (int)(now / 3600), (int)(now / 60 % 60));
    lv_subject_copy_string(subject_clock, buf);
}
