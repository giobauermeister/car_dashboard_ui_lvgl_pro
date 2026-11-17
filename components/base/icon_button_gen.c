/**
 * @file icon_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_button_gen.h"
#include "../../car_ac_ui.h"

/*********************
 *      DEFINES
 *********************/

#define ICON_SCALE_IDLE (200)
#define ICON_SCALE_PRESSED (228)
#define ICON_SCALE_ACTIVE (256)


/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* <prop bindable="true">: a create() parameter AND an owned subject */
    lv_subject_t * active;
} icon_button_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static uint32_t icon_button_get_instance_event;
static void icon_button_get_instance_cb(lv_event_t * e);
static icon_button_t * icon_button_get_instance(lv_obj_t * obj);
static void icon_button_destroy_instance(icon_button_t * inst);
static void icon_button_delete_cb(lv_event_t * e);
static void icon_button_lv_obj_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void icon_button_box_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void icon_button_lv_image_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * icon_button_create(lv_obj_t * parent, const void * icon, bool active)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_ring;
    static lv_style_t style_ring_active;
    static lv_style_t style_fill;
    static lv_style_t style_fill_active;
    static lv_style_t style_glyph;
    static lv_style_t style_glyph_pressed;
    static lv_style_t style_glyph_active;

    static bool style_inited = false;

    if (!style_inited) {
        static const lv_style_prop_t style_ring_trans_props[] = {LV_STYLE_BG_OPA, 0};
        static lv_style_transition_dsc_t style_ring_trans_dsc;
        static const lv_style_prop_t style_fill_trans_props[] = {LV_STYLE_BG_OPA, 0};
        static lv_style_transition_dsc_t style_fill_trans_dsc;
        static const lv_style_prop_t style_glyph_trans_props[] = {LV_STYLE_TRANSFORM_SCALE_X, LV_STYLE_TRANSFORM_SCALE_Y, LV_STYLE_IMAGE_RECOLOR, 0};
        static lv_style_transition_dsc_t style_glyph_trans_dsc;


        /*Init all styles*/
        lv_style_init(&style_ring);
        lv_style_init(&style_ring_active);
        lv_style_init(&style_fill);
        lv_style_init(&style_fill_active);
        lv_style_init(&style_glyph);
        lv_style_init(&style_glyph_pressed);
        lv_style_init(&style_glyph_active);

        lv_style_set_radius(&style_ring, 1000);
        lv_style_set_bg_opa(&style_ring, 0);
        lv_style_set_bg_color(&style_ring, lv_color_hex(0x5452B8));
        lv_style_set_bg_grad_color(&style_ring, lv_color_hex(0x9C2C5E));
        lv_style_set_bg_grad_dir(&style_ring, LV_GRAD_DIR_VER);
        lv_style_set_border_width(&style_ring, 0);
        lv_style_set_pad_all(&style_ring, 0);
        lv_style_transition_dsc_init(&style_ring_trans_dsc, style_ring_trans_props, lv_anim_path_linear, 220, 0, NULL);
        lv_style_set_transition(&style_ring, &style_ring_trans_dsc);
        lv_style_set_bg_opa(&style_ring_active, 255);
        lv_style_set_radius(&style_fill, 1000);
        lv_style_set_bg_opa(&style_fill, 0);
        lv_style_set_bg_color(&style_fill, lv_color_hex(0x0E2250));
        lv_style_set_bg_grad_color(&style_fill, lv_color_hex(0x501A40));
        lv_style_set_bg_grad_dir(&style_fill, LV_GRAD_DIR_VER);
        lv_style_transition_dsc_init(&style_fill_trans_dsc, style_fill_trans_props, lv_anim_path_linear, 220, 0, NULL);
        lv_style_set_transition(&style_fill, &style_fill_trans_dsc);
        lv_style_set_bg_opa(&style_fill_active, 255);
        lv_style_set_image_recolor(&style_glyph, lv_color_hex(0xD2D2D8));
        lv_style_set_image_recolor_opa(&style_glyph, 255);
        lv_style_set_transform_scale_x(&style_glyph, ICON_SCALE_IDLE);
        lv_style_set_transform_scale_y(&style_glyph, ICON_SCALE_IDLE);
        lv_style_set_transform_pivot_x(&style_glyph, lv_pct(50));
        lv_style_set_transform_pivot_y(&style_glyph, lv_pct(50));
        lv_style_transition_dsc_init(&style_glyph_trans_dsc, style_glyph_trans_props, lv_anim_path_ease_out, 220, 0, NULL);
        lv_style_set_transition(&style_glyph, &style_glyph_trans_dsc);
        lv_style_set_transform_scale_x(&style_glyph_pressed, ICON_SCALE_PRESSED);
        lv_style_set_transform_scale_y(&style_glyph_pressed, ICON_SCALE_PRESSED);
        lv_style_set_image_recolor(&style_glyph_active, lv_color_hex(0xB9BEF2));
        lv_style_set_transform_scale_x(&style_glyph_active, ICON_SCALE_ACTIVE);
        lv_style_set_transform_scale_y(&style_glyph_active, ICON_SCALE_ACTIVE);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    if(icon_button_get_instance_event == 0) icon_button_get_instance_event = lv_event_register_id();
    icon_button_t * inst = lv_malloc(sizeof(icon_button_t));
    lv_memzero(inst, sizeof(icon_button_t));
    inst->active = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->active, active);

    #if CAR_AC_UI_CHECK_COMPILE_TARGET(CAR_AC_UI_TARGET_ALL)
    if (car_ac_ui_check_target(CAR_AC_UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "icon_button_#");
        lv_obj_add_event_cb(lv_obj_0, icon_button_get_instance_cb, icon_button_get_instance_event, inst);
        lv_obj_set_width(lv_obj_0, 92);
        lv_obj_set_height(lv_obj_0, 92);
        lv_obj_set_scrollable(lv_obj_0, false);
        lv_obj_set_state_trickle(lv_obj_0, true);
        lv_subject_add_observer_obj(inst->active, icon_button_lv_obj_0_checked_binding_cb, lv_obj_0, inst);

        lv_obj_add_style(lv_obj_0, &style_ring, 0);
        lv_obj_add_style(lv_obj_0, &style_ring_active, LV_STATE_CHECKED);
        lv_obj_t * box_0 = box_create(lv_obj_0);
        lv_obj_set_width(box_0, 88);
        lv_obj_set_height(box_0, 88);
        lv_obj_set_align(box_0, LV_ALIGN_CENTER);
        lv_obj_set_clickable(box_0, false);
        lv_subject_add_observer_obj(inst->active, icon_button_box_0_checked_binding_cb, box_0, inst);
        lv_obj_add_style(box_0, &style_fill, 0);
        lv_obj_add_style(box_0, &style_fill_active, LV_STATE_CHECKED);

        lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
        lv_image_set_src(lv_image_0, icon);
        lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
        lv_subject_add_observer_obj(inst->active, icon_button_lv_image_0_checked_binding_cb, lv_image_0, inst);
        lv_obj_add_style(lv_image_0, &style_glyph, 0);
        lv_obj_add_style(lv_image_0, &style_glyph_active, LV_STATE_CHECKED);
        lv_obj_add_style(lv_image_0, &style_glyph_pressed, LV_STATE_PRESSED);

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, icon_button_delete_cb, LV_EVENT_DELETE, inst);
    else icon_button_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

