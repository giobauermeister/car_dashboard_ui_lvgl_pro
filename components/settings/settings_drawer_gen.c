/**
 * @file settings_drawer_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_drawer_gen.h"
#include "../../car_ac_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static void settings_drawer_box_1_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void settings_drawer_box_1_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void settings_drawer_set_subject_cb(lv_event_t * e);
static void settings_drawer_box_2_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void settings_drawer_set_subject_cb_2(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * settings_drawer_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_scrim;
    static lv_style_t style_scrim_open;
    static lv_style_t style_panel;
    static lv_style_t style_panel_open;
    static lv_style_t style_item_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        static const lv_style_prop_t style_scrim_trans_props[] = {LV_STYLE_OPA, 0};
        static lv_style_transition_dsc_t style_scrim_trans_dsc;
        static const lv_style_prop_t style_panel_trans_props[] = {LV_STYLE_TRANSLATE_X, 0};
        static lv_style_transition_dsc_t style_panel_trans_dsc;


        /*Init all styles*/
        lv_style_init(&style_scrim);
        lv_style_init(&style_scrim_open);
        lv_style_init(&style_panel);
        lv_style_init(&style_panel_open);
        lv_style_init(&style_item_pressed);

        lv_style_set_bg_opa(&style_scrim, (255 * 55 / 100));
        lv_style_set_bg_color(&style_scrim, COLOR_BG);
        lv_style_set_opa(&style_scrim, 0);
        lv_style_transition_dsc_init(&style_scrim_trans_dsc, style_scrim_trans_props, lv_anim_path_linear, 250, 0, NULL);
        lv_style_set_transition(&style_scrim, &style_scrim_trans_dsc);
        lv_style_set_opa(&style_scrim_open, 255);
        lv_style_set_bg_opa(&style_panel, 255);
        lv_style_set_bg_color(&style_panel, COLOR_DRAWER);
        lv_style_set_radius(&style_panel, RADIUS_SHEET);
        lv_style_set_translate_x(&style_panel, 600);
        lv_style_transition_dsc_init(&style_panel_trans_dsc, style_panel_trans_props, lv_anim_path_ease_out, 300, 0, NULL);
        lv_style_set_transition(&style_panel, &style_panel_trans_dsc);
        lv_style_set_translate_x(&style_panel_open, 0);
        lv_style_set_bg_opa(&style_item_pressed, 255);
        lv_style_set_bg_color(&style_item_pressed, lv_color_hex(0x2A2A2E));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * box_0 = box_create(parent);
        lv_obj_set_name_static(box_0, "settings_drawer_#");
        lv_obj_set_width(box_0, lv_pct(100));
        lv_obj_set_height(box_0, lv_pct(100));
        lv_obj_set_clickable(box_0, false);

        lv_obj_t * box_1 = box_create(box_0);
        lv_obj_set_width(box_1, lv_pct(100));
        lv_obj_set_height(box_1, lv_pct(100));
        lv_obj_set_clickable(box_1, true);
        lv_subject_add_observer_obj(subject_settings_open, settings_drawer_box_1_hidden_binding_cb, box_1, NULL);
        lv_subject_add_observer_obj(subject_settings_open, settings_drawer_box_1_checked_binding_cb, box_1, NULL);
        lv_obj_add_style(box_1, &style_scrim, 0);
        lv_obj_add_style(box_1, &style_scrim_open, LV_STATE_CHECKED);
        lv_obj_add_event_cb(box_1, settings_drawer_set_subject_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * box_2 = box_create(box_0);
        lv_obj_set_width(box_2, 620);
        lv_obj_set_height(box_2, lv_pct(100));
        lv_obj_set_x(box_2, 140);
        lv_obj_set_clickable(box_2, true);
        lv_subject_add_observer_obj(subject_settings_open, settings_drawer_box_2_checked_binding_cb, box_2, NULL);
        lv_obj_add_style(box_2, &style_panel, 0);
        lv_obj_add_style(box_2, &style_panel_open, LV_STATE_CHECKED);
        lv_obj_t * lv_label_0 = lv_label_create(box_2);
        lv_label_set_text(lv_label_0, "Settings");
        lv_obj_set_x(lv_label_0, 44);
        lv_obj_set_y(lv_label_0, 122);
        lv_obj_add_style(lv_label_0, &style_text_title, 0);

        lv_obj_t * lv_image_0 = lv_image_create(box_2);
        lv_image_set_src(lv_image_0, icon_close);
        lv_obj_set_x(lv_image_0, 474);
        lv_obj_set_y(lv_image_0, 102);
        lv_obj_set_clickable(lv_image_0, true);
        lv_obj_set_ext_click_area(lv_image_0, 20);
        lv_obj_add_style(lv_image_0, &style_icon_dim, 0);
        lv_obj_add_style(lv_image_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(lv_image_0, settings_drawer_set_subject_cb_2, LV_EVENT_CLICKED, NULL);

        lv_obj_t * box_3 = box_create(box_2);
        lv_obj_set_width(box_3, 540);
        lv_obj_set_height(box_3, 84);
        lv_obj_set_x(box_3, 20);
        lv_obj_set_y(box_3, 196);
        lv_obj_set_clickable(box_3, true);
        lv_obj_set_flex_flow(box_3, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(box_3, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(box_3, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_left(box_3, 24, 0);
        lv_obj_set_style_pad_column(box_3, 26, 0);
        lv_obj_set_style_radius(box_3, RADIUS_ROW, 0);
        lv_obj_add_style(box_3, &style_item_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(box_3, history_open_cb, LV_EVENT_CLICKED, NULL);
        lv_obj_add_screen_load_event(box_3, LV_EVENT_CLICKED, screen_history, LV_SCREEN_LOAD_ANIM_OVER_TOP, 350, 0);
        lv_obj_t * lv_image_1 = lv_image_create(box_3);
        lv_image_set_src(lv_image_1, icon_thermometer);
        lv_obj_add_style(lv_image_1, &style_icon, 0);

        lv_obj_t * lv_label_1 = lv_label_create(box_3);
        lv_label_set_text(lv_label_1, "Temperature History");
        lv_obj_set_style_text_color(lv_label_1, lv_color_hex(0xE2E2E8), 0);
        lv_obj_set_style_text_font(lv_label_1, font_body, 0);

        the_root = box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void settings_drawer_box_1_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, lv_subject_get_int(subject_settings_open) == 0);
}

static void settings_drawer_box_1_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_checked(obj, lv_subject_get_int(subject_settings_open) == 1);
}

static void settings_drawer_set_subject_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_settings_open, 0);
}

static void settings_drawer_box_2_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_checked(obj, lv_subject_get_int(subject_settings_open) == 1);
}

static void settings_drawer_set_subject_cb_2(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_settings_open, 0);
}

