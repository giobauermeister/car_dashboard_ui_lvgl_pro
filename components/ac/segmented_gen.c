/**
 * @file segmented_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "segmented_gen.h"
#include "../../car_ac_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* <prop type="subject">: owned by the caller, stored, never deleted */
    lv_subject_t * subject;
} segmented_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static void segmented_destroy_instance(segmented_t * inst);
static void segmented_delete_cb(lv_event_t * e);
static void segmented_set_subject_cb(lv_event_t * e);
static void segmented_set_subject_cb_2(lv_event_t * e);
static void segmented_set_subject_cb_3(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * segmented_create(lv_obj_t * parent, lv_subject_t * subject, const char * text_0, const char * text_1, const char * text_2)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_track;
    static lv_style_t style_pill;
    static lv_style_t style_pill_1;
    static lv_style_t style_pill_2;
    static lv_style_t style_option_text;

    static bool style_inited = false;

    if (!style_inited) {
        static const lv_style_prop_t style_pill_trans_props[] = {LV_STYLE_TRANSLATE_X, 0};
        static lv_style_transition_dsc_t style_pill_trans_dsc;


        /*Init all styles*/
        lv_style_init(&style_track);
        lv_style_init(&style_pill);
        lv_style_init(&style_pill_1);
        lv_style_init(&style_pill_2);
        lv_style_init(&style_option_text);

        lv_style_set_bg_opa(&style_track, 255);
        lv_style_set_bg_color(&style_track, COLOR_TRACK);
        lv_style_set_radius(&style_track, RADIUS_ROW);
        lv_style_set_radius(&style_pill, RADIUS_ROW);
        lv_style_set_translate_x(&style_pill, 0);
        lv_style_set_shadow_width(&style_pill, 14);
        lv_style_set_shadow_color(&style_pill, COLOR_BG);
        lv_style_set_shadow_opa(&style_pill, (255 * 50 / 100));
        lv_style_transition_dsc_init(&style_pill_trans_dsc, style_pill_trans_props, lv_anim_path_ease_out, 250, 0, NULL);
        lv_style_set_transition(&style_pill, &style_pill_trans_dsc);
        lv_style_set_translate_x(&style_pill_1, SEG_W);
        lv_style_set_translate_x(&style_pill_2, SEG_W * 2);
        lv_style_set_text_font(&style_option_text, font_body);
        lv_style_set_text_color(&style_option_text, lv_color_hex(0xD6D6DE));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    segmented_t * inst = lv_malloc(sizeof(segmented_t));
    lv_memzero(inst, sizeof(segmented_t));
    inst->subject = subject;

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * box_0 = box_create(parent);
        lv_obj_set_name_static(box_0, "segmented_#");
        lv_obj_set_width(box_0, SEG_W * 3);
        lv_obj_set_height(box_0, SEG_H);

        lv_obj_add_style(box_0, &style_track, 0);
        lv_obj_t * box_1 = box_create(box_0);
        lv_obj_set_width(box_1, SEG_W);
        lv_obj_set_height(box_1, lv_pct(100));
        lv_obj_set_clickable(box_1, false);
        lv_obj_add_style(box_1, &style_gradient, 0);
        lv_obj_add_style(box_1, &style_pill, 0);
        lv_obj_add_style(box_1, &style_pill_1, LV_STATE_USER_1);
        lv_obj_add_style(box_1, &style_pill_2, LV_STATE_USER_2);
        lv_obj_bind_state_if_eq(box_1, subject, LV_STATE_USER_1, 1);
        lv_obj_bind_state_if_eq(box_1, subject, LV_STATE_USER_2, 2);

        lv_obj_t * box_2 = box_create(box_0);
        lv_obj_set_width(box_2, SEG_W);
        lv_obj_set_height(box_2, lv_pct(100));
        lv_obj_set_clickable(box_2, true);
        lv_obj_add_event_cb(box_2, segmented_set_subject_cb, LV_EVENT_CLICKED, inst);
        lv_obj_t * lv_label_0 = lv_label_create(box_2);
        lv_label_set_text(lv_label_0, text_0);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_label_0, &style_option_text, 0);

        lv_obj_t * box_3 = box_create(box_0);
        lv_obj_set_width(box_3, SEG_W);
        lv_obj_set_height(box_3, lv_pct(100));
        lv_obj_set_x(box_3, SEG_W);
        lv_obj_set_clickable(box_3, true);
        lv_obj_add_event_cb(box_3, segmented_set_subject_cb_2, LV_EVENT_CLICKED, inst);
        lv_obj_t * lv_label_1 = lv_label_create(box_3);
        lv_label_set_text(lv_label_1, text_1);
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_label_1, &style_option_text, 0);

        lv_obj_t * box_4 = box_create(box_0);
        lv_obj_set_width(box_4, SEG_W);
        lv_obj_set_height(box_4, lv_pct(100));
        lv_obj_set_x(box_4, SEG_W * 2);
        lv_obj_set_clickable(box_4, true);
        lv_obj_add_event_cb(box_4, segmented_set_subject_cb_3, LV_EVENT_CLICKED, inst);
        lv_obj_t * lv_label_2 = lv_label_create(box_4);
        lv_label_set_text(lv_label_2, text_2);
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_label_2, &style_option_text, 0);

        the_root = box_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, segmented_delete_cb, LV_EVENT_DELETE, inst);
    else segmented_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void segmented_destroy_instance(segmented_t * inst)
{
    lv_free(inst);
}

static void segmented_delete_cb(lv_event_t * e)
{
    segmented_destroy_instance(lv_event_get_user_data(e));
}

static void segmented_set_subject_cb(lv_event_t * e)
{
    segmented_t * inst = lv_event_get_user_data(e);
    lv_subject_set_int(inst->subject, 0);
}

static void segmented_set_subject_cb_2(lv_event_t * e)
{
    segmented_t * inst = lv_event_get_user_data(e);
    lv_subject_set_int(inst->subject, 1);
}

static void segmented_set_subject_cb_3(lv_event_t * e)
{
    segmented_t * inst = lv_event_get_user_data(e);
    lv_subject_set_int(inst->subject, 2);
}

