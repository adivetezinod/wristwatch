#ifndef BOARD_HAL_H
#define BOARD_HAL_H
#include <board_config.h>

#include <lvgl.h>

void board_setup();
void board_draw(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void board_loop();

#endif //BOARD_HAL_H