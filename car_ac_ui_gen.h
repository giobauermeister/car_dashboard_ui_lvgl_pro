/**
 * @file car_ac_ui_gen.h
 */

#ifndef LVGL_PRO_CAR_AC_UI_GEN_H
#define LVGL_PRO_CAR_AC_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void car_ac_ui_set_target(uint32_t target);
uint32_t car_ac_ui_get_target(void);
bool car_ac_ui_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define CAR_AC_UI_TARGET_UNDEFINED  (0 << 1)
#define CAR_AC_UI_TARGET_TARGET1    (1 << 1)
#define CAR_AC_UI_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef CAR_AC_UI_COMPILE_TARGET
#define CAR_AC_UI_COMPILE_TARGET CAR_AC_UI_TARGET_ALL
#endif

#define CAR_AC_UI_CHECK_COMPILE_TARGET(target) (CAR_AC_UI_COMPILE_TARGET & (target) ? 1 : 0)

#define COLOR_BG (lv_color_hex(0x000000))
#define COLOR_WHITE (lv_color_hex(0xFFFFFF))
#define COLOR_TEXT_DIM (lv_color_hex(0x9A9AA5))
#define COLOR_TEXT_MUTED (lv_color_hex(0x6E6E78))
#define COLOR_RED (lv_color_hex(0xE0193F))
#define COLOR_BLUE (lv_color_hex(0x3A40E0))
#define COLOR_PURPLE (lv_color_hex(0x4B2A9C))
#define COLOR_NAVY (lv_color_hex(0x14163F))
#define COLOR_TICK_IDLE (lv_color_hex(0x27308A))
#define COLOR_LINE (lv_color_hex(0x2A2A30))
#define COLOR_SHEET_TOP (lv_color_hex(0x242426))
#define COLOR_SHEET_BOTTOM (lv_color_hex(0x121214))
#define COLOR_CARD_TOP (lv_color_hex(0x1C1C20))
#define COLOR_CARD_BOTTOM (lv_color_hex(0x141A36))
#define COLOR_CARD_BORDER (lv_color_hex(0x2E303C))
#define COLOR_TRACK (lv_color_hex(0x0B0C12))
#define COLOR_DRAWER (lv_color_hex(0x1C1C1E))
#define SPEEDO_SIZE (480)
#define GEAR_SIZE (360)
#define PANEL_W (110)
#define PANEL_BOX_W (150)
#define PANEL_H (680)
#define RADIUS_ROW (14)
#define RADIUS_CARD (28)
#define RADIUS_SHEET (36)
#define SPACE_PAGE (28)
#define SEG_W (198)
#define SEG_H (70)
#define SHEET_OPEN_Y (140)
#define SHEET_CLOSED_Y (1130)
#define SHEET_H (1200)
#define SHEET_HANDLE_H (150)
#define REF_GEAR_PARK (0)
#define REF_GEAR_DRIVE (1)
#define REF_AC_MODE_PET (0)
#define REF_AC_MODE_NORMAL (1)
#define THRESHOLD_MIN (15)
#define THRESHOLD_MAX (30)


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**
 * Animation path of a style transition with a `bezier(…)` easing. The control
 * points come from the transition descriptor's `user_data`, as a transition
 * descriptor cannot store animation parameters itself.
 */
static inline int32_t car_ac_ui_style_transition_bezier_path_helper(const lv_anim_t * a)
{
    const lv_anim_bezier3_para_t * para = (const lv_anim_bezier3_para_t *)lv_anim_get_user_data(a);
    if(para == NULL) return lv_anim_path_linear(a);

    lv_anim_t a_tmp = *a;
    lv_anim_set_bezier3_param(&a_tmp, para->x1, para->y1, para->x2, para->y2);
    return lv_anim_path_custom_bezier3(&a_tmp);
}

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

extern lv_obj_t * screen_ac;
extern lv_obj_t * screen_controls;
extern lv_obj_t * screen_history;

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_box;
extern lv_style_t style_hidden_part;
extern lv_style_t style_icon;
extern lv_style_t style_icon_dim;
extern lv_style_t style_text_title;
extern lv_style_t style_text_body;
extern lv_style_t style_text_dim;
extern lv_style_t style_gradient;
extern lv_style_t style_pressed;

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_speed;
extern lv_font_t * font_gear;
extern lv_font_t * font_value;
extern lv_font_t * font_title;
extern lv_font_t * font_temp;
extern lv_font_t * font_body;
extern lv_font_t * font_small;
extern lv_font_t * font_unit;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * icon_settings;
extern const void * icon_car;
extern const void * icon_fan;
extern const void * icon_steering;
extern const void * icon_speedometer;
extern const void * icon_wiper;
extern const void * icon_seat_heat;
extern const void * icon_car_door;
extern const void * icon_power;
extern const void * icon_fuel;
extern const void * icon_chevron_left;
extern const void * icon_chevron_right;
extern const void * icon_back;
extern const void * icon_close;
extern const void * icon_minus;
extern const void * icon_plus;
extern const void * icon_paw;
extern const void * icon_thermometer;
extern const void * icon_defrost;
extern const void * icon_wifi;
extern const void * icon_battery;
extern const void * icon_triangle;
extern const void * icon_mode_fan;
extern const void * img_car;
extern const void * img_arc_gear;
extern const void * img_arc_speed;
extern const void * img_panel_left;
extern const void * img_panel_right;
extern const void * icon_park;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t * subject_speed;
extern lv_subject_t * subject_range;
extern lv_subject_t * subject_power;
extern lv_subject_t * subject_gear;
extern lv_subject_t * subject_drive_mode;
extern lv_subject_t * subject_feature;
extern lv_subject_t * subject_intro;
extern lv_subject_t * subject_exterior_temp;
extern lv_subject_t * subject_interior_temp;
extern lv_subject_t * subject_defrost;
extern lv_subject_t * subject_ac_mode;
extern lv_subject_t * subject_temp_control;
extern lv_subject_t * subject_threshold;
extern lv_subject_t * subject_preset;
extern lv_subject_t * subject_sheet_pos;
extern lv_subject_t * subject_settings_open;
extern lv_subject_t * subject_clock;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void scale_section_opa_cb(lv_event_t * e);
void history_open_cb(lv_event_t * e);
void ac_screen_load_cb(lv_event_t * e);
void ac_screen_loaded_cb(lv_event_t * e);
void sheet_handle_event_cb(lv_event_t * e);
void controls_screen_load_cb(lv_event_t * e);
void intro_band_cb(lv_event_t * e);
void intro_speed_cb(lv_event_t * e);
void history_screen_load_cb(lv_event_t * e);
void history_close_cb(lv_event_t * e);

/*----------------
 * Easing Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void car_ac_ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/ac/mode_row_gen.h"
#include "components/ac/segmented_gen.h"
#include "components/base/box_gen.h"
#include "components/base/icon_button_gen.h"
#include "components/base/status_bar_gen.h"
#include "components/controls/gear_dial_gen.h"
#include "components/controls/speedometer_gen.h"
#include "components/settings/history_item_gen.h"
#include "components/settings/settings_drawer_gen.h"
#include "screens/screen_ac_gen.h"
#include "screens/screen_controls_gen.h"
#include "screens/screen_history_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_CAR_AC_UI_GEN_H*/