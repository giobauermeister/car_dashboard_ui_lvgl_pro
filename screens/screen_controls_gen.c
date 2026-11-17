/**
 * @file screen_controls_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_controls_gen.h"
#include "../car_ac_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* Index is the <COMP>_TIMELINE_* enum. Kept here rather than the root's
     * user_data, which stays free for the user. */
    lv_anim_timeline_t ** timelines;

    /* One bit per `{…}` trigger, so only a false-to-true edge fires */
    uint8_t play_timeline_event_lv_obj_0_prev : 1;
} screen_controls_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_timeline_intro_create(lv_obj_t * obj);

static uint32_t screen_controls_get_instance_event;
static void screen_controls_get_instance_cb(lv_event_t * e);
static screen_controls_t * screen_controls_get_instance(lv_obj_t * obj);
static void screen_controls_destroy_instance(screen_controls_t * inst);
static void screen_controls_delete_cb(lv_event_t * e);
/* Private event code for a condition trigger. One per XML element, never per
 * instance, so it cannot run away. */
static lv_event_code_t screen_controls_play_timeline_event_trigger_code;
static lv_style_t * screen_controls_style_power_off_ref; /* set in create(), read by a binding callback */
static void screen_controls_lv_obj_0_play_timeline_event_cond_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_set_subject_cb(lv_event_t * e);
static void screen_controls_set_subject_cb_2(lv_event_t * e);
static void screen_controls_box_0_style_enabled_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_icon_button_2_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_set_subject_cb_3(lv_event_t * e);
static void screen_controls_icon_button_4_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_set_subject_cb_4(lv_event_t * e);
static void screen_controls_icon_button_5_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_set_subject_cb_5(lv_event_t * e);
static void screen_controls_icon_button_6_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_set_subject_cb_6(lv_event_t * e);
static void screen_controls_icon_button_7_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_controls_set_subject_cb_7(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_controls_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`screen_controls` is already initialized as a permanent screen. Returning with no change.");
        return screen_controls;
    }

    static lv_style_t style_screen;
    static lv_style_t style_power_ring;
    static lv_style_t style_power;
    static lv_style_t style_power_off;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen);
        lv_style_init(&style_power_ring);
        lv_style_init(&style_power);
        lv_style_init(&style_power_off);

        lv_style_set_bg_color(&style_screen, COLOR_BG);
        lv_style_set_bg_opa(&style_screen, 255);
        lv_style_set_radius(&style_power_ring, 1000);
        lv_style_set_bg_opa(&style_power_ring, 255);
        lv_style_set_bg_color(&style_power_ring, lv_color_hex(0x0A0A12));
        lv_style_set_border_width(&style_power_ring, 2);
        lv_style_set_border_color(&style_power_ring, lv_color_hex(0x2A2A36));
        lv_style_set_radius(&style_power, 1000);
        lv_style_set_bg_opa(&style_power, 255);
        lv_style_set_bg_color(&style_power, COLOR_PURPLE);
        lv_style_set_bg_grad_color(&style_power, COLOR_RED);
        lv_style_set_bg_grad_dir(&style_power, LV_GRAD_DIR_VER);
        lv_style_set_bg_color(&style_power_off, lv_color_hex(0x2A2A36));
        lv_style_set_bg_grad_color(&style_power_off, lv_color_hex(0x3A3A46));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    if(screen_controls_get_instance_event == 0) screen_controls_get_instance_event = lv_event_register_id();
    screen_controls_t * inst = lv_malloc(sizeof(screen_controls_t));
    lv_memzero(inst, sizeof(screen_controls_t));

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = screen_controls;
        lv_obj_set_name_static(lv_obj_0, "screen_controls_#");
        lv_obj_add_event_cb(lv_obj_0, screen_controls_get_instance_cb, screen_controls_get_instance_event, inst);
        lv_obj_set_scrollable(lv_obj_0, false);

        lv_obj_add_style(lv_obj_0, &style_screen, 0);
        lv_obj_add_event_cb(lv_obj_0, controls_screen_load_cb, LV_EVENT_SCREEN_LOAD_START, NULL);
        if(screen_controls_play_timeline_event_trigger_code == 0) screen_controls_play_timeline_event_trigger_code = lv_event_register_id();
        lv_obj_t * intro_band = box_create(lv_obj_0);
        lv_obj_set_name(intro_band, "intro_band");
        lv_obj_set_width(intro_band, 0);
        lv_obj_set_height(intro_band, 0);
        lv_obj_add_event_cb(intro_band, intro_band_cb, LV_EVENT_STYLE_CHANGED, NULL);

        lv_obj_t * intro_speed = box_create(lv_obj_0);
        lv_obj_set_name(intro_speed, "intro_speed");
        lv_obj_set_width(intro_speed, 0);
        lv_obj_set_height(intro_speed, 0);
        lv_obj_add_event_cb(intro_speed, intro_speed_cb, LV_EVENT_STYLE_CHANGED, NULL);

        status_bar_create(lv_obj_0);

        lv_obj_t * title = box_create(lv_obj_0);
        lv_obj_set_name(title, "title");
        lv_obj_set_width(title, lv_pct(100));
        lv_obj_set_height(title, 64);
        lv_obj_set_y(title, 60);
        lv_obj_t * lv_label_0 = lv_label_create(title);
        lv_label_set_text(lv_label_0, "Controls");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_label_0, &style_text_title, 0);

        lv_obj_t * lv_image_0 = lv_image_create(title);
        lv_image_set_src(lv_image_0, icon_settings);
        lv_obj_set_align(lv_image_0, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_image_0, -52);
        lv_obj_set_clickable(lv_image_0, true);
        lv_obj_set_ext_click_area(lv_image_0, 20);
        lv_obj_add_style(lv_image_0, &style_icon_dim, 0);
        lv_obj_add_style(lv_image_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(lv_image_0, screen_controls_set_subject_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * speedo = speedometer_create(lv_obj_0);
        lv_obj_set_name(speedo, "speedo");
        lv_obj_set_align(speedo, LV_ALIGN_TOP_MID);
        lv_obj_set_y(speedo, 130);

        lv_obj_t * gear = gear_dial_create(lv_obj_0);
        lv_obj_set_name(gear, "gear");
        lv_obj_set_align(gear, LV_ALIGN_TOP_MID);
        lv_obj_set_y(gear, 654);
        lv_obj_set_style_transform_pivot_x(gear, lv_pct(50), 0);
        lv_obj_set_style_transform_pivot_y(gear, lv_pct(50), 0);

        lv_obj_t * power = box_create(lv_obj_0);
        lv_obj_set_name(power, "power");
        lv_obj_set_width(power, 130);
        lv_obj_set_height(power, 130);
        lv_obj_set_align(power, LV_ALIGN_TOP_MID);
        lv_obj_set_y(power, 1104);
        lv_obj_set_clickable(power, true);
        lv_obj_add_style(power, &style_power_ring, 0);
        lv_obj_add_style(power, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(power, screen_controls_set_subject_cb_2, LV_EVENT_CLICKED, NULL);
        lv_obj_t * box_0 = box_create(power);
        lv_obj_set_width(box_0, 100);
        lv_obj_set_height(box_0, 100);
        lv_obj_set_align(box_0, LV_ALIGN_CENTER);
        lv_obj_set_clickable(box_0, false);
        lv_obj_add_style(box_0, &style_power, 0);
        lv_obj_add_style(box_0, &style_power_off, 0);
        screen_controls_style_power_off_ref = &style_power_off;
        lv_subject_add_observer_obj(subject_power, screen_controls_box_0_style_enabled_cb, box_0, NULL);
        lv_obj_t * lv_image_1 = lv_image_create(box_0);
        lv_image_set_src(lv_image_1, icon_power);
        lv_obj_set_align(lv_image_1, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_image_1, &style_icon, 0);

        lv_obj_t * panel_left = box_create(lv_obj_0);
        lv_obj_set_name(panel_left, "panel_left");
        lv_obj_set_width(panel_left, PANEL_BOX_W);
        lv_obj_set_height(panel_left, PANEL_H);
        lv_obj_set_x(panel_left, 14);
        lv_obj_set_y(panel_left, 578);
        lv_obj_set_style_transform_pivot_x(panel_left, 0, 0);
        lv_obj_set_style_transform_pivot_y(panel_left, lv_pct(50), 0);
        lv_obj_t * lv_image_2 = lv_image_create(panel_left);
        lv_image_set_src(lv_image_2, img_panel_left);

        lv_obj_t * icons_left = box_create(panel_left);
        lv_obj_set_name(icons_left, "icons_left");
        lv_obj_set_width(icons_left, PANEL_W);
        lv_obj_set_height(icons_left, lv_pct(100));
        lv_obj_t * icon_button_0 = icon_button_create(icons_left, icon_car, false);
        lv_obj_set_align(icon_button_0, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_0, 93);

        lv_obj_t * icon_button_1 = icon_button_create(icons_left, icon_fan, false);
        lv_obj_set_align(icon_button_1, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_1, 230);
        lv_obj_add_screen_load_event(icon_button_1, LV_EVENT_CLICKED, screen_ac, LV_SCREEN_LOAD_ANIM_FADE_IN, 500, 0);

        lv_obj_t * icon_button_2 = icon_button_create(icons_left, icon_park, lv_subject_get_int(subject_gear) == REF_GEAR_PARK);
        lv_obj_set_align(icon_button_2, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_2, 364);
        lv_subject_add_observer_obj(subject_gear, screen_controls_icon_button_2_active_binding_cb, icon_button_2, NULL);
        lv_obj_add_event_cb(icon_button_2, screen_controls_set_subject_cb_3, LV_EVENT_CLICKED, NULL);

        lv_obj_t * icon_button_3 = icon_button_create(icons_left, icon_steering, false);
        lv_obj_set_align(icon_button_3, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_3, 499);

        lv_obj_t * panel_right = box_create(lv_obj_0);
        lv_obj_set_name(panel_right, "panel_right");
        lv_obj_set_width(panel_right, PANEL_BOX_W);
        lv_obj_set_height(panel_right, PANEL_H);
        lv_obj_set_align(panel_right, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(panel_right, -14);
        lv_obj_set_y(panel_right, 578);
        lv_obj_set_style_transform_pivot_x(panel_right, lv_pct(100), 0);
        lv_obj_set_style_transform_pivot_y(panel_right, lv_pct(50), 0);
        lv_obj_t * lv_image_3 = lv_image_create(panel_right);
        lv_image_set_src(lv_image_3, img_panel_right);
        lv_obj_set_align(lv_image_3, LV_ALIGN_TOP_RIGHT);

        lv_obj_t * icons_right = box_create(panel_right);
        lv_obj_set_name(icons_right, "icons_right");
        lv_obj_set_width(icons_right, PANEL_W);
        lv_obj_set_height(icons_right, lv_pct(100));
        lv_obj_set_align(icons_right, LV_ALIGN_TOP_RIGHT);
        lv_obj_t * icon_button_4 = icon_button_create(icons_right, icon_speedometer, lv_subject_get_int(subject_feature) == 0);
        lv_obj_set_align(icon_button_4, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_4, 93);
        lv_subject_add_observer_obj(subject_feature, screen_controls_icon_button_4_active_binding_cb, icon_button_4, NULL);
        lv_obj_add_event_cb(icon_button_4, screen_controls_set_subject_cb_4, LV_EVENT_CLICKED, NULL);

        lv_obj_t * icon_button_5 = icon_button_create(icons_right, icon_wiper, lv_subject_get_int(subject_feature) == 1);
        lv_obj_set_align(icon_button_5, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_5, 230);
        lv_subject_add_observer_obj(subject_feature, screen_controls_icon_button_5_active_binding_cb, icon_button_5, NULL);
        lv_obj_add_event_cb(icon_button_5, screen_controls_set_subject_cb_5, LV_EVENT_CLICKED, NULL);

        lv_obj_t * icon_button_6 = icon_button_create(icons_right, icon_seat_heat, lv_subject_get_int(subject_feature) == 2);
        lv_obj_set_align(icon_button_6, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_6, 364);
        lv_subject_add_observer_obj(subject_feature, screen_controls_icon_button_6_active_binding_cb, icon_button_6, NULL);
        lv_obj_add_event_cb(icon_button_6, screen_controls_set_subject_cb_6, LV_EVENT_CLICKED, NULL);

        lv_obj_t * icon_button_7 = icon_button_create(icons_right, icon_car_door, lv_subject_get_int(subject_feature) == 3);
        lv_obj_set_align(icon_button_7, LV_ALIGN_TOP_MID);
        lv_obj_set_y(icon_button_7, 499);
        lv_subject_add_observer_obj(subject_feature, screen_controls_icon_button_7_active_binding_cb, icon_button_7, NULL);
        lv_obj_add_event_cb(icon_button_7, screen_controls_set_subject_cb_7, LV_EVENT_CLICKED, NULL);

        settings_drawer_create(lv_obj_0);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_CONTROLS_TIMELINE_CNT);
        at_array[SCREEN_CONTROLS_TIMELINE_TIMELINE_INTRO] = timeline_timeline_intro_create(lv_obj_0);
        inst->timelines = at_array;

        lv_obj_add_play_timeline_event(lv_obj_0, screen_controls_play_timeline_event_trigger_code, screen_controls_get_timeline(lv_obj_0, SCREEN_CONTROLS_TIMELINE_TIMELINE_INTRO), 0, false);
        lv_subject_add_observer_obj(subject_intro, screen_controls_lv_obj_0_play_timeline_event_cond_cb, lv_obj_0, inst);

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, screen_controls_delete_cb, LV_EVENT_DELETE, inst);
    else screen_controls_destroy_instance(inst); /* no target matched, so nothing owns it */

    if (the_root) screen_created = true;

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_controls_get_timeline(lv_obj_t * obj, screen_controls_timeline_t timeline_id)
{
    if ((uint32_t)timeline_id >= _SCREEN_CONTROLS_TIMELINE_CNT) {
        LV_LOG_WARN("screen_controls has no timeline with %d ID", timeline_id);
        return NULL;
    }

    screen_controls_t * inst = screen_controls_get_instance(obj);
    return inst ? inst->timelines[timeline_id] : NULL;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_timeline_intro_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "gear"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 250);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_SCALE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "gear"));
    lv_anim_set_values(&a, 560, 256);
    lv_anim_set_duration(&a, 750);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 307, 614, 307, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_SCALE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "gear"));
    lv_anim_set_values(&a, 560, 256);
    lv_anim_set_duration(&a, 750);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 307, 614, 307, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "title"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 400);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 250, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "power"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 400);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 250, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "intro_band"));
    lv_anim_set_values(&a, 127, 405);
    lv_anim_set_duration(&a, 800);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 200, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "intro_speed"));
    lv_anim_set_values(&a, 0, 60);
    lv_anim_set_duration(&a, 900);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 450, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "speedo"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 400);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 350, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "speedo"));
    lv_anim_set_values(&a, 120, 0);
    lv_anim_set_duration(&a, 700);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 256, 1946, 768, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 350, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_left"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_SCALE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_left"));
    lv_anim_set_values(&a, 12, 256);
    lv_anim_set_duration(&a, 320);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_SCALE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_left"));
    lv_anim_set_values(&a, 184, 256);
    lv_anim_set_duration(&a, 320);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_left"));
    lv_anim_set_values(&a, -60, 0);
    lv_anim_set_duration(&a, 780);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 256, 1946, 768, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_right"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_SCALE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_right"));
    lv_anim_set_values(&a, 12, 256);
    lv_anim_set_duration(&a, 320);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_SCALE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_right"));
    lv_anim_set_values(&a, 184, 256);
    lv_anim_set_duration(&a, 320);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "panel_right"));
    lv_anim_set_values(&a, 60, 0);
    lv_anim_set_duration(&a, 780);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 256, 1946, 768, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 650, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "icons_left"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 150);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 800, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "icons_left"));
    lv_anim_set_values(&a, -60, 0);
    lv_anim_set_duration(&a, 720);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 256, 2355, 768, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 800, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "icons_right"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 150);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 800, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "icons_right"));
    lv_anim_set_values(&a, 60, 0);
    lv_anim_set_duration(&a, 720);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_path_cb(&a, lv_anim_path_custom_bezier3);
    lv_anim_set_bezier3_param(&a, 256, 2355, 768, 1024);
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 800, &a);

    return at;
}

