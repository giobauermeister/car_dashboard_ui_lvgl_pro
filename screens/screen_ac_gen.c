/**
 * @file screen_ac_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_ac_gen.h"
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

static void screen_ac_car_style_translate_y_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_car_style_image_opa_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_set_subject_cb(lv_event_t * e);
static void screen_ac_lv_label_2_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_mode_row_0_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_set_subject_cb_2(lv_event_t * e);
static void screen_ac_mode_row_1_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_set_subject_cb_3(lv_event_t * e);
static void screen_ac_mode_row_2_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_set_subject_cb_4(lv_event_t * e);
static void screen_ac_set_subject_cb_5(lv_event_t * e);
static void screen_ac_set_subject_cb_6(lv_event_t * e);
static void screen_ac_lv_label_6_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void screen_ac_set_subject_cb_7(lv_event_t * e);
static void screen_ac_set_subject_cb_8(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_ac_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`screen_ac` is already initialized as a permanent screen. Returning with no change.");
        return screen_ac;
    }

    static lv_style_t style_screen;
    static lv_style_t style_sheet;
    static lv_style_t style_group;
    static lv_style_t style_divider;
    static lv_style_t style_card;
    static lv_style_t style_round_button;
    static lv_style_t style_round_button_pressed;
    static lv_style_t style_threshold;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen);
        lv_style_init(&style_sheet);
        lv_style_init(&style_group);
        lv_style_init(&style_divider);
        lv_style_init(&style_card);
        lv_style_init(&style_round_button);
        lv_style_init(&style_round_button_pressed);
        lv_style_init(&style_threshold);

        lv_style_set_bg_color(&style_screen, COLOR_BG);
        lv_style_set_bg_opa(&style_screen, 255);
        lv_style_set_bg_opa(&style_sheet, 255);
        lv_style_set_bg_color(&style_sheet, COLOR_SHEET_TOP);
        lv_style_set_bg_grad_color(&style_sheet, COLOR_SHEET_BOTTOM);
        lv_style_set_bg_grad_dir(&style_sheet, LV_GRAD_DIR_VER);
        lv_style_set_radius(&style_sheet, RADIUS_SHEET);
        lv_style_set_bg_opa(&style_group, 255);
        lv_style_set_bg_color(&style_group, COLOR_BG);
        lv_style_set_radius(&style_group, RADIUS_ROW);
        lv_style_set_clip_corner(&style_group, true);
        lv_style_set_bg_opa(&style_divider, 255);
        lv_style_set_bg_color(&style_divider, COLOR_LINE);
        lv_style_set_bg_opa(&style_card, 255);
        lv_style_set_bg_color(&style_card, COLOR_CARD_TOP);
        lv_style_set_bg_grad_color(&style_card, COLOR_CARD_BOTTOM);
        lv_style_set_bg_grad_dir(&style_card, LV_GRAD_DIR_VER);
        lv_style_set_radius(&style_card, RADIUS_CARD);
        lv_style_set_border_width(&style_card, 1);
        lv_style_set_border_color(&style_card, COLOR_CARD_BORDER);
        lv_style_set_pad_hor(&style_card, 34);
        lv_style_set_pad_ver(&style_card, 30);
        lv_style_set_radius(&style_round_button, 1000);
        lv_style_set_bg_opa(&style_round_button, 255);
        lv_style_set_bg_color(&style_round_button, COLOR_BG);
        lv_style_set_bg_color(&style_round_button_pressed, lv_color_hex(0x26262C));
        lv_style_set_text_font(&style_threshold, font_value);
        lv_style_set_text_color(&style_threshold, lv_color_hex(0xD8D8DE));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = screen_ac;
        lv_obj_set_name_static(lv_obj_0, "screen_ac_#");
        lv_obj_set_scrollable(lv_obj_0, false);

        lv_obj_add_style(lv_obj_0, &style_screen, 0);
        lv_obj_add_event_cb(lv_obj_0, ac_screen_load_cb, LV_EVENT_SCREEN_LOAD_START, NULL);
        lv_obj_add_event_cb(lv_obj_0, ac_screen_loaded_cb, LV_EVENT_SCREEN_LOADED, NULL);
        lv_obj_t * car = lv_image_create(lv_obj_0);
        lv_obj_set_name(car, "car");
        lv_image_set_src(car, img_car);
        lv_obj_set_align(car, LV_ALIGN_TOP_MID);
        lv_obj_set_y(car, 132);
        lv_subject_add_observer_obj(subject_sheet_pos, screen_ac_car_style_translate_y_binding_cb, car, NULL);
        lv_subject_add_observer_obj(subject_sheet_pos, screen_ac_car_style_image_opa_binding_cb, car, NULL);

        status_bar_create(lv_obj_0);

        lv_obj_t * box_0 = box_create(lv_obj_0);
        lv_obj_set_width(box_0, lv_pct(100));
        lv_obj_set_height(box_0, 64);
        lv_obj_set_y(box_0, 60);
        lv_obj_t * box_1 = box_create(box_0);
        lv_obj_set_width(box_1, LV_SIZE_CONTENT);
        lv_obj_set_height(box_1, lv_pct(100));
        lv_obj_set_x(box_1, 30);
        lv_obj_set_clickable(box_1, true);
        lv_obj_set_flex_flow(box_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(box_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(box_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_column(box_1, 0, 0);
        lv_obj_add_style(box_1, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_screen_load_event(box_1, LV_EVENT_CLICKED, screen_controls, LV_SCREEN_LOAD_ANIM_FADE_IN, 500, 0);
        lv_obj_t * lv_image_0 = lv_image_create(box_1);
        lv_image_set_src(lv_image_0, icon_back);
        lv_obj_add_style(lv_image_0, &style_icon_dim, 0);

        lv_obj_t * lv_label_0 = lv_label_create(box_1);
        lv_label_set_text(lv_label_0, "Back");
        lv_obj_set_style_text_font(lv_label_0, font_title, 0);
        lv_obj_set_style_text_color(lv_label_0, COLOR_TEXT_DIM, 0);

        lv_obj_t * lv_image_1 = lv_image_create(box_0);
        lv_image_set_src(lv_image_1, icon_settings);
        lv_obj_set_align(lv_image_1, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_image_1, -52);
        lv_obj_set_clickable(lv_image_1, true);
        lv_obj_set_ext_click_area(lv_image_1, 20);
        lv_obj_add_style(lv_image_1, &style_icon_dim, 0);
        lv_obj_add_style(lv_image_1, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(lv_image_1, screen_ac_set_subject_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * sheet = box_create(lv_obj_0);
        lv_obj_set_name(sheet, "sheet");
        lv_obj_set_width(sheet, lv_pct(100));
        lv_obj_set_height(sheet, SHEET_H);
        lv_obj_set_y(sheet, SHEET_CLOSED_Y);
        lv_obj_set_clickable(sheet, true);
        lv_obj_add_style(sheet, &style_sheet, 0);
        lv_obj_t * sheet_handle = box_create(sheet);
        lv_obj_set_name(sheet_handle, "sheet_handle");
        lv_obj_set_width(sheet_handle, lv_pct(100));
        lv_obj_set_height(sheet_handle, SHEET_HANDLE_H);
        lv_obj_set_clickable(sheet_handle, true);
        lv_obj_add_event_cb(sheet_handle, sheet_handle_event_cb, LV_EVENT_ALL, NULL);
        lv_obj_t * lv_label_1 = lv_label_create(sheet_handle);
        lv_label_set_text(lv_label_1, "Mode Control");
        lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_MID);
        lv_obj_set_y(lv_label_1, 36);
        lv_obj_add_style(lv_label_1, &style_text_title, 0);

        lv_obj_t * lv_label_2 = lv_label_create(sheet_handle);
        lv_subject_add_observer_obj(subject_exterior_temp, screen_ac_lv_label_2_text_binding_cb, lv_label_2, NULL);
        lv_subject_add_observer_obj(subject_interior_temp, screen_ac_lv_label_2_text_binding_cb, lv_label_2, NULL);
        lv_obj_set_align(lv_label_2, LV_ALIGN_TOP_MID);
        lv_obj_set_y(lv_label_2, 88);
        lv_obj_add_style(lv_label_2, &style_text_dim, 0);

        lv_obj_t * box_2 = box_create(sheet);
        lv_obj_set_width(box_2, lv_pct(100));
        lv_obj_set_height(box_2, LV_SIZE_CONTENT);
        lv_obj_set_y(box_2, SHEET_HANDLE_H);
        lv_obj_set_flex_flow(box_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_cross_place(box_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(box_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(box_2, SPACE_PAGE, 0);
        lv_obj_set_style_pad_row(box_2, 26, 0);
        lv_obj_t * box_3 = box_create(box_2);
        lv_obj_set_width(box_3, lv_pct(100));
        lv_obj_set_height(box_3, 1);
        lv_obj_add_style(box_3, &style_divider, 0);

        lv_obj_t * box_4 = box_create(box_2);
        lv_obj_set_width(box_4, lv_pct(100));
        lv_obj_set_height(box_4, LV_SIZE_CONTENT);
        lv_obj_add_style(box_4, &style_group, 0);
        lv_obj_t * mode_row_0 = mode_row_create(box_4, icon_defrost, "Quick Defrost", lv_subject_get_int(subject_defrost) == 1);
        lv_subject_add_observer_obj(subject_defrost, screen_ac_mode_row_0_active_binding_cb, mode_row_0, NULL);
        lv_obj_add_event_cb(mode_row_0, screen_ac_set_subject_cb_2, LV_EVENT_CLICKED, NULL);

        lv_obj_t * box_5 = box_create(box_2);
        lv_obj_set_width(box_5, lv_pct(100));
        lv_obj_set_height(box_5, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(box_5, LV_FLEX_FLOW_COLUMN);
        lv_obj_add_style(box_5, &style_group, 0);
        lv_obj_t * mode_row_1 = mode_row_create(box_5, icon_paw, "Pet Mode", lv_subject_get_int(subject_ac_mode) == REF_AC_MODE_PET);
        lv_subject_add_observer_obj(subject_ac_mode, screen_ac_mode_row_1_active_binding_cb, mode_row_1, NULL);
        lv_obj_add_event_cb(mode_row_1, screen_ac_set_subject_cb_3, LV_EVENT_CLICKED, NULL);

        lv_obj_t * mode_row_2 = mode_row_create(box_5, icon_mode_fan, "Normal Mode", lv_subject_get_int(subject_ac_mode) == REF_AC_MODE_NORMAL);
        lv_subject_add_observer_obj(subject_ac_mode, screen_ac_mode_row_2_active_binding_cb, mode_row_2, NULL);
        lv_obj_add_event_cb(mode_row_2, screen_ac_set_subject_cb_4, LV_EVENT_CLICKED, NULL);

        lv_obj_t * lv_label_3 = lv_label_create(box_2);
        lv_label_set_text(lv_label_3, "View Interior Camera");
        lv_obj_set_style_pad_ver(lv_label_3, 6, 0);
        lv_obj_add_style(lv_label_3, &style_text_dim, 0);

        lv_obj_t * box_6 = box_create(box_2);
        lv_obj_set_width(box_6, lv_pct(100));
        lv_obj_set_height(box_6, 1);
        lv_obj_add_style(box_6, &style_divider, 0);

        lv_obj_t * box_7 = box_create(box_2);
        lv_obj_set_width(box_7, lv_pct(100));
        lv_obj_set_height(box_7, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(box_7, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(box_7, 24, 0);
        lv_obj_add_style(box_7, &style_card, 0);
        lv_obj_t * lv_label_4 = lv_label_create(box_7);
        lv_label_set_text(lv_label_4, "Interior Temperature Control");
        lv_obj_add_style(lv_label_4, &style_text_title, 0);

        segmented_create(box_7, subject_temp_control, "OFF", "NO A/C", "ON");

        lv_obj_t * lv_label_5 = lv_label_create(box_7);
        lv_label_set_text(lv_label_5, "Activation Threshold");
        lv_obj_set_style_margin_top(lv_label_5, 10, 0);
        lv_obj_add_style(lv_label_5, &style_text_title, 0);

        lv_obj_t * box_8 = box_create(box_7);
        lv_obj_set_width(box_8, lv_pct(100));
        lv_obj_set_height(box_8, 76);
        lv_obj_t * box_9 = box_create(box_8);
        lv_obj_set_width(box_9, 68);
        lv_obj_set_height(box_9, 68);
        lv_obj_set_align(box_9, LV_ALIGN_CENTER);
        lv_obj_set_x(box_9, -124);
        lv_obj_set_clickable(box_9, true);
        lv_obj_set_ext_click_area(box_9, 12);
        lv_obj_add_style(box_9, &style_round_button, 0);
        lv_obj_add_style(box_9, &style_round_button_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(box_9, screen_ac_set_subject_cb_5, LV_EVENT_SHORT_CLICKED, NULL);
        lv_obj_add_event_cb(box_9, screen_ac_set_subject_cb_6, LV_EVENT_LONG_PRESSED_REPEAT, NULL);
        lv_obj_t * lv_image_2 = lv_image_create(box_9);
        lv_image_set_src(lv_image_2, icon_minus);
        lv_obj_set_align(lv_image_2, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_image_2, &style_icon, 0);

        lv_obj_t * lv_label_6 = lv_label_create(box_8);
        lv_subject_add_observer_obj(subject_threshold, screen_ac_lv_label_6_text_binding_cb, lv_label_6, NULL);
        lv_obj_set_align(lv_label_6, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_label_6, 6);
        lv_obj_add_style(lv_label_6, &style_threshold, 0);

        lv_obj_t * box_10 = box_create(box_8);
        lv_obj_set_width(box_10, 68);
        lv_obj_set_height(box_10, 68);
        lv_obj_set_align(box_10, LV_ALIGN_CENTER);
        lv_obj_set_x(box_10, 124);
        lv_obj_set_clickable(box_10, true);
        lv_obj_set_ext_click_area(box_10, 12);
        lv_obj_add_style(box_10, &style_round_button, 0);
        lv_obj_add_style(box_10, &style_round_button_pressed, LV_STATE_PRESSED);
        lv_obj_add_event_cb(box_10, screen_ac_set_subject_cb_7, LV_EVENT_SHORT_CLICKED, NULL);
        lv_obj_add_event_cb(box_10, screen_ac_set_subject_cb_8, LV_EVENT_LONG_PRESSED_REPEAT, NULL);
        lv_obj_t * lv_image_3 = lv_image_create(box_10);
        lv_image_set_src(lv_image_3, icon_plus);
        lv_obj_set_align(lv_image_3, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_image_3, &style_icon, 0);

        segmented_create(box_7, subject_preset, "18°", "22°", "26°");

        lv_obj_t * lv_label_7 = lv_label_create(box_7);
        lv_label_set_text(lv_label_7, "Check conditions");
        lv_obj_set_width(lv_label_7, lv_pct(100));
        lv_obj_set_style_text_align(lv_label_7, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_style_margin_top(lv_label_7, 4, 0);
        lv_obj_add_style(lv_label_7, &style_text_dim, 0);

        settings_drawer_create(lv_obj_0);

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

static void screen_ac_car_style_translate_y_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_translate_y(obj, 0 - lv_subject_get_int(subject_sheet_pos) * 36 / 10, 0);
}

static void screen_ac_car_style_image_opa_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_image_opa(obj, 255 - lv_subject_get_int(subject_sheet_pos) / 2, 0);
}

static void screen_ac_set_subject_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_settings_open, 1);
}

static void screen_ac_lv_label_2_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    char eval_buf_1[LV_XML_EVAL_STRING_BUF_SIZE];
    lv_snprintf(eval_buf_1, sizeof(eval_buf_1), "%s%d%s%d%s", "Exterior ", (int)(lv_subject_get_int(subject_exterior_temp)), "°   •   Interior ", (int)(lv_subject_get_int(subject_interior_temp)), "°");
    lv_label_set_text(obj, eval_buf_1);
}

static void screen_ac_mode_row_0_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    mode_row_set_active(obj, lv_subject_get_int(subject_defrost) == 1);
}

static void screen_ac_set_subject_cb_2(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_defrost, !lv_subject_get_int(subject_defrost));
}

static void screen_ac_mode_row_1_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    mode_row_set_active(obj, lv_subject_get_int(subject_ac_mode) == REF_AC_MODE_PET);
}

static void screen_ac_set_subject_cb_3(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_ac_mode, REF_AC_MODE_PET);
}

static void screen_ac_mode_row_2_active_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    mode_row_set_active(obj, lv_subject_get_int(subject_ac_mode) == REF_AC_MODE_NORMAL);
}

static void screen_ac_set_subject_cb_4(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_ac_mode, REF_AC_MODE_NORMAL);
}

static void screen_ac_set_subject_cb_5(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_threshold, lv_subject_get_int(subject_threshold) - 1);
}

static void screen_ac_set_subject_cb_6(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_threshold, lv_subject_get_int(subject_threshold) - 1);
}

static void screen_ac_lv_label_6_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    char eval_buf_1[LV_XML_EVAL_STRING_BUF_SIZE];
    lv_snprintf(eval_buf_1, sizeof(eval_buf_1), "%d%s", (int)(lv_subject_get_int(subject_threshold)), "°");
    lv_label_set_text(obj, eval_buf_1);
}

static void screen_ac_set_subject_cb_7(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_threshold, lv_subject_get_int(subject_threshold) + 1);
}

static void screen_ac_set_subject_cb_8(lv_event_t * e)
{
    LV_UNUSED(e);
    lv_subject_set_int(subject_threshold, lv_subject_get_int(subject_threshold) + 1);
}

