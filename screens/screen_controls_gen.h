/**
 * @file screen_controls_gen.h
 */

#ifndef LVGL_PRO_SCREEN_CONTROLS_GEN_H
#define LVGL_PRO_SCREEN_CONTROLS_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    SCREEN_CONTROLS_TIMELINE_TIMELINE_INTRO = 0,
    _SCREEN_CONTROLS_TIMELINE_CNT = 1
}screen_controls_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * screen_controls_create(void);

/**
 * Get a timeline of a screen_controls
 * @param obj          pointer to a screen_controls component
 * @param timeline_id  ID of the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * screen_controls_get_timeline(lv_obj_t * obj, screen_controls_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_SCREEN_CONTROLS_GEN_H*/