static void screen_controls_get_instance_cb(lv_event_t * e)
{
    void ** out = lv_event_get_param(e);
    *out = lv_event_get_user_data(e);
}

static screen_controls_t * screen_controls_get_instance(lv_obj_t * obj)
{
    screen_controls_t * inst = NULL;
    for(lv_obj_t * o = obj; o && !inst; o = lv_obj_get_parent(o)) {
        lv_obj_send_event(o, screen_controls_get_instance_event, &inst);
    }
    return inst;
}

static void screen_controls_destroy_instance(screen_controls_t * inst)
{
    if(inst->timelines) {
        for(uint32_t i = 0; i < 1; i++) lv_anim_timeline_delete(inst->timelines[i]);
        lv_free(inst->timelines);
    }
    lv_free(inst);
}

static void screen_controls_delete_cb(lv_event_t * e)
{
    screen_controls_destroy_instance(lv_event_get_user_data(e));
}

static void screen_controls_lv_obj_0_play_timeline_event_cond_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    screen_controls_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    bool now = (lv_subject_get_int(subject_intro) == 1);
    if(now && !inst->play_timeline_event_lv_obj_0_prev) lv_obj_send_event(obj, screen_controls_play_timeline_event_trigger_code, NULL);
    inst->play_timeline_event_lv_obj_0_prev = now;
}

