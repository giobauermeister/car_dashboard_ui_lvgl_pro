/**
 * @file car_ac_ui.h
 */

#ifndef LVGL_PRO_CAR_AC_UI_H
#define LVGL_PRO_CAR_AC_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      DEFINES
 *********************/

/* Target(s) select at startup: one or more CAR_AC_UI_TARGET_* values OR-ed together. */
#ifndef CAR_AC_UI_COMPILE_TARGET
#define CAR_AC_UI_COMPILE_TARGET CAR_AC_UI_TARGET_ALL
#endif

/*********************
 *      INCLUDES
 *********************/

#include "car_ac_ui_gen.h"

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void car_ac_ui_init(const char * asset_path);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_CAR_AC_UI_H*/