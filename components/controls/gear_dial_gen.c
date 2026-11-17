/**
 * @file gear_dial_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "gear_dial_gen.h"
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

static void gear_dial_lv_label_0_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void gear_dial_set_subject_cb(lv_event_t * e);
static void gear_dial_lv_label_1_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void gear_dial_lv_label_2_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void gear_dial_lv_label_3_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void gear_dial_set_subject_cb_2(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * gear_dial_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_outline;
    static lv_style_t style_outline_idle;
    static lv_style_t style_band;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_outline);
        lv_style_init(&style_outline_idle);
        lv_style_init(&style_band);

        lv_style_set_arc_color(&style_outline, COLOR_RED);
        lv_style_set_arc_width(&style_outline, 3);
        lv_style_set_arc_rounded(&style_outline, true);
        lv_style_set_arc_color(&style_outline_idle, lv_color_hex(0x3A3A40));
        lv_style_set_arc_width(&style_outline_idle, 3);
        lv_style_set_arc_rounded(&style_outline_idle, true);
        lv_style_set_arc_width(&style_band, 62);
        lv_style_set_arc_rounded(&style_band, false);
        lv_style_set_arc_color(&style_band, COLOR_RED);
        lv_style_set_arc_image_src(&style_band, img_arc_gear);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * box_0 = box_create(parent);
        lv_obj_set_name_static(box_0, "gear_dial_#");
        lv_obj_set_width(box_0, GEAR_SIZE);
        lv_obj_set_height(box_0, GEAR_SIZE + 24);

        lv_obj_t * lv_arc_0 = lv_arc_create(box_0);
        lv_obj_set_width(lv_arc_0, GEAR_SIZE);
        lv_obj_set_height(lv_arc_0, GEAR_SIZE);
        lv_obj_set_align(lv_arc_0, LV_ALIGN_TOP_MID);
        lv_obj_set_clickable(lv_arc_0, false);
        lv_arc_set_bg_start_angle(lv_arc_0, 148);
        lv_arc_set_bg_end_angle(lv_arc_0, 32);
        lv_obj_add_style(lv_arc_0, &style_box, 0);
        lv_obj_add_style(lv_arc_0, &style_outline, 0);
        lv_obj_add_style(lv_arc_0, &style_hidden_part, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_0, &style_hidden_part, LV_PART_KNOB);

        lv_obj_t * lv_arc_1 = lv_arc_create(box_0);
        lv_obj_set_width(lv_arc_1, GEAR_SIZE);
        lv_obj_set_height(lv_arc_1, GEAR_SIZE);
        lv_obj_set_align(lv_arc_1, LV_ALIGN_TOP_MID);
        lv_obj_set_clickable(lv_arc_1, false);
        lv_arc_set_bg_start_angle(lv_arc_1, 42);
        lv_arc_set_bg_end_angle(lv_arc_1, 138);
        lv_obj_add_style(lv_arc_1, &style_box, 0);
        lv_obj_add_style(lv_arc_1, &style_outline_idle, 0);
        lv_obj_add_style(lv_arc_1, &style_hidden_part, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_1, &style_hidden_part, LV_PART_KNOB);

        lv_obj_t * gear_band = lv_arc_create(box_0);
        lv_obj_set_name(gear_band, "gear_band");
        lv_obj_set_width(gear_band, 330);
        lv_obj_set_height(gear_band, 330);
        lv_obj_set_align(gear_band, LV_ALIGN_TOP_MID);
        lv_obj_set_y(gear_band, 15);
        lv_obj_set_clickable(gear_band, false);
        lv_arc_set_bg_start_angle(gear_band, 126);
        lv_arc_set_bg_end_angle(gear_band, 45);
        lv_obj_add_style(gear_band, &style_box, 0);
        lv_obj_add_style(gear_band, &style_band, 0);
        lv_obj_add_style(gear_band, &style_hidden_part, LV_PART_INDICATOR);
        lv_obj_add_style(gear_band, &style_hidden_part, LV_PART_KNOB);

        lv_obj_t * lv_label_0 = lv_label_create(box_0);
        lv_subject_add_observer_obj(subject_gear, gear_dial_lv_label_0_text_binding_cb, lv_label_0, NULL);
        lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
        lv_obj_set_y(lv_label_0, 126);
        lv_obj_set_style_text_font(lv_label_0, font_gear, 0);
        lv_obj_set_style_text_color(lv_label_0, COLOR_WHITE, 0);

        lv_obj_t * box_1 = box_create(box_0);
        lv_obj_set_width(box_1, 210);
        lv_obj_set_height(box_1, 56);
        lv_obj_set_align(box_1, LV_ALIGN_TOP_MID);
        lv_obj_set_y(box_1, 288);
        lv_obj_t * lv_image_0 = lv_image_create(box_1);
        lv_image_set_src(lv_image_0, icon_chevron_left);
        lv_obj_set_align(lv_image_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_ext_click_area(lv_image_0, 16);
        lv_obj_set_clickable(lv_image_0, true);
        lv_obj_add_style(lv_image_0, &style_icon_dim, 0);
        lv_obj_add_style(lv_image_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(lv_image_0, gear_dial_set_subject_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * lv_label_1 = lv_label_create(box_1);
        lv_label_set_text(lv_label_1, "Eco");
        lv_subject_add_observer_obj(subject_drive_mode, gear_dial_lv_label_1_hidden_binding_cb, lv_label_1, NULL);
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_font(lv_label_1, font_body, 0);
        lv_obj_set_style_text_color(lv_label_1, COLOR_WHITE, 0);

        lv_obj_t * lv_label_2 = lv_label_create(box_1);
        lv_label_set_text(lv_label_2, "Comfort");
        lv_subject_add_observer_obj(subject_drive_mode, gear_dial_lv_label_2_hidden_binding_cb, lv_label_2, NULL);
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_set_style_text_font(lv_label_2, font_body, 0);
        lv_obj_set_style_text_color(lv_label_2, COLOR_WHITE, 0);

        lv_obj_t * lv_label_3 = lv_label_create(box_1);
        lv_label_set_text(lv_label_3, "Sport");
        lv_subject_add_observer_obj(subject_drive_mode, gear_dial_lv_label_3_hidden_binding_cb, lv_label_3, NULL);
        lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_font(lv_label_3, font_body, 0);
        lv_obj_set_style_text_color(lv_label_3, COLOR_WHITE, 0);

        lv_obj_t * lv_image_1 = lv_image_create(box_1);
        lv_image_set_src(lv_image_1, icon_chevron_right);
        lv_obj_set_align(lv_image_1, LV_ALIGN_RIGHT_MID);
        lv_obj_set_ext_click_area(lv_image_1, 16);
        lv_obj_set_clickable(lv_image_1, true);
        lv_obj_add_style(lv_image_1, &style_icon_dim, 0);
        lv_obj_add_style(lv_image_1, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(lv_image_1, gear_dial_set_subject_cb_2, LV_EVENT_CLICKED, NULL);

        lv_obj_t * lv_image_2 = lv_image_create(box_0);
        lv_image_set_src(lv_image_2, icon_triangle);
        lv_obj_set_align(lv_image_2, LV_ALIGN_TOP_MID);
        lv_obj_set_y(lv_image_2, GEAR_SIZE - 14);
        lv_obj_set_style_image_recolor(lv_image_2, lv_color_hex(0xE6E6EA), 0);
        lv_obj_set_style_image_recolor_opa(lv_image_2, 255, 0);

        the_root = box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void gear_dial_lv_label_0_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_label_set_text(obj, lv_subject_get_int(subject_gear) == REF_GEAR_PARK ? "P" : "D");
}

static void gear_dial_set_subject_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_drive_mode, lv_subject_get_int(subject_drive_mode) - 1);
}

static void gear_dial_lv_label_1_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, lv_subject_get_int(subject_drive_mode) != 0);
}

static void gear_dial_lv_label_2_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, lv_subject_get_int(subject_drive_mode) != 1);
}

static void gear_dial_lv_label_3_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, lv_subject_get_int(subject_drive_mode) != 2);
}

static void gear_dial_set_subject_cb_2(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_drive_mode, lv_subject_get_int(subject_drive_mode) + 1);
}

