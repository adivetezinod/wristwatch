#include <board_hal.h>

#include <TFT_eSPI.h>
#include <lvgl.h>

static TFT_eSPI tft = TFT_eSPI(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION);

void board_draw(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void board_setup()
{
    tft.begin();
    tft.setRotation(3);
}

void board_loop()
{
    
}