/**
 * @file mode_row_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "mode_row_gen.h"
#include "../../car_ac_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* <prop bindable="true">: a create() parameter AND an owned subject */
    lv_subject_t * active;
} mode_row_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static uint32_t mode_row_get_instance_event;
static void mode_row_get_instance_cb(lv_event_t * e);
static mode_row_t * mode_row_get_instance(lv_obj_t * obj);
static void mode_row_destroy_instance(mode_row_t * inst);
static void mode_row_delete_cb(lv_event_t * e);
static void mode_row_lv_obj_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * mode_row_create(lv_obj_t * parent, const void * icon, const char * text, bool active)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_active;
    static lv_style_t style_main_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        static const lv_style_prop_t style_main_trans_props[] = {LV_STYLE_BG_COLOR, LV_STYLE_BG_GRAD_COLOR, 0};
        static lv_style_transition_dsc_t style_main_trans_dsc;


        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_active);
        lv_style_init(&style_main_pressed);

        lv_style_set_bg_opa(&style_main, 255);
        lv_style_set_bg_color(&style_main, COLOR_BG);
        lv_style_set_bg_grad_color(&style_main, COLOR_BG);
        lv_style_set_bg_grad_dir(&style_main, LV_GRAD_DIR_HOR);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_pad_ver(&style_main, 0);
        lv_style_set_pad_hor(&style_main, 30);
        lv_style_set_pad_column(&style_main, 28);
        lv_style_transition_dsc_init(&style_main_trans_dsc, style_main_trans_props, lv_anim_path_linear, 250, 0, NULL);
        lv_style_set_transition(&style_main, &style_main_trans_dsc);
        lv_style_set_bg_color(&style_active, COLOR_BLUE);
        lv_style_set_bg_grad_color(&style_active, COLOR_RED);
        lv_style_set_bg_color(&style_main_pressed, lv_color_hex(0x15161E));
        lv_style_set_bg_grad_color(&style_main_pressed, lv_color_hex(0x15161E));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    if(mode_row_get_instance_event == 0) mode_row_get_instance_event = lv_event_register_id();
    mode_row_t * inst = lv_malloc(sizeof(mode_row_t));
    lv_memzero(inst, sizeof(mode_row_t));
    inst->active = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->active, active);

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "mode_row_#");
        lv_obj_add_event_cb(lv_obj_0, mode_row_get_instance_cb, mode_row_get_instance_event, inst);
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, 74);
        lv_obj_set_scrollable(lv_obj_0, false);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_subject_add_observer_obj(inst->active, mode_row_lv_obj_0_checked_binding_cb, lv_obj_0, inst);

        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_add_style(lv_obj_0, &style_main_pressed, LV_STATE_PRESSED);
        lv_obj_add_style(lv_obj_0, &style_active, LV_STATE_CHECKED);
        lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
        lv_image_set_src(lv_image_0, icon);
        lv_obj_add_style(lv_image_0, &style_icon, 0);

        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, text);
        lv_obj_add_style(lv_label_0, &style_text_body, 0);

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, mode_row_delete_cb, LV_EVENT_DELETE, inst);
    else mode_row_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

void mode_row_set_active(lv_obj_t * obj, int32_t active)
{
    mode_row_t * inst = mode_row_get_instance(obj);
    if(inst) lv_subject_set_int(inst->active, active);
}

int32_t mode_row_get_active(lv_obj_t * obj)
{
    mode_row_t * inst = mode_row_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->active) : (int32_t)0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void mode_row_get_instance_cb(lv_event_t * e)
{
    void ** out = lv_event_get_param(e);
    *out = lv_event_get_user_data(e);
}

static mode_row_t * mode_row_get_instance(lv_obj_t * obj)
{
    mode_row_t * inst = NULL;
    for(lv_obj_t * o = obj; o && !inst; o = lv_obj_get_parent(o)) {
        lv_obj_send_event(o, mode_row_get_instance_event, &inst);
    }
    return inst;
}

static void mode_row_destroy_instance(mode_row_t * inst)
{
    lv_subject_delete(inst->active);
    lv_free(inst);
}

static void mode_row_delete_cb(lv_event_t * e)
{
    mode_row_destroy_instance(lv_event_get_user_data(e));
}

static void mode_row_lv_obj_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    mode_row_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_checked(obj, lv_subject_get_int(inst->active));
}

