/**
 * @file status_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "status_bar_gen.h"
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

static void status_bar_lv_label_0_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * status_bar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * box_0 = box_create(parent);
        lv_obj_set_name_static(box_0, "status_bar_#");
        lv_obj_set_width(box_0, lv_pct(100));
        lv_obj_set_height(box_0, 56);
        lv_obj_set_clickable(box_0, false);

        lv_obj_t * lv_label_0 = lv_label_create(box_0);
        lv_subject_add_observer_obj(subject_clock, status_bar_lv_label_0_text_binding_cb, lv_label_0, NULL);
        lv_obj_set_align(lv_label_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_label_0, 56);
        lv_obj_set_style_text_font(lv_label_0, font_title, 0);
        lv_obj_set_style_text_color(lv_label_0, COLOR_WHITE, 0);

        lv_obj_t * lv_image_0 = lv_image_create(box_0);
        lv_image_set_src(lv_image_0, icon_wifi);
        lv_obj_set_align(lv_image_0, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_image_0, -104);
        lv_obj_add_style(lv_image_0, &style_icon, 0);

        lv_obj_t * lv_image_1 = lv_image_create(box_0);
        lv_image_set_src(lv_image_1, icon_battery);
        lv_obj_set_align(lv_image_1, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_image_1, -56);
        lv_image_set_rotation(lv_image_1, 900);
        lv_obj_add_style(lv_image_1, &style_icon, 0);

        the_root = box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void status_bar_lv_label_0_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_label_set_text(obj, lv_subject_get_string(subject_clock));
}

