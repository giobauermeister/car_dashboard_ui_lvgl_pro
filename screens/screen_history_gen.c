/**
 * @file screen_history_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_history_gen.h"
#include "../car_ac_ui.h"

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

lv_obj_t * screen_history_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`screen_history` is already initialized as a permanent screen. Returning with no change.");
        return screen_history;
    }

    static lv_style_t style_screen;
    static lv_style_t style_divider;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen);
        lv_style_init(&style_divider);

        lv_style_set_bg_color(&style_screen, COLOR_BG);
        lv_style_set_bg_opa(&style_screen, 255);
        lv_style_set_bg_opa(&style_divider, 255);
        lv_style_set_bg_color(&style_divider, COLOR_LINE);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = screen_history;
        lv_obj_set_name_static(lv_obj_0, "screen_history_#");
        lv_obj_set_scrollable(lv_obj_0, false);

        lv_obj_add_style(lv_obj_0, &style_screen, 0);
        lv_obj_add_event_cb(lv_obj_0, history_screen_load_cb, LV_EVENT_SCREEN_LOAD_START, NULL);
        status_bar_create(lv_obj_0);

        lv_obj_t * box_0 = box_create(lv_obj_0);
        lv_obj_set_width(box_0, lv_pct(100));
        lv_obj_set_height(box_0, 84);
        lv_obj_set_y(box_0, 60);
        lv_obj_t * lv_label_0 = lv_label_create(box_0);
        lv_label_set_text(lv_label_0, "Temperature History");
        lv_obj_set_align(lv_label_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_label_0, 36);
        lv_obj_add_style(lv_label_0, &style_text_title, 0);

        lv_obj_t * lv_image_0 = lv_image_create(box_0);
        lv_image_set_src(lv_image_0, icon_close);
        lv_obj_set_align(lv_image_0, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_image_0, -40);
        lv_obj_set_clickable(lv_image_0, true);
        lv_obj_set_ext_click_area(lv_image_0, 20);
        lv_obj_add_style(lv_image_0, &style_icon_dim, 0);
        lv_obj_add_style(lv_image_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(lv_image_0, history_close_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * box_1 = box_create(box_0);
        lv_obj_set_width(box_1, lv_pct(100));
        lv_obj_set_height(box_1, 1);
        lv_obj_set_align(box_1, LV_ALIGN_BOTTOM_MID);
        lv_obj_add_style(box_1, &style_divider, 0);

        lv_obj_t * box_2 = box_create(lv_obj_0);
        lv_obj_set_width(box_2, lv_pct(100));
        lv_obj_set_height(box_2, 1136);
        lv_obj_set_y(box_2, 144);
        lv_obj_set_scrollable(box_2, true);
        lv_obj_set_scroll_dir(box_2, LV_DIR_VER);
        lv_obj_set_flex_flow(box_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_hor(box_2, SPACE_PAGE, 0);
        lv_obj_set_style_pad_top(box_2, 24, 0);
        lv_obj_set_style_pad_bottom(box_2, 40, 0);
        lv_obj_set_style_pad_row(box_2, 16, 0);
        lv_obj_t * lv_label_1 = lv_label_create(box_2);
        lv_label_set_text(lv_label_1, "Nov 25");
        lv_obj_set_style_text_font(lv_label_1, font_body, 0);
        lv_obj_set_style_text_color(lv_label_1, COLOR_WHITE, 0);
        lv_obj_set_style_pad_left(lv_label_1, 6, 0);

        lv_obj_t * history_list = box_create(box_2);
        lv_obj_set_name(history_list, "history_list");
        lv_obj_set_width(history_list, lv_pct(100));
        lv_obj_set_height(history_list, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(history_list, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(history_list, 14, 0);

        the_root = lv_obj_0;
    }
    #endif

    if (the_root) screen_created = true;

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

