/**
 * @file speedometer_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "speedometer_gen.h"
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

static void speedometer_lv_label_0_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void speedometer_lv_label_2_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * speedometer_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_ring;
    static lv_style_t style_track;
    static lv_style_t style_value;
    static lv_style_t style_dot;
    static lv_style_t style_dot_reached;
    static lv_style_t style_numbers;
    static lv_style_t style_no_line;
    static lv_style_t style_tick;
    static lv_style_t style_tick_passed;
    static lv_style_t style_tick_rim;
    static lv_style_t style_range_arc;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_ring);
        lv_style_init(&style_track);
        lv_style_init(&style_value);
        lv_style_init(&style_dot);
        lv_style_init(&style_dot_reached);
        lv_style_init(&style_numbers);
        lv_style_init(&style_no_line);
        lv_style_init(&style_tick);
        lv_style_init(&style_tick_passed);
        lv_style_init(&style_tick_rim);
        lv_style_init(&style_range_arc);

        lv_style_set_radius(&style_ring, 1000);
        lv_style_set_border_width(&style_ring, 2);
        lv_style_set_border_color(&style_ring, COLOR_WHITE);
        lv_style_set_border_opa(&style_ring, (255 * 85 / 100));
        lv_style_set_arc_color(&style_track, COLOR_NAVY);
        lv_style_set_arc_width(&style_track, 22);
        lv_style_set_arc_rounded(&style_track, true);
        lv_style_set_arc_width(&style_value, 22);
        lv_style_set_arc_rounded(&style_value, true);
        lv_style_set_arc_color(&style_value, COLOR_RED);
        lv_style_set_arc_image_src(&style_value, img_arc_speed);
        lv_style_set_line_color(&style_dot, COLOR_WHITE);
        lv_style_set_line_opa(&style_dot, (255 * 13 / 100));
        lv_style_set_line_width(&style_dot, 7);
        lv_style_set_line_rounded(&style_dot, true);
        lv_style_set_length(&style_dot, 1);
        lv_style_set_line_opa(&style_dot_reached, (255 * 40 / 100));
        lv_style_set_text_font(&style_numbers, font_small);
        lv_style_set_text_color(&style_numbers, COLOR_TEXT_DIM);
        lv_style_set_line_opa(&style_numbers, 0);
        lv_style_set_length(&style_numbers, 0);
        lv_style_set_pad_radial(&style_numbers, 0);
        lv_style_set_line_opa(&style_no_line, 0);
        lv_style_set_arc_opa(&style_no_line, 0);
        lv_style_set_arc_width(&style_no_line, 0);
        lv_style_set_length(&style_no_line, 0);
        lv_style_set_line_color(&style_tick, COLOR_TICK_IDLE);
        lv_style_set_line_width(&style_tick, 3);
        lv_style_set_length(&style_tick, 17);
        lv_style_set_line_color(&style_tick_passed, COLOR_RED);
        lv_style_set_arc_color(&style_tick_rim, COLOR_RED);
        lv_style_set_arc_opa(&style_tick_rim, (255 * 45 / 100));
        lv_style_set_arc_width(&style_tick_rim, 1);
        lv_style_set_arc_color(&style_range_arc, lv_color_hex(0x8A2A7A));
        lv_style_set_arc_width(&style_range_arc, 3);
        lv_style_set_arc_rounded(&style_range_arc, true);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * box_0 = box_create(parent);
        lv_obj_set_name_static(box_0, "speedometer_#");
        lv_obj_set_width(box_0, SPEEDO_SIZE);
        lv_obj_set_height(box_0, SPEEDO_SIZE);

        lv_obj_t * box_1 = box_create(box_0);
        lv_obj_set_width(box_1, lv_pct(100));
        lv_obj_set_height(box_1, lv_pct(100));
        lv_obj_add_style(box_1, &style_ring, 0);

        lv_obj_t * lv_arc_0 = lv_arc_create(box_0);
        lv_obj_set_width(lv_arc_0, 452);
        lv_obj_set_height(lv_arc_0, 452);
        lv_obj_set_align(lv_arc_0, LV_ALIGN_CENTER);
        lv_obj_set_clickable(lv_arc_0, false);
        lv_arc_set_rotation(lv_arc_0, 135);
        lv_arc_set_bg_start_angle(lv_arc_0, 0);
        lv_arc_set_bg_end_angle(lv_arc_0, 270);
        lv_arc_set_min_value(lv_arc_0, 0);
        lv_arc_set_max_value(lv_arc_0, 120);
        lv_arc_bind_value(lv_arc_0, subject_speed);
        lv_obj_add_style(lv_arc_0, &style_box, 0);
        lv_obj_add_style(lv_arc_0, &style_track, 0);
        lv_obj_add_style(lv_arc_0, &style_value, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_0, &style_hidden_part, LV_PART_KNOB);

        lv_obj_t * lv_scale_0 = lv_scale_create(box_0);
        lv_obj_set_width(lv_scale_0, 437);
        lv_obj_set_height(lv_scale_0, 437);
        lv_obj_set_align(lv_scale_0, LV_ALIGN_CENTER);
        lv_scale_set_mode(lv_scale_0, LV_SCALE_MODE_ROUND_INNER);
        lv_scale_set_rotation(lv_scale_0, 135);
        lv_scale_set_angle_range(lv_scale_0, 270);
        lv_scale_set_min_value(lv_scale_0, 0);
        lv_scale_set_max_value(lv_scale_0, 120);
        lv_scale_set_total_tick_count(lv_scale_0, 7);
        lv_scale_set_major_tick_every(lv_scale_0, 1);
        lv_scale_set_label_show(lv_scale_0, false);
        lv_obj_set_send_draw_task_events(lv_scale_0, true);
        lv_obj_add_event_cb(lv_scale_0, scale_section_opa_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
        lv_obj_add_style(lv_scale_0, &style_box, 0);
        lv_obj_add_style(lv_scale_0, &style_no_line, 0);
        lv_obj_add_style(lv_scale_0, &style_no_line, LV_PART_ITEMS);
        lv_obj_add_style(lv_scale_0, &style_dot, LV_PART_INDICATOR);
        lv_scale_section_t * lv_scale_section_0 = lv_scale_add_section(lv_scale_0);
        lv_scale_bind_section_min_value(lv_scale_0, lv_scale_section_0, subject_speed);
        lv_scale_bind_section_max_value(lv_scale_0, lv_scale_section_0, subject_speed);
        lv_scale_set_section_style_indicator(lv_scale_0, lv_scale_section_0, &style_dot_reached);

        lv_obj_t * lv_scale_1 = lv_scale_create(box_0);
        lv_obj_set_width(lv_scale_1, 398);
        lv_obj_set_height(lv_scale_1, 398);
        lv_obj_set_align(lv_scale_1, LV_ALIGN_CENTER);
        lv_scale_set_mode(lv_scale_1, LV_SCALE_MODE_ROUND_INNER);
        lv_scale_set_rotation(lv_scale_1, 135);
        lv_scale_set_angle_range(lv_scale_1, 270);
        lv_scale_set_min_value(lv_scale_1, 0);
        lv_scale_set_max_value(lv_scale_1, 120);
        lv_scale_set_total_tick_count(lv_scale_1, 7);
        lv_scale_set_major_tick_every(lv_scale_1, 1);
        lv_scale_set_label_show(lv_scale_1, true);
        lv_obj_add_style(lv_scale_1, &style_box, 0);
        lv_obj_add_style(lv_scale_1, &style_no_line, 0);
        lv_obj_add_style(lv_scale_1, &style_no_line, LV_PART_ITEMS);
        lv_obj_add_style(lv_scale_1, &style_numbers, LV_PART_INDICATOR);

        lv_obj_t * lv_scale_2 = lv_scale_create(box_0);
        lv_obj_set_width(lv_scale_2, 320);
        lv_obj_set_height(lv_scale_2, 320);
        lv_obj_set_align(lv_scale_2, LV_ALIGN_CENTER);
        lv_scale_set_mode(lv_scale_2, LV_SCALE_MODE_ROUND_INNER);
        lv_scale_set_rotation(lv_scale_2, 135);
        lv_scale_set_angle_range(lv_scale_2, 270);
        lv_scale_set_min_value(lv_scale_2, 0);
        lv_scale_set_max_value(lv_scale_2, 120);
        lv_scale_set_total_tick_count(lv_scale_2, 91);
        lv_scale_set_major_tick_every(lv_scale_2, 5);
        lv_scale_set_label_show(lv_scale_2, false);
        lv_obj_set_send_draw_task_events(lv_scale_2, true);
        lv_obj_add_event_cb(lv_scale_2, scale_section_opa_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
        lv_obj_add_style(lv_scale_2, &style_box, 0);
        lv_obj_add_style(lv_scale_2, &style_no_line, 0);
        lv_obj_add_style(lv_scale_2, &style_tick, LV_PART_ITEMS);
        lv_obj_add_style(lv_scale_2, &style_tick, LV_PART_INDICATOR);
        lv_scale_section_t * lv_scale_section_1 = lv_scale_add_section(lv_scale_2);
        lv_scale_set_section_min_value(lv_scale_2, lv_scale_section_1, 0);
        lv_scale_bind_section_max_value(lv_scale_2, lv_scale_section_1, subject_speed);
        lv_scale_set_section_style_items(lv_scale_2, lv_scale_section_1, &style_tick_passed);
        lv_scale_set_section_style_indicator(lv_scale_2, lv_scale_section_1, &style_tick_passed);

        lv_obj_t * lv_arc_1 = lv_arc_create(box_0);
        lv_obj_set_width(lv_arc_1, 280);
        lv_obj_set_height(lv_arc_1, 280);
        lv_obj_set_align(lv_arc_1, LV_ALIGN_CENTER);
        lv_obj_set_clickable(lv_arc_1, false);
        lv_arc_set_bg_start_angle(lv_arc_1, 150);
        lv_arc_set_bg_end_angle(lv_arc_1, 30);
        lv_obj_add_style(lv_arc_1, &style_box, 0);
        lv_obj_add_style(lv_arc_1, &style_tick_rim, 0);
        lv_obj_add_style(lv_arc_1, &style_hidden_part, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_1, &style_hidden_part, LV_PART_KNOB);

        lv_obj_t * lv_label_0 = lv_label_create(box_0);
        lv_subject_add_observer_obj(subject_speed, speedometer_lv_label_0_text_binding_cb, lv_label_0, NULL);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_label_0, -22);
        lv_obj_set_style_text_font(lv_label_0, font_speed, 0);
        lv_obj_set_style_text_color(lv_label_0, COLOR_WHITE, 0);
        lv_obj_set_style_text_letter_space(lv_label_0, -3, 0);

        lv_obj_t * lv_label_1 = lv_label_create(box_0);
        lv_label_set_text(lv_label_1, "mph");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_label_1, 80);
        lv_obj_set_style_text_font(lv_label_1, font_unit, 0);
        lv_obj_set_style_text_color(lv_label_1, COLOR_TEXT_DIM, 0);

        lv_obj_t * box_2 = box_create(box_0);
        lv_obj_set_width(box_2, LV_SIZE_CONTENT);
        lv_obj_set_height(box_2, LV_SIZE_CONTENT);
        lv_obj_set_align(box_2, LV_ALIGN_CENTER);
        lv_obj_set_y(box_2, 182);
        lv_obj_set_flex_flow(box_2, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_column(box_2, 8, 0);
        lv_obj_set_style_flex_cross_place(box_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(box_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_t * lv_image_0 = lv_image_create(box_2);
        lv_image_set_src(lv_image_0, icon_fuel);
        lv_obj_add_style(lv_image_0, &style_icon_dim, 0);

        lv_obj_t * lv_label_2 = lv_label_create(box_2);
        lv_subject_add_observer_obj(subject_range, speedometer_lv_label_2_text_binding_cb, lv_label_2, NULL);
        lv_obj_add_style(lv_label_2, &style_text_dim, 0);

        lv_obj_t * lv_arc_2 = lv_arc_create(box_0);
        lv_obj_set_width(lv_arc_2, 436);
        lv_obj_set_height(lv_arc_2, 436);
        lv_obj_set_align(lv_arc_2, LV_ALIGN_CENTER);
        lv_obj_set_clickable(lv_arc_2, false);
        lv_arc_set_bg_start_angle(lv_arc_2, 62);
        lv_arc_set_bg_end_angle(lv_arc_2, 118);
        lv_obj_add_style(lv_arc_2, &style_box, 0);
        lv_obj_add_style(lv_arc_2, &style_range_arc, 0);
        lv_obj_add_style(lv_arc_2, &style_hidden_part, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_2, &style_hidden_part, LV_PART_KNOB);

        the_root = box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void speedometer_lv_label_0_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    char eval_buf_1[LV_XML_EVAL_STRING_BUF_SIZE];
    lv_snprintf(eval_buf_1, sizeof(eval_buf_1), "%d", (int)(lv_subject_get_int(subject_speed)));
    lv_label_set_text(obj, eval_buf_1);
}

static void speedometer_lv_label_2_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    char eval_buf_1[LV_XML_EVAL_STRING_BUF_SIZE];
    lv_snprintf(eval_buf_1, sizeof(eval_buf_1), "%d%s", (int)(lv_subject_get_int(subject_range)), " mi");
    lv_label_set_text(obj, eval_buf_1);
}

