/**
 * @file history_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "history_item_gen.h"
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

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * history_item_create(lv_obj_t * parent, const char * time, const char * temp)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);

        lv_style_set_radius(&style_main, 22);
        lv_style_set_border_width(&style_main, 1);
        lv_style_set_border_color(&style_main, lv_color_hex(0x1E1E22));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * box_0 = box_create(parent);
        lv_obj_set_name_static(box_0, "history_item_#");
        lv_obj_set_width(box_0, lv_pct(100));
        lv_obj_set_height(box_0, 88);

        lv_obj_add_style(box_0, &style_main, 0);
        lv_obj_t * lv_label_0 = lv_label_create(box_0);
        lv_label_set_text(lv_label_0, time);
        lv_obj_set_align(lv_label_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_label_0, 34);
        lv_obj_add_style(lv_label_0, &style_text_dim, 0);

        lv_obj_t * lv_label_1 = lv_label_create(box_0);
        lv_label_set_text(lv_label_1, temp);
        lv_obj_set_align(lv_label_1, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_label_1, -52);
        lv_obj_set_style_text_font(lv_label_1, font_temp, 0);
        lv_obj_set_style_text_color(lv_label_1, COLOR_WHITE, 0);

        lv_obj_t * lv_label_2 = lv_label_create(box_0);
        lv_label_set_text(lv_label_2, "C");
        lv_obj_set_align(lv_label_2, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_label_2, -28);
        lv_obj_set_y(lv_label_2, 3);
        lv_obj_add_style(lv_label_2, &style_text_dim, 0);

        the_root = box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

