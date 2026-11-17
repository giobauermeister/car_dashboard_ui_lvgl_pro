/**
 * @file car_ac_ui.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "car_ac_ui.h"
#include "custom/car_ac_logic.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void car_ac_ui_init(const char * asset_path)
{
    LV_LOG("Initializing custom C code using LVGL v%d.%d.%d", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH);

    car_ac_ui_init_gen(asset_path);

    /* After the generated init, which creates the subjects the logic observes */
    car_ac_logic_init();

    /* The Editor's preview creates and loads the screens itself */
#if !defined(LV_EDITOR_PREVIEW)
    lv_screen_load(screen_controls);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/