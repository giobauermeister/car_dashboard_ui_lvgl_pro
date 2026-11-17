/**
 * @file car_ac_ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "car_ac_ui.h"

#if defined(LV_USE_XML) && LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t car_ac_ui_target = CAR_AC_UI_COMPILE_TARGET;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", NULL};
    static const char * translation_tags[] = {"dog", "cat", "house", NULL};
    static const char * translation_texts[] = {
        "This is a dog", "Das ist ein Hund", /* dog */
        "A curious little cat", "Eine neugierige kleine Katze", /* cat */
        "The house is cozy and warm", "Das Haus ist gemütlich und warm", /* house */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * screen_ac = NULL;
lv_obj_t * screen_controls = NULL;
lv_obj_t * screen_history = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_speed;
extern lv_font_t font_speed_data;
lv_font_t * font_gear;
extern lv_font_t font_gear_data;
lv_font_t * font_value;
extern lv_font_t font_value_data;
lv_font_t * font_title;
extern lv_font_t font_title_data;
lv_font_t * font_temp;
extern lv_font_t font_temp_data;
lv_font_t * font_body;
extern lv_font_t font_body_data;
lv_font_t * font_small;
extern lv_font_t font_small_data;
lv_font_t * font_unit;
extern lv_font_t font_unit_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * icon_settings = NULL;
extern const void * icon_settings_data;
const void * icon_car = NULL;
extern const void * icon_car_data;
const void * icon_fan = NULL;
extern const void * icon_fan_data;
const void * icon_steering = NULL;
extern const void * icon_steering_data;
const void * icon_speedometer = NULL;
extern const void * icon_speedometer_data;
const void * icon_wiper = NULL;
extern const void * icon_wiper_data;
const void * icon_seat_heat = NULL;
extern const void * icon_seat_heat_data;
const void * icon_car_door = NULL;
extern const void * icon_car_door_data;
const void * icon_power = NULL;
extern const void * icon_power_data;
const void * icon_fuel = NULL;
extern const void * icon_fuel_data;
const void * icon_chevron_left = NULL;
extern const void * icon_chevron_left_data;
const void * icon_chevron_right = NULL;
extern const void * icon_chevron_right_data;
const void * icon_back = NULL;
extern const void * icon_back_data;
const void * icon_close = NULL;
extern const void * icon_close_data;
const void * icon_minus = NULL;
extern const void * icon_minus_data;
const void * icon_plus = NULL;
extern const void * icon_plus_data;
const void * icon_paw = NULL;
extern const void * icon_paw_data;
const void * icon_thermometer = NULL;
extern const void * icon_thermometer_data;
const void * icon_defrost = NULL;
extern const void * icon_defrost_data;
const void * icon_wifi = NULL;
extern const void * icon_wifi_data;
const void * icon_battery = NULL;
extern const void * icon_battery_data;
const void * icon_triangle = NULL;
extern const void * icon_triangle_data;
const void * icon_mode_fan = NULL;
extern const void * icon_mode_fan_data;
const void * img_car = NULL;
extern const void * img_car_data;
const void * img_arc_gear = NULL;
extern const void * img_arc_gear_data;
const void * img_arc_speed = NULL;
extern const void * img_arc_speed_data;
const void * img_panel_left = NULL;
extern const void * img_panel_left_data;
const void * img_panel_right = NULL;
extern const void * img_panel_right_data;
const void * icon_park = NULL;
extern const void * icon_park_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_box;
lv_style_t style_hidden_part;
lv_style_t style_icon;
lv_style_t style_icon_dim;
lv_style_t style_text_title;
lv_style_t style_text_body;
lv_style_t style_text_dim;
lv_style_t style_gradient;
lv_style_t style_pressed;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t * subject_speed;
lv_subject_t * subject_range;
lv_subject_t * subject_power;
lv_subject_t * subject_gear;
lv_subject_t * subject_drive_mode;
lv_subject_t * subject_feature;
lv_subject_t * subject_intro;
lv_subject_t * subject_exterior_temp;
lv_subject_t * subject_interior_temp;
lv_subject_t * subject_defrost;
lv_subject_t * subject_ac_mode;
lv_subject_t * subject_temp_control;
lv_subject_t * subject_threshold;
lv_subject_t * subject_preset;
lv_subject_t * subject_sheet_pos;
lv_subject_t * subject_settings_open;
lv_subject_t * subject_clock;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void car_ac_ui_init_gen(const char * asset_path)
{
    /* When running from the editor the theme set from the XML should overwrite this */
#if !defined(LV_EDITOR_PREVIEW)
#if LV_USE_THEME_SIMPLE
    lv_display_t * disp = lv_display_get_default();
    lv_theme_t * th = lv_theme_simple_init(disp);
    lv_display_set_theme(disp, th);
#else
    LV_LOG_WARN("Simple theme is selected in project.xml but LV_USE_THEME_SIMPLE is disabled");
#endif
#endif /*LV_EDITOR_PREVIEW*/


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        if (!font_speed) {
            /* font_speed */
            /* get font 'font_speed' from a C array */
            font_speed = &font_speed_data;

        }
        if (!font_gear) {
            /* font_gear */
            /* get font 'font_gear' from a C array */
            font_gear = &font_gear_data;

        }
        if (!font_value) {
            /* font_value */
            /* get font 'font_value' from a C array */
            font_value = &font_value_data;

        }
        if (!font_title) {
            /* font_title */
            /* get font 'font_title' from a C array */
            font_title = &font_title_data;

        }
        if (!font_temp) {
            /* font_temp */
            /* get font 'font_temp' from a C array */
            font_temp = &font_temp_data;

        }
        if (!font_body) {
            /* font_body */
            /* get font 'font_body' from a C array */
            font_body = &font_body_data;

        }
        if (!font_small) {
            /* font_small */
            /* get font 'font_small' from a C array */
            font_small = &font_small_data;

        }
        if (!font_unit) {
            /* font_unit */
            /* get font 'font_unit' from a C array */
            font_unit = &font_unit_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        /* icon_settings */
        if (!icon_settings) {
            icon_settings = &icon_settings_data;
        }
        /* icon_car */
        if (!icon_car) {
            icon_car = &icon_car_data;
        }
        /* icon_fan */
        if (!icon_fan) {
            icon_fan = &icon_fan_data;
        }
        /* icon_steering */
        if (!icon_steering) {
            icon_steering = &icon_steering_data;
        }
        /* icon_speedometer */
        if (!icon_speedometer) {
            icon_speedometer = &icon_speedometer_data;
        }
        /* icon_wiper */
        if (!icon_wiper) {
            icon_wiper = &icon_wiper_data;
        }
        /* icon_seat_heat */
        if (!icon_seat_heat) {
            icon_seat_heat = &icon_seat_heat_data;
        }
        /* icon_car_door */
        if (!icon_car_door) {
            icon_car_door = &icon_car_door_data;
        }
        /* icon_power */
        if (!icon_power) {
            icon_power = &icon_power_data;
        }
        /* icon_fuel */
        if (!icon_fuel) {
            icon_fuel = &icon_fuel_data;
        }
        /* icon_chevron_left */
        if (!icon_chevron_left) {
            icon_chevron_left = &icon_chevron_left_data;
        }
        /* icon_chevron_right */
        if (!icon_chevron_right) {
            icon_chevron_right = &icon_chevron_right_data;
        }
        /* icon_back */
        if (!icon_back) {
            icon_back = &icon_back_data;
        }
        /* icon_close */
        if (!icon_close) {
            icon_close = &icon_close_data;
        }
        /* icon_minus */
        if (!icon_minus) {
            icon_minus = &icon_minus_data;
        }
        /* icon_plus */
        if (!icon_plus) {
            icon_plus = &icon_plus_data;
        }
        /* icon_paw */
        if (!icon_paw) {
            icon_paw = &icon_paw_data;
        }
        /* icon_thermometer */
        if (!icon_thermometer) {
            icon_thermometer = &icon_thermometer_data;
        }
        /* icon_defrost */
        if (!icon_defrost) {
            icon_defrost = &icon_defrost_data;
        }
        /* icon_wifi */
        if (!icon_wifi) {
            icon_wifi = &icon_wifi_data;
        }
        /* icon_battery */
        if (!icon_battery) {
            icon_battery = &icon_battery_data;
        }
        /* icon_triangle */
        if (!icon_triangle) {
            icon_triangle = &icon_triangle_data;
        }
        /* icon_mode_fan */
        if (!icon_mode_fan) {
            icon_mode_fan = &icon_mode_fan_data;
        }
        /* img_car */
        if (!img_car) {
            img_car = &img_car_data;
        }
        /* img_arc_gear */
        if (!img_arc_gear) {
            img_arc_gear = &img_arc_gear_data;
        }
        /* img_arc_speed */
        if (!img_arc_speed) {
            img_arc_speed = &img_arc_speed_data;
        }
        /* img_panel_left */
        if (!img_panel_left) {
            img_panel_left = &img_panel_left_data;
        }
        /* img_panel_right */
        if (!img_panel_right) {
            img_panel_right = &img_panel_right_data;
        }
        /* icon_park */
        if (!icon_park) {
            icon_park = &icon_park_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_box);
        lv_style_init(&style_hidden_part);
        lv_style_init(&style_icon);
        lv_style_init(&style_icon_dim);
        lv_style_init(&style_text_title);
        lv_style_init(&style_text_body);
        lv_style_init(&style_text_dim);
        lv_style_init(&style_gradient);
        lv_style_init(&style_pressed);

        lv_style_set_bg_opa(&style_box, 0);
        lv_style_set_border_width(&style_box, 0);
        lv_style_set_outline_width(&style_box, 0);
        lv_style_set_shadow_width(&style_box, 0);
        lv_style_set_pad_all(&style_box, 0);
        lv_style_set_radius(&style_box, 0);
        lv_style_set_bg_opa(&style_hidden_part, 0);
        lv_style_set_arc_opa(&style_hidden_part, 0);
        lv_style_set_border_width(&style_hidden_part, 0);
        lv_style_set_pad_all(&style_hidden_part, 0);
        lv_style_set_image_recolor(&style_icon, COLOR_WHITE);
        lv_style_set_image_recolor_opa(&style_icon, 255);
        lv_style_set_image_recolor(&style_icon_dim, COLOR_TEXT_DIM);
        lv_style_set_image_recolor_opa(&style_icon_dim, 255);
        lv_style_set_text_font(&style_text_title, font_title);
        lv_style_set_text_color(&style_text_title, COLOR_WHITE);
        lv_style_set_text_font(&style_text_body, font_body);
        lv_style_set_text_color(&style_text_body, COLOR_WHITE);
        lv_style_set_text_font(&style_text_dim, font_small);
        lv_style_set_text_color(&style_text_dim, COLOR_TEXT_DIM);
        lv_style_set_bg_opa(&style_gradient, 255);
        lv_style_set_bg_color(&style_gradient, COLOR_PURPLE);
        lv_style_set_bg_grad_color(&style_gradient, COLOR_RED);
        lv_style_set_bg_grad_dir(&style_gradient, LV_GRAD_DIR_HOR);
        lv_style_set_opa(&style_pressed, (255 * 60 / 100));

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    subject_speed = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_speed, 0);
    lv_subject_set_max_value_int(subject_speed, 120);
    lv_subject_set_int(subject_speed, 60);
    subject_range = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(subject_range, 200);
    subject_power = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_power, 0);
    lv_subject_set_max_value_int(subject_power, 1);
    lv_subject_set_int(subject_power, 1);
    subject_gear = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_gear, 0);
    lv_subject_set_max_value_int(subject_gear, 1);
    lv_subject_set_int(subject_gear, 1);
    subject_drive_mode = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_drive_mode, 0);
    lv_subject_set_max_value_int(subject_drive_mode, 2);
    lv_subject_set_int(subject_drive_mode, 2);
    subject_feature = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_feature, 0);
    lv_subject_set_max_value_int(subject_feature, 3);
    lv_subject_set_int(subject_feature, 0);
    subject_intro = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_intro, 0);
    lv_subject_set_max_value_int(subject_intro, 1);
    lv_subject_set_int(subject_intro, 0);
    subject_exterior_temp = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(subject_exterior_temp, 32);
    subject_interior_temp = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(subject_interior_temp, 20);
    subject_defrost = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_defrost, 0);
    lv_subject_set_max_value_int(subject_defrost, 1);
    lv_subject_set_int(subject_defrost, 0);
    subject_ac_mode = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_ac_mode, 0);
    lv_subject_set_max_value_int(subject_ac_mode, 1);
    lv_subject_set_int(subject_ac_mode, 1);
    subject_temp_control = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_temp_control, 0);
    lv_subject_set_max_value_int(subject_temp_control, 2);
    lv_subject_set_int(subject_temp_control, 2);
    subject_threshold = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_threshold, 15);
    lv_subject_set_max_value_int(subject_threshold, 30);
    lv_subject_set_int(subject_threshold, 26);
    subject_preset = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_preset, 0);
    lv_subject_set_max_value_int(subject_preset, 2);
    lv_subject_set_int(subject_preset, 1);
    subject_sheet_pos = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_sheet_pos, 0);
    lv_subject_set_max_value_int(subject_sheet_pos, 100);
    lv_subject_set_int(subject_sheet_pos, 0);
    subject_settings_open = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_min_value_int(subject_settings_open, 0);
    lv_subject_set_max_value_int(subject_settings_open, 1);
    lv_subject_set_int(subject_settings_open, 0);
    static char subject_clock_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_clock_prev_buf[UI_SUBJECT_STRING_LENGTH];
    subject_clock = lv_subject_create(LV_SUBJECT_TYPE_STRING);
    lv_subject_set_string_buffer_static(subject_clock, subject_clock_buf, subject_clock_prev_buf, UI_SUBJECT_STRING_LENGTH);
    lv_subject_set_string(subject_clock, "02:58");

    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_speed, "font_speed");
    check_font(&font_gear, "font_gear");
    check_font(&font_value, "font_value");
    check_font(&font_title, "font_title");
    check_font(&font_temp, "font_temp");
    check_font(&font_body, "font_body");
    check_font(&font_small, "font_small");
    check_font(&font_unit, "font_unit");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_speed", font_speed);
    lv_xml_register_font(NULL, "font_gear", font_gear);
    lv_xml_register_font(NULL, "font_value", font_value);
    lv_xml_register_font(NULL, "font_title", font_title);
    lv_xml_register_font(NULL, "font_temp", font_temp);
    lv_xml_register_font(NULL, "font_body", font_body);
    lv_xml_register_font(NULL, "font_small", font_small);
    lv_xml_register_font(NULL, "font_unit", font_unit);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_speed", subject_speed);
    lv_xml_register_subject(NULL, "subject_range", subject_range);
    lv_xml_register_subject(NULL, "subject_power", subject_power);
    lv_xml_register_subject(NULL, "subject_gear", subject_gear);
    lv_xml_register_subject(NULL, "subject_drive_mode", subject_drive_mode);
    lv_xml_register_subject(NULL, "subject_feature", subject_feature);
    lv_xml_register_subject(NULL, "subject_intro", subject_intro);
    lv_xml_register_subject(NULL, "subject_exterior_temp", subject_exterior_temp);
    lv_xml_register_subject(NULL, "subject_interior_temp", subject_interior_temp);
    lv_xml_register_subject(NULL, "subject_defrost", subject_defrost);
    lv_xml_register_subject(NULL, "subject_ac_mode", subject_ac_mode);
    lv_xml_register_subject(NULL, "subject_temp_control", subject_temp_control);
    lv_xml_register_subject(NULL, "subject_threshold", subject_threshold);
    lv_xml_register_subject(NULL, "subject_preset", subject_preset);
    lv_xml_register_subject(NULL, "subject_sheet_pos", subject_sheet_pos);
    lv_xml_register_subject(NULL, "subject_settings_open", subject_settings_open);
    lv_xml_register_subject(NULL, "subject_clock", subject_clock);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "scale_section_opa_cb", scale_section_opa_cb);
    lv_xml_register_event_cb(NULL, "history_open_cb", history_open_cb);
    lv_xml_register_event_cb(NULL, "ac_screen_load_cb", ac_screen_load_cb);
    lv_xml_register_event_cb(NULL, "ac_screen_loaded_cb", ac_screen_loaded_cb);
    lv_xml_register_event_cb(NULL, "sheet_handle_event_cb", sheet_handle_event_cb);
    lv_xml_register_event_cb(NULL, "controls_screen_load_cb", controls_screen_load_cb);
    lv_xml_register_event_cb(NULL, "intro_band_cb", intro_band_cb);
    lv_xml_register_event_cb(NULL, "intro_speed_cb", intro_speed_cb);
    lv_xml_register_event_cb(NULL, "history_screen_load_cb", history_screen_load_cb);
    lv_xml_register_event_cb(NULL, "history_close_cb", history_close_cb);

    /* Register easing callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "icon_settings", icon_settings);
    lv_xml_register_image(NULL, "icon_car", icon_car);
    lv_xml_register_image(NULL, "icon_fan", icon_fan);
    lv_xml_register_image(NULL, "icon_steering", icon_steering);
    lv_xml_register_image(NULL, "icon_speedometer", icon_speedometer);
    lv_xml_register_image(NULL, "icon_wiper", icon_wiper);
    lv_xml_register_image(NULL, "icon_seat_heat", icon_seat_heat);
    lv_xml_register_image(NULL, "icon_car_door", icon_car_door);
    lv_xml_register_image(NULL, "icon_power", icon_power);
    lv_xml_register_image(NULL, "icon_fuel", icon_fuel);
    lv_xml_register_image(NULL, "icon_chevron_left", icon_chevron_left);
    lv_xml_register_image(NULL, "icon_chevron_right", icon_chevron_right);
    lv_xml_register_image(NULL, "icon_back", icon_back);
    lv_xml_register_image(NULL, "icon_close", icon_close);
    lv_xml_register_image(NULL, "icon_minus", icon_minus);
    lv_xml_register_image(NULL, "icon_plus", icon_plus);
    lv_xml_register_image(NULL, "icon_paw", icon_paw);
    lv_xml_register_image(NULL, "icon_thermometer", icon_thermometer);
    lv_xml_register_image(NULL, "icon_defrost", icon_defrost);
    lv_xml_register_image(NULL, "icon_wifi", icon_wifi);
    lv_xml_register_image(NULL, "icon_battery", icon_battery);
    lv_xml_register_image(NULL, "icon_triangle", icon_triangle);
    lv_xml_register_image(NULL, "icon_mode_fan", icon_mode_fan);
    lv_xml_register_image(NULL, "img_car", img_car);
    lv_xml_register_image(NULL, "img_arc_gear", img_arc_gear);
    lv_xml_register_image(NULL, "img_arc_speed", img_arc_speed);
    lv_xml_register_image(NULL, "img_panel_left", img_panel_left);
    lv_xml_register_image(NULL, "img_panel_right", img_panel_right);
    lv_xml_register_image(NULL, "icon_park", icon_park);
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
    /* Create all the permanent screens first so that they can reference each other */
    screen_ac = lv_obj_create(NULL);
    screen_controls = lv_obj_create(NULL);
    screen_history = lv_obj_create(NULL);

    screen_ac_create();
    screen_controls_create();
    screen_history_create();
#endif
}

void car_ac_ui_set_target(uint32_t target)
{
    car_ac_ui_target = target;
}

uint32_t car_ac_ui_get_target(void)
{
    return car_ac_ui_target;
}

bool car_ac_ui_check_target(uint32_t target)
{
    return (car_ac_ui_target & target) ? true : false;
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) scale_section_opa_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("scale_section_opa_cb was called\n");
}
void __attribute__((weak)) history_open_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("history_open_cb was called\n");
}
void __attribute__((weak)) ac_screen_load_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("ac_screen_load_cb was called\n");
}
void __attribute__((weak)) ac_screen_loaded_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("ac_screen_loaded_cb was called\n");
}
void __attribute__((weak)) sheet_handle_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("sheet_handle_event_cb was called\n");
}
void __attribute__((weak)) controls_screen_load_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("controls_screen_load_cb was called\n");
}
void __attribute__((weak)) intro_band_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("intro_band_cb was called\n");
}
void __attribute__((weak)) intro_speed_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("intro_speed_cb was called\n");
}
void __attribute__((weak)) history_screen_load_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("history_screen_load_cb was called\n");
}
void __attribute__((weak)) history_close_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("history_close_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}