static void screen_controls_set_subject_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_settings_open, 1);
}

static void screen_controls_set_subject_cb_2(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_power, !lv_subject_get_int(subject_power));
}

static void screen_controls_box_0_style_enabled_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_enabled(obj, screen_controls_style_power_off_ref, 0, lv_subject_get_int(subject_power) == 0);
}

static void screen_controls_icon_button_2_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    icon_button_set_active(obj, lv_subject_get_int(subject_gear) == REF_GEAR_PARK);
}

static void screen_controls_set_subject_cb_3(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_gear, !lv_subject_get_int(subject_gear));
}

static void screen_controls_icon_button_4_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    icon_button_set_active(obj, lv_subject_get_int(subject_feature) == 0);
}

static void screen_controls_set_subject_cb_4(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_feature, 0);
}

static void screen_controls_icon_button_5_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    icon_button_set_active(obj, lv_subject_get_int(subject_feature) == 1);
}

static void screen_controls_set_subject_cb_5(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_feature, 1);
}

static void screen_controls_icon_button_6_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    icon_button_set_active(obj, lv_subject_get_int(subject_feature) == 2);
}

static void screen_controls_set_subject_cb_6(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_feature, 2);
}

static void screen_controls_icon_button_7_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    icon_button_set_active(obj, lv_subject_get_int(subject_feature) == 3);
}

static void screen_controls_set_subject_cb_7(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_feature, 3);
}

