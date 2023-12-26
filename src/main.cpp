#include <Arduino.h>
#include <lvgl.h>
#include <board_hal.h>

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[HORIZONTAL_RESOLUTION * VERTICAL_RESOLUTION / 10];
static lv_color_t buf2[HORIZONTAL_RESOLUTION * VERTICAL_RESOLUTION / 10];

void setup()
{
  Serial.begin(115200);
  lv_init();
  board_setup();

  static lv_disp_drv_t disp_drv;
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, HORIZONTAL_RESOLUTION * VERTICAL_RESOLUTION / 10);
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = HORIZONTAL_RESOLUTION;
  disp_drv.ver_res = VERTICAL_RESOLUTION;
  disp_drv.flush_cb = board_draw;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /* Create simple label */
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Hello World");
  lv_obj_align(label, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
}

void loop()
{
  lv_timer_handler();
  board_loop();
}