void icon_button_set_active(lv_obj_t * obj, int32_t active)
{
    icon_button_t * inst = icon_button_get_instance(obj);
    if(inst) lv_subject_set_int(inst->active, active);
}

int32_t icon_button_get_active(lv_obj_t * obj)
{
    icon_button_t * inst = icon_button_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->active) : (int32_t)0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void icon_button_get_instance_cb(lv_event_t * e)
{
    void ** out = lv_event_get_param(e);
    *out = lv_event_get_user_data(e);
}

static icon_button_t * icon_button_get_instance(lv_obj_t * obj)
{
    icon_button_t * inst = NULL;
    for(lv_obj_t * o = obj; o && !inst; o = lv_obj_get_parent(o)) {
        lv_obj_send_event(o, icon_button_get_instance_event, &inst);
    }
    return inst;
}

static void icon_button_destroy_instance(icon_button_t * inst)
{
    lv_subject_delete(inst->active);
    lv_free(inst);
}

static void icon_button_delete_cb(lv_event_t * e)
{
    icon_button_destroy_instance(lv_event_get_user_data(e));
}

static void icon_button_lv_obj_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    icon_button_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_checked(obj, lv_subject_get_int(inst->active));
}

static void icon_button_box_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    icon_button_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_checked(obj, lv_subject_get_int(inst->active));
}

static void icon_button_lv_image_0_checked_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    icon_button_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_checked(obj, lv_subject_get_int(inst->active));
}

